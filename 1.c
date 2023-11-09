#include <stdio.h>

#define N 100
int arr[N];

void printData(int arr[]){
    int i=0;
    while(arr[i] != '\0'){
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void addElement(int arr[], int data, int pos){
    int i=0;
    while(i+1 != pos){
        i++;
    }
    arr[i] = data;
    printf("\n");

}

void deleteElement(int arr[], int pos){
    int i=0;
    while(i+1 != pos){
        i++;
    }
    while(arr[i] != '\0'){
        arr[i] = arr[i+1];
        i++;
    }
    printf("\n");
}

void linearSearch(int arr[], int key){
    int i=0;
    while(arr[i] != key){
        i++;
    }
    printf("Given element is at position %d\n", i+1);
    printf("\n");

}

int main(){
    int choice;
    int size;
    int data; 
    int pos;
    int key;

    while (choice != 0){   

        printf("Enter choice: \n 0-exit \n 1-input array \n 2-print array \n 3-add element \n 4-delete element \n 5-search element \n");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter size of array: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("Enter element number %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            break;
        case 2:
            printData(arr);
            break;
        case 3: 
            printf("Enter element to add: ");
            scanf("%d", &data);
            printf("Enter position to add at: ");
            scanf("%d", &pos);
            
            addElement(arr, data, pos);
            break;
        case 4: 
            printf("Enter position to delete from: ");
            scanf("%d", &pos);
            
            deleteElement(arr, pos);
            break;
        case 5: 
            printf("Enter element to find: ");
            scanf("%d", &key);

            linearSearch(arr, key);
            break;
        default:
            break;
        }
    }
}