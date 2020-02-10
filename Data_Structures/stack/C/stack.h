
/********
 *  
 *  Stack is a linear data structure that follows FILO (First in and Last Out).
 *  Basic Operations:
 *  Push
 *  Pop
 *  Peek
 *  IsEmpty
 * 
 * *********/
typedef struct stack_node stack_node;

struct stack_node {
    int data;
    //unsigned int capacity;
    stack_node* next;
};

stack_node* create_node(int num);

int isEmpty(stack_node* root);

int push (stack_node** root, int num);

int pop (stack_node** root);

int peek(stack_node* root);

void stack_print(stack_node* stack);