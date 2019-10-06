#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL(CELL_NAME) CELL_NAME = cell_alloc()

/* What we need:
 * file scanner -> write to array
 * board and cell init
 * checker functions: originp
 * wave tracer
 * multi-thread?
 */

typedef struct _cell{
  int distance;
  int origin[2];
  int links[3];
}CELL;

CELL ** board_alloc(int dimx, int dimy){
  CELL ** board = malloc(sizeof(CELL *) * dimx); // row
  for(int i = 0; i < dimx; i++){
    board[i] = malloc(sizeof(CELL) * dimy);
  }
  return board;
}



void traverse(CELL ** board,int giveupi){

}


int main(void){
  FILE maze = fopen("./res/d
  
  return 0;
}
  //int main(int argc, char * argv[]){


  //}
