#ifndef QUEUE   
#define QUEUE

#include <stdbool.h>

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


#endif 