#include <stdio.h>
#include <stdlib.h>
 
struct node{
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

struct node* delete_from_start(struct node* head){
    if(head == NULL){
        printf("Empty Linked List!\n");
    }
    else{
        struct node* ptr = head;
        head = head->next;
        ptr->next = NULL;
        free(ptr);
    }
    return head;
}

struct node* delete_from_end(struct node* head){
    if(head == NULL){
        printf("Empty Linked List!\n");
    }
    else if(head->next == NULL){
        head = NULL;
    }
    else{
        struct node* ptr = head;
        
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        struct node* temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    }
    return head;
}

struct node* delete_at_given_index(struct node* head, int index){
    if(head == NULL){
        printf("Linked List empty so index not exist!\n");
    }
    else if(index<0 || index>getlen(head)){
        printf("Invalid index!\n");
    }
    else if(index == 0){
        head = delete_from_start(head);
    }
    else{
        struct node* ptr = head;
        for(int i=0; i<index-1; i++){
            ptr = ptr->next;
        }
        struct node* temp = ptr->next;
        ptr->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return head;    
}

void main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));    
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* forth = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = forth;

    forth->data = 40;
    forth->next = NULL;

    traverse(head);

    head = delete_from_start(head);
    traverse(head);

    head = delete_from_end(head);
    traverse(head);

    head = delete_at_given_index(head, 0);
    traverse(head);
}