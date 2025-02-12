#include <stdio.h>

void merge(int A[], int mid, int lb, int ub){
    int i, j, k;
    
    // Creating two array 
    int n1 = (mid-lb)+1;
    int n2 = ub-mid;
    int Left[n1], Right[n2];

    // Adding elements of A into Left and Right
    for(i=0; i<n1; i++){
        Left[i] = A[i+lb];
    }
    for(j=0; j<n2; j++){
        Right[j] = A[j+mid+1];
    }

    // Making A a sorted array
    i=0, j=0, k=lb;
    while(i<n1 && j<n2){
        if(Left[i] < Right[j]){
            A[k++] = Left[i++];
        }
        else{
            A[k++] = Right[j++];
        }
    }
    while(i<n1){
        A[k++] = Left[i++];
    }
    while(j<n2){
        A[k++] = Right[j++];
    }
}

void Merge_sort(int A[], int lb, int ub){
    if(lb < ub){
        int mid = (lb+ub)/2;
        Merge_sort(A, lb, mid);
        Merge_sort(A, mid+1, ub);
        merge(A, mid, lb, ub);
    }
}
 
void main(){
    printf("<---------- Mohit AIML-2 ----------> \n");
    int arr[10] = {20, 45, 1, 23, 54, 24, 21, 19, 42, 27};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int lb = 0, ub = n-1;
    Merge_sort(arr, lb, ub);

    // Printing the Sorted Array
    for(int i=0; i<n; i++){
        printf("%d \t", arr[i]);
    }
}