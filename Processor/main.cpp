/* comands:
"add"   is 111
"sub"   is 122
"mul"   is 211
"div"   is 222
"push"  is 311 with value
"pushA" is 312
"pushB" is 313
"pop"   is 322
"popA"  is 323
"popB"  is 324
"print" is 411
"mov"   is 511 with variable and variable or value (variables are 'A' and 'B')
"jump"  is 611 with value
"jne"   is 622 with value
"je"    is 633 with value
"je"    is 644 with value
"jl"    is 655 with value
"label" is 711 with its name
"cmp"   is 811
*/

#include "stdafx.h"
#include "string.h"
#include "stack.h"
#include "ctype.h"


struct Arr
{
	int com;
	int val1;
	int val2;
	int letter;
};

int main()
{
	Arr* p;
	int size_c = 1000;
	p = (struct Arr*)calloc(size_c, sizeof(struct Arr));

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
	int flag = 0;  // variable of processor
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
	int j = 0;
	char let = 0;

 int res = fscanf(fout, "%d", &command);
	while (res!= EOF)
	{
		printf("\n%d)\n", i);
		p[i].com = command; 
		printf("command[%d] = %d\n",i, command);// error in this line
		if (command == 311 || command == 611 || command == 622 || command == 633 || command == 644 || command == 655 || command == 711)
		{
			fscanf(fout, "%d", &val);
			p[i].val1 = val;
			printf("val[%d] = %d\n",i, val);
		}
		if (command == 511)
		{
			fscanf(fout, "%c", &let);
			fscanf(fout, "%c", &let);
			p[i].val1 = let;
			fscanf(fout, "%c", &let);
			fscanf(fout, "%c", &let);
			if (isdigit(let))
			{
				fseek(fout, -1, SEEK_CUR);
				fscanf(fout, "%d", &val);
				p[i].val2 = val;
			}
			else
			{
				p[i].val2 = let;
				p[i].letter = 1;
			}
		}
		i++;
		if (i == size_c - 1)
		{
			size_c = size_c + 10;
			realloc(p, size_c);
		}
		printf("counter %d\n", i);
		for (j = 0; j<i; j++)
			printf("Command[%d] = %d\n", j, p[j].com);
 res = fscanf(fout, "%d", &command);
	}  
	
	int END = i;
	printf("\nEND %d\n", END);
	for (i=0;i<END;i++)
			printf("Command[%d] = %d\n", i, p[i].com);
	i = 0;
	printf("\n");

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
			stack = push(stack, p[i].val1);
			i++;
			break;
		case 312:
			stack = push(stack, A);
			i++;
			break;
		case 313:
			stack = push(stack, B);
			i++;
			break;
		case 322:
			printf("Stack-top: %d\n", pop(&stack));
			i++;
			break;
		case 323:
			A = pop(&stack);
			i++;
			break;
		case 324:
			B = pop(&stack);
			i++;
			break;
		case 411:
			printf("Stack-top value: %d\n", stack->value);
			i++;
			break;
		case 511:
			if (p[i].val1 == 'A')
			{
				if (p[i].letter == 1)
					A = B;
				else
					A = p[i].val2;
			}
			if (p[i].val1 == 'B')
			{
				if (p[i].letter == 1)
					B = A;
				else
					B = p[i].val2;
			}
			i++;
			break;
		case 611:
			for (j = 0; j < i; j++)
			{
				if (p[j].com == 711)
					if (p[j].val1 == p[i].val1)
						i = j + 1;
			}
			break;
		case 622:
			if (flag != 0)
				i++;
			else
			for (j = 0; j < i; j++)
			{
				if (p[j].com == 711)
				if (p[j].val1 == p[i].val1)
					i = j + 1;
			}
			break;
		case 633:
			if (flag == 0)
				i++;
			else
			for (j = 0; j < i; j++)
			{
				if (p[j].com == 711)
				if (p[j].val1 == p[i].val1)
					i = j + 1;
			}
			break;
		case 644:
			if (flag > 0)
				i++;
			else
			for (j = 0; j < i; j++)
			{
				if (p[j].com == 711)
				if (p[j].val1 == p[i].val1)
					i = j + 1;
			}
			break;
		case 655:
			if (flag < 0)
				i++;
			else
			for (j = 0; j < i; j++)
			{
				if (p[j].com == 711)
				if (p[j].val1 == p[i].val1)
					i = j + 1;
			}
			break;
		case 711:
			i++;
			break;
		case 811:
			flag = A - B;
			i++;
			break;
		}
	}
	printf("Processor work completed.\n");
	getchar(); 
}
