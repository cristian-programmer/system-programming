#include "./../stack.h"


int main(void){
	struct node *top = NULL;
	struct tree *root = NULL;
	
	insertNode(&root, 15);
	push(&top, root);
	peek(top);
	
}
