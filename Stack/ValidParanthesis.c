#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    char* arr;
};

int flag = 0;

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, char val){
    if(ptr->top == ptr->size-1){
        printf("overflow\n");
    }
    else{
        (ptr->top)++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack* ptr){
    if(ptr->top == -1){
        printf("underflow\n");
        flag = 1;
    }
    else{
        char val = ptr->arr[ptr->top];
        (ptr->top)--;
    }
}

void display(struct stack* ptr){
    if(ptr->top == -1){
        printf("Stack is Empty\n");
    }
    else{
        int n = sizeof(ptr->arr)/sizeof(ptr->arr[0]);
        
        printf("Stack:  ");
        for(int i=0; i<n; i++){
            printf("%c \t", ptr->arr[i]);
        }
        printf("\n");
    }
}

void matching(struct stack* ptr, char str[]){
    if(isEmpty(ptr) && flag==0){
        printf("The expression has valid %s paranthesis.\n", str);
    }
    else{
        printf("The expression has invalid %s paranthesis.\n", str);
    }
}

void main(){
    char a[] = "{(5+2)*3-6(4+2)}+[5*{6+(2/10)}]";
    int n = sizeof(a)/sizeof(a[0]);

    char str[3];
    printf("Enter the paranthesis you want to check. (), {}, []: ");
    scanf("%s", str);

    struct stack* ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->top = -1;
    ptr->size = n;
    ptr->arr = (char*)malloc(sizeof(ptr->size*sizeof(char)));

    for(int i=0; i<n; i++){
        if(a[i] == str[0]){
            push(ptr, a[i]);
        }
        if(a[i] == str[1]){
            pop(ptr);
        }
    }
    display(ptr);
    matching(ptr, str);
}