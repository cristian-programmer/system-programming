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
void freeList(list *head);


int main(void){
    list *head = NULL;
    list *head2 = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    printListBackwards(head);
    printf("\n");
    insertAtEnd(&head2, 15);
    insertAtEnd(&head2, 10);
    insertAtEnd(&head2, 5);
    printList(head2);

    freeList(head);
    freeList(head2);  
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

void insertAtEnd(list **head, int value){
    list *newNode;
    if(head == NULL){
        return ;
    }

    newNode = malloc(sizeof(list));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data =  value;

    if(*head == NULL) {
        *head = newNode;
    }else {
        list *temp = *head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void freeList(list *node) {
    while(node != NULL){
        list *current = node->next;
        free(node);
        node = current;
    }
}