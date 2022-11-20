#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct IEEE
{
	int intInput[2];
	int binIntInput[2][32];
	
	float floatInput[2];
	int binFloatInput[2][32];
	
	int binNormalice[2][32];
	int dotPosition[2];
	int e[2];
	int mantisse[2][23];
	
	char operator;
	float result;
};

typedef struct IEEE IEEE;

int getIntLeangh(int *n)
{
	char string[32];
	
	sprintf(string, "%d", *n);
	
	return strlen(string);
}

int getFloatLeangh(float *f)
{
	char string[32];
	
	sprintf(string, "%f", *f);
	
	return strlen(string) - 2;
}

void calcResult(IEEE *ieee)
{
	switch(ieee->operator)
	{
		case '+': ieee->result = ieee->floatInput[0] + ieee->floatInput[1]; break;
		case '-': ieee->result = ieee->floatInput[0] - ieee->floatInput[1]; break;
		case '*': ieee->result = ieee->floatInput[0] * ieee->floatInput[1]; break;
		case '/': ieee->result = ieee->floatInput[0] / ieee->floatInput[1]; break;
		default: break;
	}
	
	printf("Result: %f \n", ieee->result);
}

void getInput(IEEE *ieee, char *string)
{
	printf("%s: ", string);
	
	scanf("%f %c %f", &ieee->floatInput[0], &ieee->operator, &ieee->floatInput[1]);
	
	printf("\n");
	
	calcResult(ieee);
	
	ieee->intInput[0] = (int)ieee->floatInput[0];
	ieee->intInput[1] = (int)ieee->floatInput[1];
	
	ieee->floatInput[0] = ieee->floatInput[0] - (float)ieee->intInput[0];
	ieee->floatInput[1] = ieee->floatInput[1] - (float)ieee->intInput[1];
	
	printf("Input 1: %d - %f \n", ieee->intInput[0], ieee->floatInput[0]);
	printf("Input 2: %d - %f \n", ieee->intInput[1], ieee->floatInput[1]);
	
	printf("\n");
}

void IntDezToBin(IEEE *ieee)
{
	int n = 0;
	int count = 0;
	int len = 0;
	int showFlag = 0;
	
	for (int i = 0; i < 2; i++)
	{
		n = ieee->intInput[i];
		len = getIntLeangh(&ieee->intInput[i]);
		count = 0;
		showFlag = 0;
		
		printf("Transform %d to Bin \n", ieee->intInput[i]);
		
		while(n > 0)
		{
			printf("%*d : 2 = %*d R %d \n", len, n, len, n/2, n%2);
			ieee->binIntInput[i][count] = n % 2;
			n /= 2;
			count++;
		}
		
		printf("->");
		
		for (int k = 32 - 1; k >= 0; k--)
		{
			if (ieee->binIntInput[i][k] == 1 || showFlag == 1)
			{
				printf("%d", ieee->binIntInput[i][k]);
				showFlag = 1;
			}
		}
		
		printf("\n \n");
	}
}

void floatDezToBin(IEEE *ieee)
{
	float f = 0;
	int count = 0;
	int showFlag = 0;
	int len = 0;
	
	for (int i = 0; i < 2; i++)
	{
		f = ieee->floatInput[i];
		count = 0;
		len = getFloatLeangh(&ieee->floatInput[i]);
		showFlag = 0;
		
		printf("Transform %f to Bin \n", ieee->floatInput[i]);
		
		while(f > 0 && count < 32)
		{
			f *= 2;
			
			if (f >= 1)
			{
				printf("%1.*f * 2 = %f U 1 \n", len, f / 2, f);
				
				ieee->binFloatInput[i][count] = 1;
				
				f -= 1;
			} else {
				printf("%1.*f * 2 = %f U 0 \n", len,  f / 2, f);
				
				ieee->binFloatInput[i][count] = 0;
			}
		
			count++;
		}
		
		printf("->");
		
		for (int k = 0; k < 32; k++)
		{
			if (ieee->binFloatInput[i][k] == 1 || showFlag == 1 || i == 1)
			{
				printf("%d", ieee->binFloatInput[i][k]);
				showFlag = 1;
			}
		}
		
		printf("\n \n");
	}
}

