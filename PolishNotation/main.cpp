#include "stdafx.h"
#include "stack.h"
#include "functions.h"

int main()
{
	struct mystack stack;
	printf("Please, enter 'F', when you will finish enter elements.\n");
	char a = NULL;

	
	while (1) 
	{
		a = getchar();
		if (a == 'F')
		{
			stack.push(a);
			break;
		}
		else
		{
			stack.push(a);
		}
	}

	struct mystack stackR;

	while (stack.getNumberOfEl())
	stackR.push(stack.pop());


	int result = 0;
	int b = 0;
	int d = 0;
	int c = 0;

		struct mystack stackV;   // first number
		while (1)
		{
			a = stackR.pop();
			if (a == ' ' || a == 'F')
				break;
			else
			{
				stackV.push(a);
			}
		}

		while (stackV.getNumberOfEl())
			stack.push(stackV.pop());

		while (stack.getNumberOfEl())
		{
			b = b + inttoc(stack.pop()) * power(10, stack.getNumberOfEl());
		}

		
	    // second number
		while (1)
		{
			a = stackR.pop();
			if (a == ' ' || a == 'F')
				break;
			else
			{
				stackV.push(a);
			}
		}

		while (stackV.getNumberOfEl())
			stack.push(stackV.pop());

		while (stack.getNumberOfEl())
		{
			d = d + inttoc(stack.pop()) * power(10, stack.getNumberOfEl());
		}

		c = inttoc(stackR.pop()); // numerical operation
		switch (c)
		{
			case -5:
				b = b + d;
				break;
			case -3:
				b = b - d;
				break;
			case -6:
				b = b * d;
				break;
			case -1:
				b = b / d;
		}

		if (stackR.getNumberOfEl())
			stackR.pop();
		d = 0;

		if (stackR.getNumberOfEl())
		{
			while (stackR.getNumberOfEl())   
			{
			    // third number and further
				while (1)
				{
					a = stackR.pop();
					if (a == ' ' || a == 'F')
						break;
					else
					{
						stackV.push(a);
					}
			}


			while (stackV.getNumberOfEl())
				stack.push(stackV.pop());

			while (stack.getNumberOfEl())
			{
				d = d + inttoc(stack.pop()) * power(10, stack.getNumberOfEl());
			}

			c = inttoc(stackR.pop()); // numerical operation
			switch (c)
			{
				case -5:
					b = b + d;
					break;
				case -3:
					b = b - d;
					break;
				case -6:
					b = b * d;
					break;
				case -1:
					b = b / d;
			}

			if (stackR.getNumberOfEl())
				stackR.pop();
			d = 0;
			}

			printf("%d\n", b);
		}

		else
			printf("%d\n", b);

	getchar();
	return 0;
}
