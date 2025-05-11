#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int* arr;
};

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, int val){
    if (isFull(ptr)){
        printf("Stack Overflow!\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack* ptr){
    if (isEmpty(ptr)){
        printf("Stack Underflow!\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void peek(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Empty Array!\n");
    }
    else{
        printf("%d \n", ptr->arr[ptr->top]);
    }
}

void display(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Empty Array!\n");
    }
    else{
        for(int i=ptr->top; i>=0; i--){
            printf("%d \t", ptr->arr[i]);
        }
        printf("\n");
    }
}
 
void main(){
    struct stack * ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->top = -1;
    ptr->size = 10;
    ptr->arr = (int*)malloc((ptr->size) * sizeof(int));

    push(ptr, 10);
    push(ptr, 20);
    push(ptr, 30);
    display(ptr);

    pop(ptr);
    display(ptr);

    peek(ptr);
}