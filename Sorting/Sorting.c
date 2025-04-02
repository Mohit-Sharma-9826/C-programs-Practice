#include <stdio.h>

void selection_sorting(int arr[], int n){

    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertion_sorting(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
void main(){
    printf("<---------- Mohit AIML-2 ---------->\n");
    int arr[9] = {26,59,97,17,77,31,44,55,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int arr2[9] = {42,17,89,63,24,56,71,38,92};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    selection_sorting(arr, n);

    printf("Selection sorting: ");
    for(int i=0; i<n; i++){
        printf("%d \t", arr[i]);
    }
    printf("\n");


    insertion_sorting(arr2, n2);
    
    printf("Insertion sorting: ");
    for(int i=0; i<n2; i++){
        printf("%d \t", arr2[i]);
    }
}