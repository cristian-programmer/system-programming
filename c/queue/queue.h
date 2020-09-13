#ifndef QUEUE   
#define QUEUE

#include <stdbool.h>

struct node {
    int value;
    struct queue *ref;
};

struct queue {
    int count;
    struct node *front;
    struct node *near;
};

void initializate(struct queue *queue);
bool isEmpty(struct queue *queue);
void createQueue(struct queue *queue, int value);
int dequeue(struct queue* queue);
void viewQueue(struct node* head);

void initializate(struct queue *queue){
    queue->count = 0;
    queue->front = NULL;
    queue->near  = NULL;
}

bool isEmpty(struct queue *queue){
    return (queue->count == 0);
}

void createQueue(struct queue *queue, int value){
    struct node *temp = malloc(sizeof( struct node));
    temp->value = value;
    temp->ref = NULL;
    if(!isEmpty(queue)){
        queue->near->ref = temp;
        queue->near =temp;
    }else {
        queue->front = queue->near = temp;
    }
    
    queue->count++;
}

int dequeue(struct queue* queue){
    struct node* temp;
    int n = 0;
    if(!isEmpty(queue)){
        n = queue->front->value;
        temp = queue->front;    
        queue->front = queue->front->ref;
        queue->count--;
        free(temp);
    }else {
        printf("Empty queue\n");
    }    
    return n;
}

void viewQueue(struct node* head){
    if(head == NULL){
        printf(" NULL\n");
    }else{
        printf("%d ", head->value);
        viewQueue(head->ref);
    }  
}

#endif 
