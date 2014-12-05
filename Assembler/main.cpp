/* Assembler translates comands: 
"add"   to 111
"sub"   to 122
"mul"   to 211
"div"   to 222
"push"  to 311 with value
"pop"   to 322
"print" to 411
"mov"   to 511 with variable and variable or value (variables are 'A' and 'B')
"jump"  to 611 with label
"pushA" to 312
"pushB" to 313
"popA"  to 323
"popB"  to 324
"jne"   to 622 with label
"je"    to 633 with label
"je"    to 644 with label
"jl"    to 655 with label
"label" to 711 with its name
"cmp"   to 811
*/

#include "stdafx.h"
#include <string.h>
#include "stack.h"

struct Label
{
	char name[100];
	int number;
};

int main()
{
	
	char s1[100] = ""; //"FileOut.txt"; // file name, which binary code you want to get
	char s2[100] = ""; //"FileIn.txt"; // file name, where you want to put the resulting binary code
	char command[20] = ""; // command name, that we take from out-file
	char simbol = 0;
	char labName[100] = "";
	int i = 0;
	int labCount = 0;
	int j = 0;
	int labcheck = 0;

	Label* p;
	int size_c = 100;
	p = (struct Label*)calloc(size_c, sizeof(struct Label));

	printf("Enter the name of original file:\n");
	for (i = 0; i < 100; i++)
	{
		simbol = getchar();
		if (simbol == '\n')
			break;
		s1[i] = simbol;
	}

	printf("Enter the name of file where you want to put binary code:\n");
	for (i = 0; i < 100; i++)
	{
		simbol = getchar();
		if (simbol == '\n')
			break;
		s2[i] = simbol;
	}

	FILE *fout;
	FILE *fin;

	fout = fopen(s1, "r");
	fin = fopen(s2, "w");

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

		if (stack->value == ':')            // if we found label
		{
			pop(&stack);
			while (stack->number != 1)
				stackV = push(stackV, pop(&stack));

			i = 0;
			while (stackV->number != 1)
			{
				p[labCount].name[i] = pop(&stackV);
				i++;
			}
			p[labCount].number = labCount;
			fprintf(fin, "711 %d\n", p[labCount].number);
			labCount++;

			if (labCount == size_c - 1)
			{
				size_c = size_c + 10;
				realloc(p, size_c);
			}
			while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333)
				pop(&stackR);
		}

		else
		{
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

			fprintf(fin, "%d ", bincode);


			if (bincode == 311)
			{
				bincode = 0; // must be here
				while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333) // char ' ' = int 32, char '\n' = int 10 ------ deleting extra spaces and hyphens
					pop(&stackR);

				while (stackR->value != 10 && stackR->value != 32 && stackR->value != 3333)
					stack = push(stack, pop(&stackR));

				while (stack->number != 1)
					stackV = push(stackV, pop(&stack));

				while (stackV->number != 1)
				{
					bincode = bincode + inttoc(pop(&stackV)) * power(10, stackV->number - 1);
				}

				fprintf(fin, "%d", bincode);
			}

			if (bincode == 511)
			{
				bincode = 0; // must be here
				while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333) // char ' ' = int 32, char '\n' = int 10    
					pop(&stackR);

				if (stackR->value == 3333)
				{
					printf("There are no variables after 'mov' in the original file");
					break;
				}

				fprintf(fin, "%c ", pop(&stackR));

				while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333) // char ' ' = int 32, char '\n' = int 10
					pop(&stackR);

				if (stackR->value == 3333)
				{
					printf("There are no variables after 'mov' in the original file");
					break;
				}

				if (stackR->value == 'A' || stackR->value == 'B')
				{
					fprintf(fin, "%c", pop(&stackR));
				}

				else
				{
					while (stackR->value != 10 && stackR->value != 32 && stackR->value != 3333)
						stack = push(stack, pop(&stackR));

					while (stack->number != 1)
						stackV = push(stackV, pop(&stack));

					while (stackV->number != 1)
					{
						bincode = bincode + inttoc(pop(&stackV)) * power(10, stackV->number - 1);
					}

					fprintf(fin, "%d", bincode);
				}

			}

			if (bincode == 611 || bincode == 622 || bincode == 633 || bincode == 644 || bincode == 655)
			{
				bincode = 0; // must be here
				while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333) // char ' ' = int 32, char '\n' = int 10 ------ deleting extra spaces and hyphens
					pop(&stackR);

				while (stackR->value != 10 && stackR->value != 32 && stackR->value != 3333)
					stack = push(stack, pop(&stackR));

				while (stack->number != 1)
					stackV = push(stackV, pop(&stack));

				i = 0;
				while (stackV->number != 1)
				{
					labName[i] = pop(&stackV);
					i++;
				}
				
				for (i = 0; i < labCount; i++)
				{
					labcheck = 0;
					for (j = 0; j < 100; j++)
					{
						if (labName[j] != p[i].name[j])
						{
							labcheck = 1;
						}
					}
					if (labcheck == 0)
					{
						fprintf(fin, "%d", i);
						break;
					}
				}
				
				for (i = 0; i < 100; i++)
					labName[i] = 0;
			}
			bincode = 0;
			fprintf(fin, "\n");

			while (stackR->value == 32 || stackR->value == 10 && stackR->value != 3333)
				pop(&stackR);
		}
	}

	printf("Assambler's work finished.\n");
	getchar();
	return 0;
}
