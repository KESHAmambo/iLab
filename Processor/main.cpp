/* comands:
"add"   to 111
"sub"   to 122
"mul"   to 211
"div"   to 222
"push"  to 311 with value
"pop"   to 322
"print" to 411
"mov"   to 511 with variable and variable or value (variables are 'A' and 'B')
"jump"  to 611 with value

*/

#include "stdafx.h"
#include "string.h"
#include "stack.h"


struct Arr
{
	int com;
	int val1;
	int val2;
};

int main()
{
	
	
	Arr* p;
	p = (struct Arr*)calloc(1, sizeof(struct Arr));

	char s1[100] = ""; // file name, where you get binary code
	char simbol = 0;
	int i = 0;
	printf("Enter the name of original file:\n");
	for (i = 0; i < 100; i++)
	{
		simbol = getchar();
		if (simbol == '\n')
			break;
		s1[i] = simbol;
	}

	FILE *fout;
	
	fout = fopen(s1, "r");
	
	int A = 0;     // variable of processor
	int B = 0;	   // variable of processor
	int minuend = 0; // for sub
	int subtrahend = 0; // for sub
	int command = 0;
	int val = 0;
	int result = 0;
	int loc = 0;

	struct List* stack = NULL;
	stack = (struct List*)calloc(1, sizeof(struct List));
	stack->value = 1111;
	stack->next = NULL;
	stack->number = 1;

	i = 0;
	while (fscanf(fout, "%d", &command) != EOF)
	{
		p[i].com = command;
		if (command == 311 || command == 611)
		{
			fscanf(fout, "%d", &val);
			p[i].val1 = val;
		}
		if (command == 511)
		{
			fscanf(fout, "%d", &val);
			p[i].val1 = val;
			fscanf(fout, "%d", &val);
			p[i].val2 = val;
		}
		i++;
	}
	int END = i;
	i = 0;
	
	while (i < END)
	{
		switch (p[i].com)
		{
		case 111:
			result = 0;
			result = pop(&stack) + pop(&stack);
			stack = push(stack, result);
			i++;
			break;
		case 122:
			result = 0;
			minuend = pop(&stack);
			subtrahend = pop(&stack);
			result = subtrahend - minuend;
			stack = push(stack, result);
			i++;
			break;
		case 211:
			result = 0;
			result = pop(&stack) * pop(&stack);
			stack = push(stack, result);
			i++;
			break;
		case 222:
			result = 0;
			result = pop(&stack) / pop(&stack);
			stack = push(stack, result);
			i++;
			break;
		case 311:
			loc = p[i].val1;
			stack = push(stack, loc);
			i++;
			break;
		case 322:
			printf("%d\n", pop(&stack));
			i++;
			break;
		case 411:
			printf("%d\n", stack->value);
			i++;
			break;
		case 511:
			if (p[i].val1 == 'A')
			{
				if (p[i].val2 == 'B')
					A = B;
				else
					A = p[i].val2;
			}
			if (p[i].val1 == 'B')
			{
				if (p[i].val2 == 'A')
					B = A;
				else
					B = p[i].val2;
			}
			i++;
			break;
		case 611:
			val = p[i].val1 - 1;
			i = val;
			break;
		}
	}

	getchar(); 
}
