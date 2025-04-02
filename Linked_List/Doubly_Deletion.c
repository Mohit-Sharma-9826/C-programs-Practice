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

struct node* delete_from_start(struct node* head){
    if(head == NULL){
        printf("Empty Linked List!\n");
    }
    else{
        struct node* ptr = head;
        head = head->next;
        head->prev = NULL;
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
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }
    return head;
}

struct node* delete_from_given_index(struct node* head, int index){
    if(head == NULL){
        printf("Linked List is empty so indexing is not possible!n\n");
    }
    else if(index<0 || index>getlen(head)){
        printf("Invalid Index\n");
    }
    else if(index == 0){
        head = delete_from_start(head);
    }
    else{
        struct node* ptr = head;
        for(int i=0; i<index; i++){
            ptr = ptr->next;
        }

        if(ptr->next != NULL){
            ptr->next->prev = ptr->prev;
        }
        if(ptr->prev != NULL){
            ptr->prev->next = ptr->next;
        }
        ptr->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }
    return head;
}
 
void main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* forth = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = forth;

    forth->data = 40;
    forth->prev = third;
    forth->next = NULL;

    traverse(head);

    head = delete_from_start(head);
    traverse(head);

    head = delete_from_end(head);
    traverse(head);

    head = delete_from_given_index(head, 1);
    traverse(head);
}