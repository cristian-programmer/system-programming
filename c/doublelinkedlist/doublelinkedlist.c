#include <stdlib.h>
#include <stdio.h>


struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node list;

void insertAtBeginning(list **head, int value); 
void insertAtEnd(list **head, int value);
void printList(list *head);
void printListBackwards(list *head);

int main(void){
    list *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);  
    printListBackwards(head);
    printList(head);  
    return 0;
}

void printListBackwards(list *head){
    if(head != NULL){
        list *p = head;
    
        while(p->next != NULL){
                p = p->next;
        }  
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->prev;
        }
    }
}

void printList(list *head) {
    list *p = head;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

void insertAtBeginning(list **head, int value){
    list *newNode;

    if(head == NULL)
        return;
    
    newNode = malloc(sizeof(list));
    newNode->next =  NULL;
    newNode->prev = NULL;
    newNode->data = value;
    

    if(*head == NULL){
        *head = newNode;

    }else {
        newNode->prev = *head;
        (*head)->next = newNode;
        *head = newNode; 
    }
}


