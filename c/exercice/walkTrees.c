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
            printf("%i ", temp->index);
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

void inOrder(struct tree *root){
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
                printf("%i", current->index);
                current = current->right;
            }else {
                sw = true;
            }
        }
    }
}

void postOrderNoRecursive(struct tree *root){
    if(root == NULL)
        return;
    
    struct node *top = NULL;
    do {
        while(root){
            if(root->right)
                push(&top, root->right);
            
            push(&top, root);
            root = root->left; 
        }
        root = pop(&top);
        if(root->right && getPeek(top) == root->right){
            pop(&top);
            push(&top, root);
            root = root->right;
        }else {
            printf("%i ",root->index);
            root = NULL;
        }
    } while(!isEmpty(top));
}

int main(){

    struct tree *node = NULL;
    insertNode(&node, 10);
    insertNode(&node, 11);
    insertNode(&node, 6);
    insertNode(&node, 24);
    insertNode(&node, 5);

    inOderNoRecursive(node);
    printf("\n");
    printf("--------------\n");
    preOderNoRecursive(node);
    printf("\n");
    printf("--------------\n");
    postOrderNoRecursive(node);

    return 0;
}
