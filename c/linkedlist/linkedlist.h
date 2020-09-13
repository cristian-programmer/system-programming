#include <sdtlib.h>
#include <stdio.h>


struct list {
	void *data; // generic data 
	struct list *next;
};


void push(struct list ** head, void *data, size_t data_size){
	struct list * node = malloc(sizeof(struct list));
	node->data = malloc(data_size);
	node->next = (*head);

	int i; for(i=0; i < data_size; i++){
		*(char *)(node->data + i) = *(char *)(data + 1);
		(*head) = node;
	}
}


void printFloat(void *){
	printf("%f", *(float *)f);
}
