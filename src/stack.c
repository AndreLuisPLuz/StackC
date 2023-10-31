#include "stack.h"

Node* init_node(void* data, Node* previous, callback_print cprint)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->cprint = cprint;
    new_node->previous = previous;
    new_node->next = NULL;

    if (previous != NULL)
        previous->next = new_node;

    return new_node;
}

Stack* init_stack(void)
{
    Stack* new_stack = malloc(sizeof(Stack));
    new_stack->length = 0;
    new_stack->top = NULL;

    return new_stack;
}

void push(Stack* stack, void* data, callback_print cprint)
{
    Node* node = init_node(data, stack->top, cprint);

    stack->top = node;
    stack->length++;
}

void pop(Stack* stack)
{
    Node* top_node = stack->top;

    if (stack->length > 1)
        stack->top = top_node->previous;
    else
        stack->top = NULL;

    free(top_node);
    stack->length--;
}

void print_stack(Stack* stack)
{
    Node* current_node = stack->top;

    for (int i = 0; i < stack->length; i++)
    {
        current_node->cprint(current_node->data);
        current_node = current_node->previous;
    }
}