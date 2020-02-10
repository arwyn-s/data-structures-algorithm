#include <stdio.h>

#include "queue.h"

int main(int argc, char* argv) {

    //que_node* que = create_node(9);
    queue *que = create_queue();
    queue_print(que->front);
    enqueue(que,9);
    enqueue(que,10);
    queue_print(que->front);
    enqueue(que,19);
    queue_print(que->front);
    dequeue(que);
    queue_print(que->front);
    enqueue(que,20);
    queue_print(que->front);
    dequeue(que);
    queue_print(que->front);
    dequeue(que);
    queue_print(que->front);
    dequeue(que);
    queue_print(que->front);
}