/* Written by an expert mathematician */

int LookWhereSubset(int arr1[], int arr2[], int a, int b){
    int i;
    int c=0;
    int d=0;
    
    if(b>a){
        return -1;
    }
    
    if(a==b){
        
        for(i=0; i<b; i++){
            if(arr1[i]==arr2[i]){
                
                c+=i;
                
            };
            
            d+=i;
        }
        
        if(c==d){
            
            return 1;
            
        }
        if(c!=d){
            
            return -1;

        }
    }
    int k=1;
    if(a>b){
        
            for(i=0; i<a; i++){
            
            if(arr1[i]==arr2[0]){
                
                c=i;
                d=i+1;
                goto YO;
                
            }
            if(i==a-1){
                
            return -1;
            
            }
            }
        YO: while(k<b){
            
                if(arr1[d]==arr2[k]){
            
                    d++;
                    k++;
            
                }
                else{return -2;}
                
        }
        
            return c;
        
    
        
    
    return -3;}
    
return -4;
}