void showNumberIntBin(IEEE *ieee)
{
	int showFlag = 0;
	int counter = 0;

	for (int i = 0; i < 2; i++)
	{
		showFlag = 0;
		counter = 0;
		
		for (int k = 32 - 1; k >= 0; k--)
		{
			if (ieee->binIntInput[i][k] == 1 || showFlag == 1)
			{
				printf("%d", ieee->binIntInput[i][k]);
				ieee->binNormalice[i][counter] = ieee->binIntInput[i][k];
				showFlag = 1;
				counter++;
			}
		}
		
		ieee->dotPosition[i] = counter - 1;
		
		
		printf(".");

		
		for (int k = 0; k < 32; k++)
		{
			printf("%d", ieee->binFloatInput[i][k]);
			ieee->binNormalice[i][counter] = ieee->binFloatInput[i][k];
			counter++;
			if (counter >= 32) break;
		}
		
		printf("\n");
	}
	
	
}

void normaliceNumber(IEEE *ieee)
{
	printf("\n");
	
	for (int k = 0; k < 2; k++)
	{
		ieee->e[k] = ieee->dotPosition[k];

		for (int i = 0; i < 23; i++)
		{
			ieee->mantisse[k][i] = ieee->binNormalice[k][i + 1];
		}
		
		
		for (int i = 0; i < 23; i++)
		{
			printf("%d", ieee->mantisse[k][i]);
		}
		
		printf("\n");
		printf("Exponent: %d \n", ieee->e[k]);
		printf("\n");
	}
	
	
	if (ieee->e[0] > ieee->e[1])
	{
		int diff = ieee->e[0] - ieee->e[1];
		printf("Diff1: %d\n", diff);
		
		for (int i = 23; i >= 0; i--)
		{
			if (i - diff >= 0)
			{
				ieee->mantisse[1][i] = ieee->mantisse[1][i - diff];
			} else {
				break;
			}
		}
		
		for (int k = 0; k < diff; k++)
		{
			if (k == diff - 1)
			{
				ieee->mantisse[1][k] = 1;
			} else {
				ieee->mantisse[1][k] = 0;
			}
		}
	}
	
	if (ieee->e[0] < ieee->e[1])
	{
		int diff = ieee->e[1] - ieee->e[0];
		printf("Diff2: %d\n", diff);
		
		for (int i = 23; i >= 0; i--)
		{
			if (i - diff >= 0)
			{
				ieee->mantisse[0][i] = ieee->mantisse[0][i - diff];
			} else {
				break;
			}
		}
		
		for (int k = 0; k < diff; k++)
		{
			if (k == diff - 1)
			{
				ieee->mantisse[0][k] = 1;
			} else {
				ieee->mantisse[0][k] = 0;
			}
		}
	}
	
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 23; k++)
		{
			printf("%d", ieee->mantisse[i][k]);
		}
		printf("\n");
	}
		
	printf("\n");
}

void showIEEEFormat(IEEE *ieee)
{
	char *p = &ieee->result;

	for (int i = sizeof(float) - 1; i >= 0; i--)
	{
		for (int k = 7; k >= 0; k--)
		{
            if ( (*(p + i) & 1<<k) > 0 )
            {
            	printf("1");
            } else {
            	printf("0");
            }


            if (i == sizeof(float) - 1 && k == 7) 
            {
            	printf(" ");
            }
            if (i == sizeof(float) - 2 && k ==  7)
            {
            	printf(" ");
         	}
		}
	}
}

int main(void)
{
	IEEE *ieee = (IEEE*) malloc(sizeof(IEEE));
	
	getInput(ieee, "Input");
	
	IntDezToBin(ieee);
	
	floatDezToBin(ieee);
	
	showNumberIntBin(ieee);
	
	normaliceNumber(ieee);
	
	
	
	showIEEEFormat(ieee);

	return EXIT_SUCCESS;
}
