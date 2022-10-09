#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gameboard.h"



int main(void)
{
	printf("Hallo\n");

	int offsetX = 5, offsetY = 5;
	int startX = 5, startY = 5;

	snake *gameboard = initGameboard('w', offsetX, offsetY, startX, startY);

	setNewPosition(gameboard,'b',  5, 5, _append);

	setNewPosition(gameboard,'s', 5, 6, _append);

	setNewPosition(gameboard,'s', 5, 7, _append);

	setNewPosition(gameboard,'s', 5, 8, _append);

	setNewPosition(gameboard,'w', 5, 9, _move);

	setNewPosition(gameboard,'w', 4, 9, _move);

	setNewPosition(gameboard,'w', 3, 9, _move);

	setNewPosition(gameboard,'w', 2, 9, _move);

	setNewPosition(gameboard,'w', 2, 8, _move);

	setNewPosition(gameboard,'w', 2, 7, _move);

	setNewPosition(gameboard,'w', 2, 6, _move);

	setNewPosition(gameboard,'w', 2, 5, _move);

	setNewPosition(gameboard,'d', 2, 5, _move);

	setNewPosition(gameboard,'d', 2, 5, _move);

	setNewPosition(gameboard,'s', 2, 5, _move);

	setNewPosition(gameboard,'s', 2, 5, _move);

	setNewPosition(gameboard,'s', 2, 5, _move);

	setNewPosition(gameboard,'s', 2, 5, _move);

	setNewPosition(gameboard,'a', 2, 5, _move);

	setNewPosition(gameboard,'a', 2, 5, _move);


	freeGameboard(gameboard);

	return 0;
}
