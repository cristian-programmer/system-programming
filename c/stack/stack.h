#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./../tree/tree.h"
struct tree mytree;
struct node {
	int value;
	struct node *next;
	struct tree *link;
	
};


bool isEmpty(struct node *top){
	return top == NULL;
} 

void push(struct node **top, struct tree *value){
	struct node* new_node = malloc(sizeof(struct node));
	new_node->next = *top;
	new_node->link = value; 
	*top = new_node;
}


void display(struct node *top){
	struct node *temp = NULL;
	temp =  top;
	while(!isEmpty(temp)){
		printf("%i ", top->link->index);
	}
}

void peek(struct node *top){
	if(!isEmpty(top)){
		printf("%i ", top->link->index);
	}
}

struct tree *getPeek(struct node *top){
	if(!isEmpty(top))
		return top->link;
}


struct tree *pop(struct node **top){
	struct tree *value = NULL; 
	struct node *temp;
	if(!isEmpty(*top)){
		temp = *top;
		value = (struct tree *) temp->link;
		
		*top = temp->next;
	
		free(temp);
	}
	return value;
}


