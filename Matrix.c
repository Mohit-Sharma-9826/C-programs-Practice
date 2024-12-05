#include <stdio.h>

void multiply(int a[3][3], int b[3][3], int result[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            result[i][j] = 0;
            for(int k=0; k<3; k++){
                result[i][j] += a[i][k] * b[k][j];
            }
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }

}

void transpose(int result[3][3]){
      for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d  ", result[j][i]);
        }
        printf("\n");
    }
}

int main(){
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int arr2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int result[3][3];

    multiply(arr, arr2, result);  
    printf("\n");
    transpose(result);                  
    
    return 0;
}