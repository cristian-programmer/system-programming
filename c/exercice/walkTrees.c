#include "./../stack/stack.h"

void inOderNoRecursive(struct tree *root){
    struct tree *temp = root;
    bool sw = 0;
    struct node *top = NULL;
    
    while(sw == 0){
        while(temp != NULL){
            push(&top, temp);
            temp = temp->left;
        }

        if(isEmpty(top)){
            sw = 1;
        }else {
            temp  = pop(&top);
            printf("%i here \n", temp->index);
            temp = temp->right;
        }
    }
}

void preOderNoRecursive(struct tree *root){
    
    bool sw = 0;
    struct node *top = NULL;
    
    if(root == NULL)
        return;
        
    push(&top, root);
    
    while(!isEmpty(top)){
        struct tree *temp = pop(&top);
        printf("%i ", temp->index);
        
        if(temp->right)
            push(&top, temp->right);
        if(temp->left)
            push(&top, temp->left);
    }
}

void inOrderOptional(struct tree *root){
    struct tree *current = root;
    bool sw = false;
    struct node *top = NULL;
    
    while(!sw) {
        if(current != NULL){
            push(&top, current);
            current = current->left;
        }else {
            if(!isEmpty(top)){
                current =  pop(&top);
                printf("%i --->", current->index);
                current = current->right;
            }else {
                sw = true;
            }
        }
    }
}

int main(){

    struct tree *node = NULL;
   // struct node *top =  NULL;
    insertNode(&node, 10);
    //push(&top, node);
   // pop(&top);    
    insertNode(&node, 11);
    //push(&top, node->right);
    insertNode(&node, 6);
    //push(&top, node->left);

    
    //pop(&top);
   // pop(&top);
    //inOrder(node);
    inOderNoRecursive(node);
    printf("--------------\n");
    preOderNoRecursive(node);
    //viewPosOrder(node);
    
    //printf("--------------\n");

  /* 
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
