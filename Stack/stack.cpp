#include "stdafx.h"
#include "stack.h"

List* push(List* stack, int i)
{
   struct List* temp = stack;
   stack = (struct List*)calloc(1, sizeof(struct List));
   stack->value = i;
   stack->next = temp;
   stack->number = temp->number + 1;
   return stack;
}

int getCount(List* stack)
{
    int a = 0;
    while (!isEmpty(stack))
    {
        a++;
        stack = stack->next;
    }
    return a;
}

bool isEmpty(List* stack)
{
    if (stack == NULL)
        return true;
    else
        return false;
}

List* Delete(List* stack)
{
    struct List* temp = stack;
    stack = stack->next;
    free(temp);
    return stack;
}

int pop(List** stack)
{
    int a;
    struct List* temp = *stack;
    a = temp->value;
    *stack = temp->next;
    free(temp);
    return a;
}

List* DeleteAll(List* stack)
{
    while(!isEmpty(stack))
    {
        struct List* temp = stack;
        stack = stack->next;
        free(temp);
    }
    return stack;
}
