#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

int getlen(struct node* head){
    int count = 0;
    struct node* ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void traverse(struct node* head){
    if(head == NULL){
        printf("Empty Linked List!\n");
    }
    else{
        struct node* ptr = head;
        while(ptr != NULL){
            printf("%d \t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

struct node* insertion_at_start(struct node* head, int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->prev = NULL;
    new->next = NULL;

    if(head == NULL){
        head = new;
    }
    else{
        new->next = head;
        head->prev = new;
        head = new;        
    }
    return head;
}

struct node* insertion_at_end(struct node* head, int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->prev = NULL;
    new->next = NULL;

    if(head == NULL){
        head = new;
    }
    else{
        struct node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        new->prev = ptr;
        ptr->next = new;
    }
    return head;
}

struct node* insert_at_given_index(struct node* head, int info, int index){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->prev = NULL;
    new->next = NULL;
    
    if(head == NULL){
        printf("Linked List is empty so indexing is not possible!\n");
    }
    else if(index<0 || index>getlen(head)){
        printf("Invalid index!\n");
    }
    else if(index == 0){
        head = insertion_at_start(head, info);
    }
    else{
        struct node* ptr = head;
        for(int i=0; i<index-1; i++){
            ptr = ptr->next;
        }
        new->prev = ptr;
        new->next = ptr->next;
        ptr->next = new;
        new->next->prev = new;
    }
    return head;
}
 
void main(){
    struct node* head = NULL;
    
    head = insertion_at_start(head, 20);
    head = insertion_at_start(head, 10);
    traverse(head);

    head = insertion_at_end(head, 30);
    head = insertion_at_end(head, 50);
    traverse(head);

    head = insert_at_given_index(head, 40, 3);
    head = insert_at_given_index(head, 100, 0);
    traverse(head);
}