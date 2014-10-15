#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct List
{
    int value;
    struct List* next;
    int number;
};

    List* push(List* stack, int i);
    int getCount(List* stack);
    bool isEmpty(List* stack);
    List* Delete(List* stack);
    int pop(List** stack);
    List* DeleteAll(List* stack);
