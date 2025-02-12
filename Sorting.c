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
    int arr[9] = {26,59,97,17,77,31,44,55,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // selection_sorting(arr, n);

    insertion_sorting(arr, n);

    for(int i=0; i<n; i++){
        printf("%d \t", arr[i]);
    }
}