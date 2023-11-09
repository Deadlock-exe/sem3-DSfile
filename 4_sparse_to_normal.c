/* Read a matrix in sparse form and print it in normal form. */
#include <stdio.h>
#include <stdlib.h>

struct sparse_matrix
{
    int row, col, value;
};
typedef struct sparse_matrix sparsematrix;

// read sparse matrix
void read_sparsematrix(sparsematrix * ptr, int *psize)
{
    int i = 0;
    int col_size=1,row_size=1;
    while (i < *psize)
    {
        int row ,col,value;
        printf("enter row column value : ");
        scanf(" %d %d %d",&row,&col,&value);
        if(row_size<=row){
            row_size = row+1;
        }
        if(col_size<=col){
            col_size = col + 1;
        }
        ptr[i+1].row = row;
        ptr[i+1].col = col;
        ptr[i+1].value = value;
        i++;
    }
    ptr[0].row=row_size;
    ptr[0].col=col_size;
    ptr[0].value=i;
    ++*psize;
}

void display_sparsematrix(sparsematrix * ptr ,int size){
    for(int i = 0;i<size;i++){
        printf("%4d %4d %4d\n",ptr[i].row,ptr[i].col,ptr[i].value);
    }
}

int** conv_sparse_to_normal(sparsematrix * ptr,int** arrptr,int * psize){
    int k = 1;
    arrptr = (int**)malloc(ptr[0].row * sizeof(int*));

    for(int i = 0; i<ptr[0].row;i++){
        arrptr[i]= (int*)malloc(ptr[0].col*sizeof(int));
    }

    for(int i = 0; i<ptr[0].row;i++){
        for(int j = 0; j <ptr[0].col;j++){
            if(ptr[k].row==i&&ptr[k].col==j){
                arrptr[i][j]=ptr[k].value;
                ++k;
            }
            else{
                arrptr[i][j]=0;
            }
        }
    }
    return arrptr;
}

void display_array(int **array_ptr, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        printf("[ ");
        for (int j = 0; j < column; j++)
        {
            printf("%3d ", *(*(array_ptr + i) + j));
        }
        printf("]\n");
    }
}

int main(){
    sparsematrix array[10];
    int size =3;
    int*psize=&size;
    int ** arrptr =0;

    read_sparsematrix(array,psize);
    display_sparsematrix(array,size);
    arrptr= conv_sparse_to_normal(array,arrptr,psize);
    display_array(arrptr,array[0].row,array[0].col);

}
