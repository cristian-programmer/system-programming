#include "./../tree/tree.h"
#include "./../stack/stack.h"

void inOderNoRecursive(struct tree *root){
    struct tree *temp = root;
    bool sw = 0;
    struct node *top = NULL;
    
    while(sw == 0){
        while(temp != NULL){
            push(&top, temp->index);
            temp = temp->left;
        }

        if(isEmpty(top)){
            sw = 1;
        }else {
            int index = pop(&top);
            printf("%i \n", index);
            temp = temp->right;
        }
    }
    
}
int main(){

    struct tree *node = NULL;
    insertNode(&node, 10);
    insertNode(&node, 11);
    insertNode(&node, 6);
    printf("%i \n", node->index);
    printf("%i \n", ((node->left)->index));
    printf("%i \n", ((node->right)->index));
    inOderNoRecursive(node);
    //viewPosOrder(node);
    //printf("--------------\n");

  /*  struct node *top =  NULL;
    push(&top, 4);
    push(&top, 10);
    push(&top, 5);
    
    pop(&top);
    pop(&top);
    pop(&top);
    printf("is %i", isEmpty(top));
    */
    return 0;
}
