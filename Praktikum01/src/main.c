/*
 ============================================================================
 Name        : HelloWorld.c
 Author      : Maximilian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rstArray(char *str, int *size)
{
	for (int i = 0; i <= *size; i++)
	{
		str[i] = ' ';
	}
}

void drawX(int size)
{
	char c[size];

	rstArray(c, &size);

	for (int i = 0; i <= size; i++)
	{
		c[i] = 'X';
	    c[size - i] = 'X';

	    printf("%s \n", c);

	    rstArray(c, &size);

	}
}

void calcSpeed(int taube_speed, int payload, int nd)
{
	double taube_x_ms = (float)taube_speed/3.6;
	double taube_x_m = 0;
	double taube_t_s = 0;

	double internet_v_bits = (float)nd * 1000 * 1000;
	double internet_x_bit = (float)payload * 8 * 1000 * 1000 * 1000;
	double internet_t_s = 0;

	internet_t_s = internet_x_bit / internet_v_bits;
	taube_x_m = taube_x_ms * internet_t_s;

	const int ausgleich = 3;


	int kastenlange = printf("------------------------------------------\n");
	char ausgabe[kastenlange];

	int ausgabelange = sprintf(ausgabe, "V_Taube: %.2f m/s", taube_x_ms);
	printf("|%s%*s|\n", ausgabe, (kastenlange - ausgabelange - ausgleich), "");

	printf("|%*s|\n", kastenlange - ausgleich, " ");

	ausgabelange = sprintf(ausgabe, "V_Internet: %4.0f MBit/s", (float)nd);
	printf("|%s%*s|\n", ausgabe, (kastenlange - ausgabelange - ausgleich), "");

	printf("|%*s|\n", kastenlange - ausgleich, " ");

	ausgabelange = sprintf(ausgabe, "Payload: %4.0f MBit/s", (float)payload);
	printf("|%s%*s|\n", ausgabe, (kastenlange - ausgabelange - ausgleich), "");

	printf("|%*s|\n", kastenlange - ausgleich, " ");

	ausgabelange = sprintf(ausgabe, "Ubertragungszeit: %5.0f s", (float)internet_t_s);
	printf("|%s%*s|\n", ausgabe, (kastenlange - ausgabelange - ausgleich), "");

	printf("|%*s|\n", kastenlange - ausgleich, " ");

	ausgabelange = sprintf(ausgabe, "Strecke <  %5.0f m", (float)taube_x_m);
	printf("|%s%*s|\n", ausgabe, (kastenlange - ausgabelange - ausgleich), "");

	printf("------------------------------------------\n");
}

void printName()
{
	char *Name = "Maximilian Hoffmann";
	int Alter = 20;
	float Groeße = 1.93;

	printf("Hallo \x94 \b lter bitte: ");

	scanf("%d", &Alter);

	printf("\nHerr %s \nAlter: %d \nGroese: %.*f", Name, Alter, 3, Groeße);
}

int main(int argc, char **argv) {

	//printName();

	//drawX(10);

	calcSpeed(72, 64, 200);



	return EXIT_SUCCESS;
}
