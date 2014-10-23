#include "stdafx.h"
#include <stdio.h>

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
