/*
 * main.c
 *
 *  Created on: 13.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANZAHL_REIHEN 26
#define ANZAHL_SPALTEN 26

struct Kino
{
	int room[ANZAHL_REIHEN][ANZAHL_SPALTEN];
};

void presetKino(struct Kino *kino)
{
	srand(time(NULL));

	for (int y = 0; y < ANZAHL_REIHEN; y++)
	{
		for (int x = 0; x < ANZAHL_SPALTEN; x++)
		{
			kino->room[y][x] = rand() % 2;
		}
	}
}

void printKino(struct Kino *kino)
{
	for (int y = 0; y <= ANZAHL_REIHEN; y++)
	{
		for (int x = 0; x <= ANZAHL_SPALTEN; x++)
		{
			if (x == 0 && y == 0)
			{
				printf("   ");
			}
			else if (x == 0 && y > 0)
			{
				printf("%c ", (65 + y - 1));


			}
			else if (x > 0 && y == 0)
			{
				printf("%2d ", x);
			} else {
				printf("%3d", kino->room[y- 1][x - 1]);
			}
		}
		printf("\n");
	}
}

void searchPlace(struct Kino *kino, int n)
{
	for (int y = 0; y < ANZAHL_REIHEN; y++)
	{
		int x = 0;
		int foundPlace = 0;
		int start = 0;
		int end = 0;

		while (x < ANZAHL_SPALTEN)
		{
			if (kino->room[y][x] == 0 && x >= 0)
			{
				start = x;
				while(x < ANZAHL_SPALTEN && kino->room[y][x] == 0)
				{
					x++;
				}
				end = x;
				foundPlace = 1;
			}

			if (foundPlace && (end - start) >= n)
			{
				printf("\n Reihe %c ist von %d bis %d frei (%d Platze). ", ('A' + y), start + 1, end, end - start);
			}

			foundPlace = 0;

			x++;
		}
	}
}

int getUserInput(char *str)
{
	int n;
	printf("%s", str);
	scanf("%d", &n);
	printf("\n\n");

	return n;
}

int main(void)
{
	//int kino[ANZAHL_REIHEN][ANZAHL_SPALTEN];

	struct Kino kino;
	struct Kino *kinoPtr;
	kinoPtr = &kino;

	presetKino(kinoPtr);
	printKino(kinoPtr);
	searchPlace(kinoPtr, getUserInput("Wie viele Sitzplätze?"));

	int wait;
	scanf("%d", &wait);
	return 0;
}
