#include "./../stack.h"


int main(void){
	struct node *top = NULL;
	push(&top, 10);
	push(&top, 12);
	peek(top);
}
