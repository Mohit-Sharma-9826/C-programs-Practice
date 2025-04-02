#include <stdio.h>

void linear(int a[], int size, int key){
    int i, flag=0;
    for(i=0; i<size; i++){
        if(a[i] == key){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        printf("Element %d found at %d index.", key, i);
    }
    else{
        printf("Element not found!");
    }
    printf("\n");

}

int binary(int a[],int lb, int ub, int key){
    if(lb <= ub){
        int mid = (lb+ub)/2;

        if(a[mid] == key){
            printf("Element %d found at %d index.", key, mid);
        }
        else if(a[mid] < key){
            binary(a, mid+1, ub, key);
        }
        else{
            binary(a, lb, mid-1, key);
        }
    }
    else{
        printf("Element not Found!");
    }
}

void main(){
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    linear(arr, size, key);

    int lb = 0, ub = size-1;
    binary(arr, lb, ub, key);
    
}