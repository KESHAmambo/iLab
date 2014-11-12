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
	while (!isEmpty(stack))
	{
		struct List* temp = stack;
		stack = stack->next;
		free(temp);
	}
	return stack;
}

int inttoc(char c)
{
	switch (c - '0')
	{
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
	case 6:
		return 6;
	case 7:
		return 7;
	case 8:
		return 8;
	case 9:
		return 9;
	case -5:
		return -5;
	case -3:
		return -3;
	case -6:
		return -6;
	case -1:
		return -1;
	}
}

char add[20] = "add";
char sub[20] = "sub";
char mul[20] = "mul";
char diva[20] = "div";
char pusha[20] = "push";
char popa[20] = "pop";
char print[20] = "print";
char mov[20] = "mov";
char jump[20] = "jump";

int wordsToInt(char* w)
{
	int i = 0;
	int check = 0;

	for (i = 0; i < 20; i++)
	{
		if (w[i] != add[i])
			check = 1;
	}
	if (check == 0)
		return 111;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != sub[i])
			check = 1;
	}
	if (check == 0)
		return 122;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != mul[i])
			check = 1;
	}
	if (check == 0)
		return 211;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != diva[i])
			check = 1;
	}
	if (check == 0)
		return 222;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != pusha[i])
			check = 1;
	}
	if (check == 0)
		return 311;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != popa[i])
			check = 1;
	}
	if (check == 0)
		return 322;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != print[i])
			check = 1;
	}
	if (check == 0)
		return 411;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != mov[i])
			check = 1;
	}
	if (check == 0)
		return 511;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != jump[i])
			check = 1;
	}
	if (check == 0)
		return 611;

	return 0;
}

int power(int a, int b)
{
	int c = 1;
	for (int i = 0; i < b; i++)
		c = c * a;
	return c;
}
