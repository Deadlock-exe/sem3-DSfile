#include <stdio.h>
#include <stdlib.h>

struct sparsematrix
{
    int row;
    int column;
    int value;
    struct sparsematrix *prev, *next;
};
typedef struct sparsematrix sparse_element;

void display_array(int **, int, int);
int **read_array(int **, int, int);

sparse_element *create_sparse_element(void)
{
    sparse_element *newnode = (sparse_element *)malloc(sizeof(sparse_element));
    newnode->prev = newnode->next = 0;
    return newnode;
}

sparse_element *conv_2D_to_sparse(int **arrayptr, sparse_element *head, int row, int column)
{
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
    return head;
}


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
    
}

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

int main()
{
    int **a = 0;
    int row = 5, column = 4;
    a = read_array(a, row, column);
    display_array(a, row, column);

    sparse_element *head = 0;
    head = conv_2D_to_sparse(a, head, row, column);
    //printf("%d\n",head);
    display_sparse_matrix(head);
}