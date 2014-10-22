#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include <math.h>

#ifndef MYSTACK
#define MYSTACK

struct mystack
{
private:
	struct mystackval* last = NULL;
	long numberOfEl;
public:
	mystack();
	int pop();
	int push(int a);
	void delall();
	long getNumberOfEl();
};

struct mystackval;

int inttoc(char c);
int power(int a, int b);


#endif
