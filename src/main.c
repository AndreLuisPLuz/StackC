#include "stack.h"

void clean_buffer()
{
    while (getchar() != '\n');
}

void print_int(void* num)
{
    printf("Valor do no: %d\n", *((int*)num));
}

void print_char(void* c)
{
    printf("Valor do no: %c\n", *((char*)c));
}

int main()
{
    Stack* stack = init_stack();
    int number[5];
    char coisinho[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Insira número: ");
        scanf("%d", &number[i]);
    }

    clean_buffer();

    for (int i = 0; i < 5; i++)
    {
        printf("Insira caractere: ");
        scanf("%c", &coisinho[i]);
        clean_buffer();
    }

    for (int i = 0; i < 5; i++)
    {
        push(stack, &number[i], print_int);
    }

    for (int i = 0; i < 5; i++)
    {
        push(stack, &coisinho[i], print_char);
    }

    // pop(stack);
    print_stack(stack);
}