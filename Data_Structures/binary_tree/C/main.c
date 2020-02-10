#include "binary_tree.h"
#include <stdio.h>


int main(int argc, char* argv){

    binary_tree* root = create_node(21);
    binary_tree* lchild = create_node(10);
    binary_tree* rchild = create_node(17);
    root->left = lchild;
    root->right = rchild;
    printf("%d\n",root->data);
    printf("| \\\n");
    printf("%d %d\n",root->left->data,root->right->data);
    return 0;
}