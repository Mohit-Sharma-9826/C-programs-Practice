#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
 
void main(){
    struct node *head, *second, *third;
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = NULL;

    struct node * ptr = head;
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

}