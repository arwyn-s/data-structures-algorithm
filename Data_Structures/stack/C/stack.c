
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_node* create_node(int num) {
    stack_node* newnode = (stack_node*) malloc(sizeof(stack_node));
    newnode->data = num;
    newnode->next = NULL;
    return newnode;
}

int isEmpty(stack_node* root) {
    return !root;
}

int push (stack_node** root, int num) {
    stack_node* nextnode = create_node(num);
    nextnode->next = *root;
    *root = nextnode;
}

int pop (stack_node** root) {
    if(isEmpty(*root)) return INT_MIN;
    stack_node *temp = *root;
    *root = (*root) ->next;
    int ret = temp->data;
    free(temp);
    return ret;
}

int peek(stack_node* root){
    if(!isEmpty(root)) {
        return root->data;
    } else {
        return INT_MIN;
    }
}

void stack_print(stack_node* root) {

    if(isEmpty(root)) {
        printf("\n");
        return ;
    }

    printf("-> %d", root->data);
    stack_print(root->next);
}