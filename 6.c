
# include <stdio.h>
# include <stdlib.h>

struct sparsematrix
{
    int row;
    int column;
    int value;
    struct sparsematrix *prev, *next;
};
typedef struct sparsematrix sparse_element;

// Declarations for reading 2D array
void display_array(int **, int, int);
int **read_array(int **, int, int);

// creating element  for sparsematrix
sparse_element *create_sparse_element(void)
{
    sparse_element *newnode = (sparse_element *)malloc(sizeof(sparse_element));
    newnode->prev = newnode->next = 0;
    return newnode;
}

// 2D array to sparse matrix
sparse_element *conv_2D_to_sparse(int **arrayptr, sparse_element *head, int row, int column)
{
    //printf("start of conv func\n");
    sparse_element *newelement = 0, *lastelement = 0;
    if (head == 0)
    {
        newelement = create_sparse_element();
        newelement->row = row;
        newelement->column = column;
        newelement->value = 0;
        head= newelement;
        lastelement = newelement;
    }
    if(head!=0)
    {
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (*(*(arrayptr + i) + j) != 0)
                {
                    newelement = create_sparse_element();
                    newelement->row = i;
                    newelement->column = j;
                    newelement->value = *(*(arrayptr + i) + j);
                    newelement->prev = lastelement;
                    lastelement->next=newelement;
                    lastelement = newelement;
                    count++;
                }
            }
        }
        head->value = count;
    }
    //printf("end of conv function\n");
    return head;
}


//display sparse matrix 
void display_sparse_matrix(sparse_element * head){
    printf("sparse matrix form:\n");
    sparse_element * temp = head;
    while(temp!=0){
       
        int row = temp->row;
        int column = temp->column;
        int value = temp->value;
        printf("%4d %4d %4d\n",row,column,value);

        temp = temp->next;
    }
    //printf("end of display sparse\n");
}

// function to read two dimensional array
int **read_array(int **arrayptr, int row, int column)
{
    arrayptr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        *(arrayptr + i) = (int *)malloc(column * sizeof(int));
        for (int j = 0; j < column; j++)
        {
            printf("element [%d][%d] = ", i + 1, j + 1);
            int val;
            scanf(" %d", &val);
            *(*(arrayptr + i) + j) = val;
        }
    }
    return arrayptr;
}

void display_array(int **array_ptr, int row, int column)
{
    printf("normal matrix form : \n");
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


int** conv_sparse_to_normal(sparse_element * ptr,int** arrptr){
    int k = 1;
    arrptr = (int**)malloc(ptr[0].row * sizeof(int*));

    for(int i = 0; i<ptr[0].row;i++){
        arrptr[i]= (int*)malloc(ptr[0].column*sizeof(int));
    }

    for(int i = 0; i<ptr[0].row;i++){
        for(int j = 0; j <ptr[0].column;j++){
            if(ptr[k].row==i&&ptr[k].column==j){
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

sparse_element* add_sparsematrix(sparse_element * sp1, sparse_element* sp2) {
    
    int rowsize_1 = sp1->row;
    int colsize_1 = sp1->column;
    int rowsize_2 = sp2->row;
    int colsize_2 = sp2->column;
    sparse_element* sp3 = 0;
    sp3 = (sparse_element*)malloc(sizeof(sp1[0].value + sp2[0].value + 1));
    
    int i = 1, j = 1, k = 1;
    if ((rowsize_1 != rowsize_2) && (colsize_1 != colsize_2)) {
        printf("Cannot add matrix of different order");
        return NULL;
    }
    else {
        if (sp3 == 0) {
            sparse_element* newnode = create_sparse_element();
            newnode->row = rowsize_1;
            newnode->column = colsize_1;
            newnode->value = 0;
        }
        printf("\nentered in else block of add sparse matrix\n");
        while (i <= rowsize_1 && j <= rowsize_2) {
            printf("inside while loop %d\n", k);
            if (sp1[i].row < sp2[j].row) {
                sp3[k].row = sp1[i].row;
                sp3[k].column = sp1[i].column;
                sp3[k].value = sp1[i].value;
                ++i, ++k;
            }
            else if (sp1[i].row > sp2[j].row) {
                sp3[k].row = sp2[j].row;
                sp3[k].column = sp2[j].column;
                sp3[k].value = sp2[j].value;
                ++j, ++k;
            }
            else {
                if (sp1[i].column < sp2[j].column) {
                    sp3[k].row = sp1[i].row;
                    sp3[k].column = sp1[i].column;
                    sp3[k].value = sp1[i].value;
                    ++i, ++k;
                }
                else if (sp1[i].column > sp2[j].column) {
                    sp3[k].row = sp2[j].row;
                    sp3[k].column = sp2[j].column;
                    sp3[k].value = sp2[j].value;
                    ++j, ++k;
                }
                else {
                    sp3[k].row = sp1[i].row;
                    sp3[k].column = sp1[i].column;
                    sp3[k].value = sp1[i].value + sp2[j].value;
                    ++i, ++k, ++j;
                }
            }
        }
    }
    
    sp3[0].row = rowsize_1;
    sp3[0].column = colsize_2;
    sp3[0].value = k;
    printf("\ndisplay inside add of sparse matrix : \n");
    display_sparse_matrix(sp3);
    return sp3;
}


int main(){
    int **a = 0, **b =0;
    sparse_element * c =0;
    int row = 2,col = 2;
    printf("enter matrix a :\n");
    a=read_array(a,row,col);

    printf("enter matrix b :\n");
    b=read_array(b,row,col);

    printf("matrix A\n");
    display_array(a,row,col);

    printf("matrix A\n");
    display_array(b,row,col);
    
    sparse_element * as1 =0,*as2 =0;
    as1 = conv_2D_to_sparse(a,as1,row,col);
    printf("\nsparse matrix as1 : \n");
    display_sparse_matrix(as1);

    as2 = conv_2D_to_sparse(b,as2,row,col);
    printf("\nsparse matrix as2 : \n");
    display_sparse_matrix(as2);

    c = add_sparsematrix(as1,as2);
    printf("\nbefore displaying sparse matirx\n");
    display_sparse_matrix(c);
    printf("after displaying sparse matirx");

    int**d =0;
    d = conv_sparse_to_normal(c,d);
    display_array(d,row,col);
}