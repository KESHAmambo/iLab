#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


struct List
{
	int value;
	struct List* next;
	int number;
};

List* push(List* stack, char i);
int getCount(List* stack);
bool isEmpty(List* stack);
List* Delete(List* stack);
char pop(List** stack);
List* DeleteAll(List* stack);
int inttoc(char c);
int wordsToInt(char* w);
int power(int a, int b);
