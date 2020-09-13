#include <stdbool.h>
#include <stdio.h>

struct tree {
    int index;
    struct tree *left;
    struct tree *right;
};


void insertNode(struct tree **root, int value);
void viewPosOrder(struct tree* root);
bool search(struct tree *node, int a, int b);


void insertNode(struct tree **root, int value){
    struct tree *temp = NULL;
    if(!(*root)){
        temp = malloc(sizeof(struct tree));
        temp->left =  temp->right = NULL;
        temp->index = value;
        *root =  temp;
        return;
    }
    
    if(value < (*root)->index){
        insertNode(&(*root)->left, value);
    }else if( value > (*root)->index){
        insertNode(&(*root)->right, value);
    }
}


void viewPosOrder(struct tree* root){
    if(root){
        viewPosOrder(root->left);
        viewPosOrder(root->right);
        printf("%i\n", root->index);
    }
}

bool search(struct tree *node, int a, int b){
    bool next, result = false;
    int run = 0;
    struct tree *tmp;
    while(run == 0 && node != NULL){
        if(a == node->index){
            run = 1;
            next = true;
            tmp = node;
        }else if( a > node->index){
            node = node->right;
        }else if( a < node->index){
            node = node->left;
        }
    }

    if(next){
        run = 0;
        while(run == 0 && tmp !=NULL){
            if(b == tmp->index){
                run = 1;
                result = true;
            }else if(b > tmp->index){
                tmp = tmp->right;
            }else if(b < tmp->index){
                tmp = tmp->left;
            }
        }
    }

    return result;
}
