#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO:
 * determine maze size by scanning
 * multi-thread with openmp
 */

typedef struct _cell{
  char type;
  //char color;
  //int distance;
  int origin[2];
}CELL;

CELL ** board_alloc(int dimx, int dimy){
  CELL ** board = malloc(sizeof(CELL *) * dimx); // row
  for(int i = 0; i < dimx; i++){
    board[i] = malloc(sizeof(CELL) * dimy);
  }
  return board;
}

void cell_init(FILE * mfile,CELL ** board,int * start, int dimx, int dimy){ // change to return an array of start coords
  char scan;
  for(int i=0; i<dimx; i++){
    for(int j=0; j<dimy; j++){
      fscanf(mfile, "%1c", &scan);
      board[i][j].type = scan;
      board[i][j].origin[0] = -1; //TODO check null pointers instead
      board[i][j].origin[1] = -1;
      if(scan=='S'){
        start[0] = i;
        start[1] = j;
        board[i][j].origin[0] = i;
        board[i][j].origin[1] = j;
      }
    }
  }
}

int * traverse(CELL ** board,           /* maze as an array */
               int dimx, int dimy,      /* array dimensions */
               int * s,                 /* a "pivot" where to check neigbors */
               int * origin,            /* needed for recursion */
               int giveupi){            /* give up after a certain amount of iterations */
  int sx = s[0]-1; // variables needed to make the for loop work, basically a pivot shifted top left
  int sy = s[1]-1;
  int new_s[2];    // a new pivot to be passed into the next iteration
  int x,y;         // used to access neigboring cells
  static int exit[2] = {-1, -1}; // default return in case no finish is found
  if(giveupi<5000){
    //board[s[0]][s[1]].distance = giveupi; //might be useful for a multi-threaded setup w optimal path
    for(int j=0; j<4; j++){
      x = sx + (2*j+1) % 3;
      y = sy + (2*j+1) / 3; // integer division is important here

      if(!(                                       // mind the inversion! below are the fail conditions
           x < 0 || y < 0 || x > dimx || y > dimy // out of bounds check
           || (x == origin[0] && y == origin[1])  // infinite recursion prevention
           || board[x][y].origin[0] != -1)){       // checks if the cell is initialized
        switch(board[x][y].type){
        case 'F': // mission accomplished, maze exit found
          exit[0]=x;
          exit[1]=y;
          board[x][y].origin[0] = s[0];
          board[x][y].origin[1] = s[1];
          return exit;
        case '0': // new branch found
          board[x][y].origin[0] = s[0];
          board[x][y].origin[1] = s[1];
          new_s[0] = x;
          new_s[1] = y;
          int * p = traverse(board, dimx, dimy, new_s, s, giveupi+1);
          exit[0] = p[0];
          exit[1] = p[1];
          break;
        default: // don't do anything if any other symbol is found
          break;
        }
      }
    }
  }
  return exit; // in case the maze is unsolvable
}

void print_brd(CELL ** board, int dimx, int dimy){
  for(int i=0; i<dimx; i++){
    for(int j=0; j<dimy; j++){
      printf("%c",board[i][j].type);
      if(j==dimy-1){printf("\n");}
    }
  }
}

void paint(CELL ** board, int dimx, int dimy, int * finish){
  print_brd(board,dimx,dimy);
  int * n_f;
  if(board[finish[0]][finish[1]].type == 'S'){
    board[finish[0]][finish[1]].type = '!';
    print_brd(board,dimx,dimy);
    return;
  }else{
    board[finish[0]][finish[1]].type = '!';
    n_f = board[finish[0]][finish[1]].origin;
    paint(board,dimx,dimy,n_f);
  }
}

void write_maze(CELL ** board, int dimx, int dimy, FILE * w){
  for(int i=0; i<dimx; i++){
    for(int j=0; j<dimy; j++){
      fprintf(w, "%c",board[i][j].type);
    }
    fprintf(w,"\n");
  }
}

int main(void){
  FILE * maze = fopen("./res/maze.txt", "r");
  FILE * smaz = fopen("./res/solve.txt", "w");
  int bx = 100; // board's x and y dimensions
  int by = 100;
  int start[2]; // start coordinates
  CELL ** board = board_alloc(bx,by);
  cell_init(maze,board,start,bx,by); // defines starting coords
  print_brd(board,bx,by);
  printf("Detected S at array addr: %i,%i\n",start[0],start[1]);
  int * finish = traverse(board,bx,by,start,start,0); // The origin of start is start itself
  printf("Detected F at array addr: %i,%i\n",finish[0],finish[1]);
  paint(board,bx,by,finish);
  write_maze(board,bx,by,smaz);
  free(board);
  return 0;
}
