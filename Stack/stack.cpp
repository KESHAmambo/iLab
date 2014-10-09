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

int pop(List* stack)
{
    return stack->value;
}

int getCount(List* stack)
{
    return stack->number;
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
