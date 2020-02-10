#include <stdio.h>

#include "stack.h"

int main(int argc, char* argv) {

    stack_node* stack = create_node(9);
    stack_print(stack);
    push(&stack, 10);
    stack_print(stack);
    push(&stack, 19);
    stack_print(stack);
    pop(&stack);
    stack_print(stack);
    push(&stack, 20);
    stack_print(stack);
    pop(&stack);
    stack_print(stack);
    pop(&stack);
    stack_print(stack);
    pop(&stack);
    stack_print(stack);
}