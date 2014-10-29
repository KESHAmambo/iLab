/* Assembler translates comands: 
"add"   to 111
"sub"   to 122
"mul"   to 211
"div"   to 222
"push"  to 311 with value
"pop"   to 322
"print" to 411
"mov"   to 511 with value
"jump"  to 611
*/

#include "stdafx.h"
#include <string.h>
#include "stack.h"

int main()
{
	
	char s1[100] = ""; //"FileOut.txt"; // file name, which binary code you want to get
	char s2[100] = ""; //"FileIn.txt"; // file name, where you want to put the resulting binary code
	char command[20] = ""; // command name, that we took from out-file
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

	/*printf("Enter the name of file where you want to put binary code:\n");
	for (i = 0; i < 100; i++)
	{
		simbol = getchar();
		if (simbol == '\n')
			break;
		s2[i] = simbol;
	}*/

	FILE *fout;
	FILE *fin;

	fout = fopen(s1, "r");
	fin = fopen(s2, "a");

	struct List* stack = NULL;
	stack = (struct List*)calloc(1, sizeof(struct List));
	stack->value = 1111;
	stack->next = NULL;
	stack->number = 1;

	char c = 0;
	int elstack = 0;
	int bincode = 0;

	while(fscanf(fout, "%c", &c) != EOF)
		stack = push(stack, c);

	struct List* stackR = NULL;
	stackR = (struct List*)calloc(1, sizeof(struct List));
	stackR->value = 3333;
	stackR->next = NULL;
	stackR->number = 1;

	struct List* stackV = NULL;
	stackV = (struct List*)calloc(1, sizeof(struct List));
	stackV->value = 5555;
	stackV->next = NULL;
	stackV->number = 1;

	while (stack->number != 1)
		stackR = push(stackR, pop(&stack));

	int alarm = 0;
	
	while (stackR->number > 1)
	{
		while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333) // char ' ' = int 32, char '\n' = int 10
			pop(&stackR);

		while (stackR->value != 10 && stackR->value != 32 && stackR->value != 3333)  // stackR - has all elements of original file
			stack = push(stack, pop(&stackR));				

		while (stack->number != 1)
			stackV = push(stackV, pop(&stack));  // there is first command in the stackV

		elstack = stackV->number;

		for (i = 0; i < elstack - 1; i++)
		{
			command[i] = pop(&stackV);
		}

		bincode = wordsToInt(command);

		for (i = 0; i < elstack - 1; i++)
		{
			command[i] = 0;
		}

		if (bincode == 0)
		{
			printf("Error in the algorithm presented in the original file.\n");
			break;
		}

		printf("%d ", bincode);

		if (bincode == 311 || bincode == 511)
		{
			bincode = 0;
			while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333) // char ' ' = int 32, char '\n' = int 10
				pop(&stackR);


			while (stackR->value != 10 && stackR->value != 32 && stackR->value != 3333)
				stack = push(stack, pop(&stackR));

			while (stack->number != 1)
				stackV = push(stackV, pop(&stack));

			while (stackV->number != 1)
			{
				bincode = bincode + inttoc(pop(&stackV)) * power(10, stackV->number - 1);
			}

			printf("%d", bincode);
		}
		bincode = 0;
		printf("\n");

		while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333)
			pop(&stackR);
	}
	getchar();
	return 0;
}
