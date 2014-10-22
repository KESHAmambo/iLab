#include "stdafx.h"
#include "stack.h"
#define float int
/*
struct mystack
{
struct mystackval* last = NULL;
double pop();
int push(double a);
void delall();
};
*/
struct mystackval
{
	int value;
	struct mystackval* previous = NULL;
};


mystack::mystack()
{
	numberOfEl = 0;
}


int mystack::push(int a)
{

	struct mystackval* newEl = (struct mystackval*)calloc(1, sizeof(struct mystackval));
	struct mystackval* before;
	if (newEl == NULL)
		return 0;
	before = last;
	last = newEl;
	newEl->value = a;
	newEl->previous = before;
	numberOfEl++;
	return 1;
}



int mystack::pop()
{
	int result;
	struct mystackval* newLast;
	if (last == NULL)
		result = NAN;
	else
	{
		result = last->value;
		newLast = last->previous;
		free(last);
		last = newLast;
		numberOfEl--;
	}
	return result;
}


void mystack::delall()
{
	struct mystackval* newLast;
	while (last != NULL)
	{
		newLast = last->previous;
		free(last);
		last = newLast;
		numberOfEl = 0;
	}
}


long mystack::getNumberOfEl()
{
	return numberOfEl;
}



int inttoc(char c)
{
	switch (c)
	{
  	case '0':
  		return 0;
  	case '1':
  		return 1;
	  case '2':
		  return 2;
  	case '3':
	  	return 3;
	  case '4':
	  	return 4;
  	case '5':
  		return 5;
  	case '6':
  		return 6;
  	case '7':
  		return 7;
  	case '8':
  		return 8;
  	case '9':
  		return 9;
  	case '+':
  		return 10;
  	case '-':
  		return 11;
  	case '*':
  		return 12;
  	case '/':
  		return 13;
	}
}

int power(int a, int b)
{
	int c = 1;
	for (int i = 0; i < b; i++)
		c = c * a;
	return c;
}
