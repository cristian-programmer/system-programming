#include <stdlib.h>
#include <stdio.h>


struct list {
	void *data; // generic data
	struct list *next;
};


void push(struct list **head, void *data, size_t data_size){
	struct list *node = (struct list*)malloc(sizeof(struct list));
	node->data = malloc(data_size);
	node->next = (*head);

	int i;
 	for(i=0; i < data_size; i++){
		*(char *)(node->data + i) = *(char *)(data + 1);
		(*head) = node;
	}
}


void printList(struct list *node, void (*fptr)(void *)){
	while(node != NULL){
		(*fptr)(node->data);
		node = node->next;
	}
}


void printFloat(void *f){
	printf("%f", *(float *)f);
}


void printInt(void *n){
	printf(" %d", *(int *)n);
}
