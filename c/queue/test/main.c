#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "./../queue.h"


int main(void){
	struct queue *q = malloc(sizeof(struct queue));
	initializate(q);
	assert(q != NULL);
}

