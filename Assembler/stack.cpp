#include "stdafx.h"
#include "stack.h"

List* push(List* stack, char i)
{
	struct List* temp = stack;
	stack = (struct List*)calloc(1, sizeof(struct List));
	stack->value = i;
	//putchar(stack->value);
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

char pop(List** stack)
{
	char a;
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
	return (c - '0');
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
char pushA[20] = "pushA";
char pushB[20] = "pushB";
char popA[20] = "popA";
char popB[20] = "popB";
char jne[20] = "jne";
char je[20] = "je";
char jg[20] = "jg";
char jl[20] = "jl";
char cmp[20] = "cmp";

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

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != pushA[i])
			check = 1;
	}
	if (check == 0)
		return 312;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != pushB[i])
			check = 1;
	}
	if (check == 0)
		return 313;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != popA[i])
			check = 1;
	}
	if (check == 0)
		return 323;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != popB[i])
			check = 1;
	}
	if (check == 0)
		return 324;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != jne[i])
			check = 1;
	}
	if (check == 0)
		return 622;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != je[i])
			check = 1;
	}
	if (check == 0)
		return 633;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != jg[i])
			check = 1;
	}
	if (check == 0)
		return 644;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != jl[i])
			check = 1;
	}
	if (check == 0)
		return 655;

	check = 0;
	for (i = 0; i < 20; i++)
	{
		if (w[i] != cmp[i])
			check = 1;
	}
	if (check == 0)
		return 811;

	return 0;
}

int power(int a, int b)
{
	int c = 1;
	for (int i = 0; i < b; i++)
		c = c * a;
	return c;
}
