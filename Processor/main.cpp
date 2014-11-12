/* comands:
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
#include "string.h"
#include "stack.h"

int main()
{
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
	

	struct List* stack = NULL;
	stack = (struct List*)calloc(1, sizeof(struct List));
	stack->value = 1111;
	stack->next = NULL;
	stack->number = 1;

	int command = 0;
	int result = 0;
	while (fscanf(fout, "%d", &command) != EOF)
	{
		switch (command)
		{
		case 111:
			result = 0;
			result = pop(&stack) + pop(&stack);
			stack = push(stack, result);
			break;
		case 122:
			result = 0;
			result = pop(&stack) - pop(&stack);
			stack = push(stack, result);
			break;
		case 211:
			result = 0;
			result = pop(&stack) * pop(&stack);
			stack = push(stack, result);
			break;
		case 222:
			result = 0;
			result = pop(&stack) / pop(&stack);
			stack = push(stack, result);
			break;
		case 311:
			fscanf(fout, "%d", &command);
			stack = push(stack, command);
			break;
		case 322:
			printf("%d", pop(&stack));
			break;
		case 411:
			printf("%d", stack->value);
			break;
		case 511:
			break;
		case 611:
			rewind(fout);
		}
	}
	getchar();
}
