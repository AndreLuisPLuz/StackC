#ifndef STACK_H
#define STACK_H

    #include <stdio.h>
    #include <stdlib.h>

    typedef void (*callback_print)(void* data);

    typedef struct Node
    {
        void* data;
        callback_print cprint;
        struct Node* previous;
        struct Node* next;
    } Node;

    typedef struct
    {
        unsigned length;
        Node* top;
    } Stack;

    Node* init_node(void* data, Node* previous, callback_print cprint);

    Stack* init_stack(void);

    void push(Stack* stack, void* data, callback_print cprint);

    void pop(Stack* stack);

    void print_stack(Stack* stack);

#endif