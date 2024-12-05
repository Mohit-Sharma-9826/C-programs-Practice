#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node * next;
};
struct node * first;


void insertAtStart(){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> info = 10;
    ptr -> next = first;
    first = ptr;
}

void insertAtEnd(){
    struct node *cpt, * ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    static int num = 20;
    ptr -> info = num;
    num += 10;
    cpt = first;
    while(cpt -> next != NULL){
        cpt = cpt -> next;
    }
    cpt -> next = ptr;
    ptr -> next = NULL;
}

void deleteAtStart(){
    struct node* ptr;
    ptr = first;
    first = ptr -> next;
    free(ptr);
}

void deleteAtEnd(){
    struct node *ptr, *cpt;
    ptr = first;
    while(ptr -> next != NULL){
        cpt = ptr;
        ptr = ptr -> next;
    }
    cpt -> next = NULL;
    free(ptr);
}

void deleteAtEnd2(){
    struct node *ptr;
    ptr = first;
    while(ptr -> next -> next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = NULL;
}

int main(){
    insertAtStart();
    
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();

    struct node * ptr;
    ptr = first;

    printf("info\t ptr\t\t next\n");
    while(ptr != NULL){
        printf("%d \t", ptr -> info);
        printf("%d \t", ptr);
        printf("%d \n", ptr -> next);
        ptr = ptr -> next;
    }

    deleteAtStart();

    deleteAtEnd();
    deleteAtEnd2();

    printf("After Deletion \n");
    while(first != NULL){
        printf("%d \t", first -> info);
        printf("%d \t", first);
        printf("%d \n", first -> next);
        first = first -> next;
    }
    
    return 0;
}