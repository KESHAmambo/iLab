#include "stdafx.h"
#include "stack.h"

int main()
{
    struct List* stack = NULL;
    if (isEmpty(stack))
        printf_s("Stack is empty now.\n");
    else
        printf_s("Stack includes something.\n");
    stack = (struct List*)calloc(1, sizeof(struct List));
    stack->value = 111;
    stack->next = NULL;
    stack->number = 1;

    stack = push(stack, 222);
    stack = push(stack, 333);
    stack = push(stack, 444);

    if (isEmpty(stack))
        printf_s("Stack is still empty.\n");
    else
    {
        printf_s("We added some elements and now stack isn't empty:\n");
        printf_s("%d\n", pop(&stack));
        printf_s("%d\n", getCount(stack));
    }

    stack = Delete(stack);
    printf_s("After deleting:\n");
    printf_s("%d\n", pop(&stack));
    printf_s("%d\n", getCount(stack));
 
    stack = DeleteAll(stack);
    if (isEmpty(stack))
        printf_s("Stack is NULL after ''DeleteAll''.\n");

    getchar();
    return 0;
}
