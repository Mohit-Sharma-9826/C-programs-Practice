#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
} *head = NULL, *tail = NULL;


int getlen(){
    int count = 0;
    struct node* ptr = head;
    while(ptr != tail){
        count++;
        ptr = ptr->next;
    }
    count++;
    return count;
}

void traverse(){
    if(head == NULL){
        printf("Empty Linked List!\n");
    }
    else{
        struct node* ptr = head;
        while(ptr != tail){
            printf("%d \t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d \t", ptr->data);
        printf("\n");
    }
}

void insert_at_start(int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;
    new->prev = NULL;

    if(head == NULL){
        head = new;
        tail = new;
        head->next = head;
        head->prev = head;
    }
    else{
        new->next = head;
        new->prev = tail;
        head->prev = new;
        tail->next = new;
        head = new;
    }
}

void insert_at_end(int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;
    new->prev = NULL;

    if(head == NULL){
        head = new;
        tail = new;
        head->next = head;
        head->prev = head;
    }
    else{
        new->next = head;
        new->prev = tail;
        head->prev = new;
        tail->next = new;
        tail = new;
    }
}

void insert_at_index(int info, int index){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;
    new->prev = NULL;

    if(head == NULL && tail == NULL){
        printf("Linked List is empty, so indexing is not possible!\n");
    }
    else if(index<0 || index>getlen()){
        printf("Invalid Index!\n");
    }
    else if(index == 0){
        insert_at_start(info);
    }
    else if(index == getlen()){
        insert_at_end(info);
    }
    else{
        struct node* ptr = head;
        for(int i=0; i<index-1; i++){
            ptr = ptr->next;
        }
        new->next = ptr->next;
        new->prev = ptr;
        ptr->next->prev = new;
        ptr->next = new;
    }
}

void delete_from_start(){
    if(head == NULL && tail == NULL){
        printf("Empty Linked!\n");
    }
    else if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
        tail->next = head;
        free(head->prev);
        head->prev = tail;
    }
}

void delete_from_end(){
    if(head == NULL && tail == NULL){
        printf("Empty Linked!\n");
    }
    else if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->prev;
        head->prev = tail;
        free(tail->next);
        tail->next = head;
    }
}

void delete_from_index(int index){
    if(head == NULL && tail == NULL){
        printf("Linked List is empty, so indexing is not possible!\n");
    }
    else if(index<0 || index>=getlen()){
        printf("Invalid Index!\n");
    }
    else if(index == 0){
        delete_from_start();
    }
    else if(index == getlen()-1){
        delete_from_end();
    }
    else{
        struct node*ptr = head;
        for(int i=0; i<index; i++){
            ptr = ptr->next;
        }
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        ptr->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }    
}

void main(){
    insert_at_start(20);
    insert_at_start(10);
    traverse();

    insert_at_end(30);
    insert_at_end(40);
    insert_at_end(50);
    traverse();

    insert_at_index(101, 2);
    traverse();

    delete_from_start();
    traverse();

    delete_from_end();
    traverse();

    delete_from_index(3);
    traverse();
}