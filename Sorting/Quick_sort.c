#include<stdio.h>
int partition(int A[],int lb,int ub)
{
    int pivot=A[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(A[start]<pivot)
        {
            start++;
        }
        while(A[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            int temp1=A[start];
            A[start]=A[end];
            A[end]=temp1;
        }
    }
    int temp2=pivot;
    pivot=A[end];
    A[end]=temp2;
    return end;
}
void quicksort(int A[],int lb,int ub)
{    if (lb<ub){

    int mid=partition(A,lb,ub);
    quicksort(A,lb,mid-1);
    quicksort(A,mid+1,ub);
}
}
void main()
{
    printf("<---------- Mohit AIML-2 ----------> \n");
    int A[10]={20,45,1,23,54,24,21,19,42,27};
    int lb=0;
    int ub=9;
    int n=10;
    quicksort(A,lb,ub);
    for(int i=0;i<n;i++)
    printf("%d\t",A[i]);
}