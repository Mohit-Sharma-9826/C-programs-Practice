#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int* arr;
};
 
void enqueue(struct queue* q, int value){
    if(q->rear == -1 && q->front == -1){
        q->rear++;
        q->front++;
        q->arr[q->rear] = value;
    }
    else if((q->rear+1)%q->size == q->front){
        printf("Overflow\n");
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    if(q->rear==-1 && q->front==-1){
        printf("underflow\n");
    }
    else if(q->rear == q->front){
        q->rear = -1;
        q->front = -1;
    }
    else{
        int val = q->arr[q->front];
        q->front = (q->front+1)%q->size;
    }
}

void display(struct queue* q){
    if(q->rear == -1 && q->front == -1){
        printf("Empty Queue\n");
    }
    else{
        int i = q->front;
        while(i != q->rear){
            printf("%d\t", q->arr[i]);
            i = (i+1)%q->size;
        }
        printf("%d\n", q->arr[i]);
    }
}

void main(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
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

    enqueue(q, 60);
    enqueue(q, 70);
    display(q);
}
