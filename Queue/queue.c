#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int* arr;
};

void enqueue(struct queue* q, int value){
    if(q->rear == q->size-1){
        printf("Overflow");
    }
    else if(q->rear == -1 && q->front == -1){
        q->rear++;
        q->front++;
        q->arr[q->rear] = value;
    }
    else{
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    if(q->rear == -1 && q->front == -1){
        printf("underflow");
    }
    else if(q->rear == q->front){
        q->rear = -1;
        q->front = -1;
    }
    else{
        int val = q->arr[q->front];
        q->front++;
        return val;
    }
}

void display(struct queue* q){
    if(q->rear==-1 && q->front==-1){
        printf("Empty Queue\n");
    }
    else{
        for(int i=q->front; i<=q->rear; i++){
            printf("%d\t", q->arr[i]);
        }
        printf("\n");
    }
}

void main(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 100;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    dequeue(q);
    dequeue(q);
    display(q);
}
