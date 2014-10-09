#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct List
{
 int value;
 struct List* next;
 int number;

 List* push(List* stack, int i);
 int pop(List* stack);
 int getCount(List* stack);
 bool isEmpty(List* stack);
 List* Delete(List* stack);

};

List* push(List* stack, int i);
int pop(List* stack);
int getCount(List* stack);
bool isEmpty(List* stack);
List* Delete(List* stack);
