
/********
 *  
 *  queue is a linear data structure that follows FIFO (First in and First Out).
 *  Basic Operations:
 *  Enqueue
 *  Dequeue
 *  Front
 *  Rear
 * 
 * *********/
typedef struct queue_node queue_node;

struct queue_node {
    int data;
    //unsigned int capacity;
    queue_node* next;
};

typedef struct queue queue;

struct queue {
    queue_node *front;
    queue_node *rear;
};

queue_node* create_node(int num);

queue* create_queue();

int isEmpty(queue* root);

int enqueue (queue* root, int num);

int dequeue (queue* root);

int front(queue* root);

int rear(queue* root);

void queue_print(queue_node* queue);