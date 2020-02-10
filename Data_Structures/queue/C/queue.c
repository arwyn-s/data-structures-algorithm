
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue_node* create_node(int num) {
    queue_node* newnode = (queue_node*) malloc(sizeof(queue_node));
    newnode->data = num;
    newnode->next = NULL;
    //newnode->rear = NULL;
    return newnode;
}
queue* create_queue() {
    queue* que = (queue*) malloc(sizeof(queue));
    que->front = NULL;
    que->rear = NULL;
    return que;
}

int isEmpty(queue* root) {
    if(front==NULL && rear==NULL) return 1;
    return 0;
}

int enqueue (queue* root, int num) {
    queue_node* newnode = create_node(num);
    if(root->rear == NULL) {
        root->rear = newnode;
        root->front = newnode;
        return num;
    }
    root->rear->next = newnode;
    root->rear = newnode;
}

int dequeue (queue* root) {
    if(root->front==NULL){
        root->rear==NULL;
        return INT_MIN;
    }
    queue_node *temp = root->front;
    root->front = root->front->next;
    if(root->front==NULL) root->rear = NULL;
    int ret = temp->data;
    free(temp);
    return ret;
}

int front(queue* root){
    if(root->front != NULL) return root->front->data;
    return INT_MIN;
}

int rear(queue* root){
    if(root->rear != NULL) return root->rear->data;
    return INT_MIN;
}

void queue_print(queue_node* root) {

    if(root == NULL) {
        printf("\n");
        return ;
    }
    printf("-> %d", root->data);
    queue_print(root->next);
}