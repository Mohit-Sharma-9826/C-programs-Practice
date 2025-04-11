#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int getlen(struct node* tail){
    int count = 0;
    struct node* ptr = tail->next;
    while(ptr != tail){
        count++;
        ptr = ptr->next;
    }
    if(ptr == tail){
        count++;
    }
    return count;
}

void traverse(struct node* tail){
    if(tail == NULL){
        printf("Empty Linked List!\n");
    }
    else if(tail->next == tail){
        printf("%d\t", tail->data);
    }
    else{
        struct node* ptr = tail->next;
        while(ptr != tail){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        if(ptr == tail){
            printf("%d\t", ptr->data);
        }
        printf("\n");
    }
}

struct node* insert_at_start(struct node* tail, int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;

    if(tail == NULL){
        tail = new;
        tail->next = tail;
    }
    else{
        new->next = tail->next;
        tail->next = new;
    }
    return tail;
}

struct node* insert_at_end(struct node* tail, int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;

    if(tail == NULL){
        tail = new;
        tail->next = tail;
    }
    else{
        new->next = tail->next;
        tail->next = new;
        tail = new;        
    }
    return tail;
}

struct node* insert_at_index(struct node* tail, int info, int index){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;

    if(tail == NULL){
        printf("Linked List is empty, so indexing is not possible!\n");
    }
    else if(index<0 || index>getlen(tail)){
        printf("Invalid Index!\n");
    }
    else if(index == 0){
        tail = insert_at_start(tail, info);
    }
    else if(index == getlen(tail)){
        tail = insert_at_end(tail, info);
    }
    else{
        struct node* ptr = tail->next;
        for(int i=0; i<index-1; i++){
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
    }
    return tail;
}

struct node* delete_from_start(struct node* tail){
    if(tail == NULL){
        printf("Empty Linked List!\n");
    }
    else if(tail->next == tail){
        tail->next = NULL;
        tail = NULL;
    }
    else{
        struct node* temp = tail->next;
        tail->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return tail;
}

struct node* delete_from_end(struct node* tail){
    if(tail == NULL){
        printf("Empty Linked List!\n");
    }
    else if(tail->next == tail){
        tail->next = NULL;
        tail = NULL;
    }
    else{
        struct node* ptr = tail->next;
        while(ptr->next != tail){
            ptr = ptr->next;
        }
        struct node* temp = tail;
        tail = ptr;
        tail->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return tail;
}

struct node* delete_from_index(struct node* tail, int index){
    if(tail == NULL){
        printf("Linked List is empty, so indexing is not possible!\n");
    }
    else if(index<0 || index>=getlen(tail)){
        printf("Invalid Index!\n");
    }
    else if(index == 0){
        tail = delete_from_start(tail);
    }
    else if(index == getlen(tail)-1){
        tail = delete_from_end(tail);
    }
    else{
        struct node* ptr = tail->next;
        for(int i=0; i<index-1; i++){
            ptr = ptr->next;
        }
        struct node* temp = ptr->next;
        ptr->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return tail;
}
 
void main(){
    struct node* tail = NULL;

    tail = insert_at_start(tail, 30);
    tail = insert_at_start(tail, 20);
    tail = insert_at_start(tail, 10);
    traverse(tail);

    tail = insert_at_end(tail, 40);
    tail = insert_at_end(tail, 50);
    traverse(tail);

    tail = insert_at_index(tail, 101, 3);
    traverse(tail);

    tail = delete_from_start(tail);
    traverse(tail);

    tail = delete_from_end(tail);
    traverse(tail);

    tail = delete_from_index(tail, 2);
    traverse(tail);
}