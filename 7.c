# include <stdio.h>
# include <stdlib.h>

void countSort(int a[],int size){
    int k = 0;
    for(int i = 0; i < size;i++){
        if(a[i]>a[k]){
            k = i;
        }
    }
    k = a[k];
    int *count ;
    count = (int*)malloc((k+1)*sizeof(int));

    for(int i = 0; i <=k ;i++){
        count[i] =0;
    }
    for(int i = 0; i <size ;i++){
        count[a[i]] =count[a[i]]+1;
    }

    for(int i = 1 ; i<=k;i++){
        count[i] = count[i-1]+count[i];
    }
    
    int * b;
    b=(int*)malloc((size)*sizeof(int));
    for(int i = size; i>0; i--){
        b[--count[a[i-1]]] = a[i-1];
    }

    for(int i = 0; i<size ;i++){
        a[i] = b[i];
    }
    free(b);
}


int main(){
    int arr[17] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    countSort(arr,17);
    for(int i = 0 ; i<17;i++){
        printf("%d ",arr[i]);
    }
}