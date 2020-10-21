#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree {
    int index;
    struct tree *left;
    struct tree *right;
    int height;
};


int max(int a, int b);
int height(struct tree  *node);
int getBalance(struct tree *node);
struct tree *insertNode(struct tree *root, int value);
void viewPosOrder(struct tree* root);

bool search(struct tree *node, int a, int b);
struct tree *newNode(int key);

int max(int a, int b){
    return (a > b) ? a : b;
}

int height(struct tree *root){
    if(root != NULL)
        return root->height;
    return 0;
}

int getBalance(struct tree *node){
    if(node != NULL)
        return height(node->left) -height(node->right);
    return 0;
}

struct tree *newNode(int key){
    struct tree *temp = NULL;
    temp = malloc(sizeof(struct tree));
    temp->left =  temp->right = NULL;
    temp->index = key;
    temp->height = 1;

    return temp;
}

struct tree *rightRotate(struct tree *y){
    struct tree *x = y->left;
    struct tree *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}


struct tree *leftRotate(struct tree *x){
    struct tree *y = x->right;
    struct tree *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
    
}


struct tree *insertNode(struct tree *node, int key){
    if(node == NULL)
        return newNode(key);

    if(key < node->index)
        node->left = insertNode(node->left, key);
    else if (key > node->index)
        node->right = insertNode(node->right, key);
    else 
        return node;
    

    node->height =  1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if(balance > 1 && key < node->left->index)
        return rightRotate(node);
    if(balance < -1 && key > node->right->index)
        return leftRotate(node);
    if(balance > 1 && key > node->left->index)
        node->left = leftRotate(node->left);
        return rightRotate(node);
    if(balance < -1 && key < node->right->index)
        return leftRotate(node);
    
    return node;
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



typedef struct tree tree;