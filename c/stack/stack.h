#include <stdio.h>
#include <stdlib.h>



struct node {
	int value;
	struct node *next;

};


void push(struct node **top, int value){
	struct node* new_node = malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = top;
	top = new_node;
}


void display(struct node *top){
	struct node *temp = NULL;
	temp =  top;

	if(!top == NULL){
		while(temp != NULL){
			printf("%i ", temp->value);
		}
	}

}

void peek(struct node *top){
	if(top != NULL){
		printf("%i ", top->value);
	}

}


int pop(struct node *top){
	int n  = -1;
	struct node *temp;
	if(!top == NULL){
		temp = top;
		n = temp->value;
		top = top->next;
		free(temp);
	}
	return n;
}
