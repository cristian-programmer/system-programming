#include "./tree.h"






int main(){

    struct tree *root = NULL;
    root  = insertNode(root, 10);
    root  = insertNode(root, 20);
    root  = insertNode(root, 30);
    root  = insertNode(root, 40);
    root  = insertNode(root, 50);
    root  = insertNode(root, 25);

    printf("post order\n");
    viewPosOrder(root);
    return 0;
}