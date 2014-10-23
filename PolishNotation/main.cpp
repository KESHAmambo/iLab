#include "stdafx.h"
#include "stack.h"
#include "functions.h"

int main()
{
	

	struct mystack stack;
	printf("Please, enter 'F', when you will finish enter elements.\n");
	char a = NULL;

	
	while (1) // entering polish notation
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

		struct mystack stackV1;   // first number
		while (1)
		{
			a = stackR.pop();
			if (a == ' ' || a == 'F')
				break;
			else
			{
				stackV1.push(a);
			}
		}

		struct mystack stackVR1;

		while (stackV1.getNumberOfEl())
			stackVR1.push(stackV1.pop());

		while (stackVR1.getNumberOfEl())
		{
			b = b + inttoc(stackVR1.pop()) * power(10, stackVR1.getNumberOfEl());
		}

		
		struct mystack stackV2; // second number
		while (1)
		{
			a = stackR.pop();
			if (a == ' ' || a == 'F')
				break;
			else
			{
				stackV2.push(a);
			}
		}

		struct mystack stackVR2;

		while (stackV2.getNumberOfEl())
			stackVR2.push(stackV2.pop());

		while (stackVR2.getNumberOfEl())
		{
			d = d + inttoc(stackVR2.pop()) * power(10, stackVR2.getNumberOfEl());
		}

		c = inttoc(stackR.pop()); // numerical operation
		switch (c)
		{
		  case 10:
	  		b = b + d;
	  		break;
	  	case 11:
	  		b = b - d;
	  		break;
	  	case 12:
	  		b = b * d;
	  		break;
	  	case 13:
	  		b = b / d;
		}

		if (stackR.getNumberOfEl())
			stackR.pop();
		d = 0;

		if (stackR.getNumberOfEl())
		{
			while (stackR.getNumberOfEl())   
			{
		  	struct mystack stackV3; // third number and further
		  	while (1)
		  	{
		  		a = stackR.pop();
		  		if (a == ' ' || a == 'F')
	  				break;
	  			else
	  			{
	  				stackV3.push(a);
		  		}
			}

			struct mystack stackVR3;

			while (stackV3.getNumberOfEl())
				stackVR3.push(stackV3.pop());

			while (stackVR3.getNumberOfEl())
			{
				d = d + inttoc(stackVR3.pop()) * power(10, stackVR3.getNumberOfEl());
			}

			c = inttoc(stackR.pop()); // numerical operation
			switch (c)
			{
		  	case 10:
		  		b = b + d;
	  			break;
	  		case 11:
		  		b = b - d;
	  			break;
	  		case 12:
		  		b = b * d;
		  		break;
	  		case 13:
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
