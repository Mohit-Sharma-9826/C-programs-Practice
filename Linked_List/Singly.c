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

struct node* insert_at_start(struct node *head, int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;

    if(head == NULL){
        head = new;
    }
    else{
        new->next = head;
        head = new; 
    }
    return head;
}

struct node* insert_at_end(struct node* head, int info){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;

    if(head == NULL){
        head = new;
    }
    else{
        struct node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

struct node * insert_at_given_index(struct node* head, int info, int index){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = info;
    new->next = NULL;

    if(head == NULL){
        printf("Indexing Not Possible because linked list is empty!\n");
    }
    else if(index<0 || index>getlen(head)){
        printf("Given Invalid Index!\n");
    }
    else if(index == 0){
        head = insert_at_start(head, info);
    }
    else if(index == getlen(head)){
        head = insert_at_end(head, info);
    }
    else{
        struct node* ptr = head;
        int i = 0;
        while(i < index-1){
            ptr = ptr->next;
            i++;
        }
        new->next = ptr->next;
        ptr->next = new;
    }
    return head;
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
    else if(index<0 || index>=getlen(head)){
        printf("Invalid index!\n");
    }
    else if(index == 0){
        head = delete_from_start(head);
    }
    else if(index == getlen(head)-1){
        head = delete_from_end(head);
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
    struct node* head = NULL;
    
    head = insert_at_start(head, 2);
    head = insert_at_start(head, 1);
    traverse(head);
    
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 5);
    traverse(head);
    
    head = insert_at_given_index(head, 4, 3);
    head = insert_at_given_index(head, 10, 0);
    traverse(head);

    head = delete_from_end(head);
    traverse(head);

    head = delete_from_start(head);
    traverse(head);

    head = delete_at_given_index(head, 2);
    head = delete_at_given_index(head, 0);
    traverse(head);
}