#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
	int value;
	struct node *next;

};


bool isEmpty(struct node *top){
	return top == NULL;
} 

void push(struct node **top, int value){
	struct node* new_node = malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = *top;
	*top = new_node;
}


void display(struct node *top){
	struct node *temp = NULL;
	temp =  top;
	while(!isEmpty(temp)){
		printf("%i ", temp->value);
	}
}

void peek(struct node *top){
	if(!isEmpty(top)){
		printf("%i ", top->value);
	}
}


int pop(struct node **top){
	int n  = -1;
	if(!isEmpty(*top)){
		struct node *temp;
		temp = *top;
		n = temp->value;
		printf("value to pop %i \n", n);
		*top = (*top)->next;
		temp->next = NULL;
		free(temp);
	}
	return n;
}


