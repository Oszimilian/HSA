#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "gameboard.h"

snake *initGameboard(char startDirection, int offsetX, int offsetY, int startX, int startY)
{
	snake *gameboard = (snake*) malloc(sizeof(snake));

	gameboard->Offset[_x] = offsetX;
	gameboard->Offset[_y] = offsetY;

	gameboard->startPosition[_x] = startX;
	gameboard->startPosition[_y] = startY;

	gameboard->direction = startDirection;

	gameboard->leangh = 0;

	printGameboard(gameboard);

	return gameboard;
}

void freeGameboard(snake *game)
{
	printf("\33[%d;%dH%s", (game->Offset[0] + _gameboardHeight + 2), 0, "Ende vom Spiel");

	free(game);
}

void printFrame(snake *game)
{
	for (int i = 0; i < (_gameboardHeight + 2); i++)
	{
		for (int k = 0; k < (_gameboardWidght + 2); k++)
		{
			if(k == 0 || k == (_gameboardWidght + 1))
			{
				printf("\33[%d;%dH%s", (game->Offset[0] + i - 1), (game->Offset[1] + k - 1), "|");
			}
			if(i == 0 || i == (_gameboardHeight + 1))
			{
				printf("\33[%d;%dH%s", (game->Offset[0] + i - 1), (game->Offset[1] + k - 1), "-");
			}

		}
	}
}

void printGameboard(snake *game)
{
	char c = ' ';

	for (int i = 0; i < _gameboardWidght; i++)
	{
		for (int k = 0; k < _gameboardHeight; k++)
		{
			for (int m = 0; m <= game->leangh; m++)
			{
				if (i == game->position[m][_actPos][_x] && k == game->position[m][_actPos][_y])
				{
					c ='o';
					break;
				} else {
					c = ' ';
				}
			}

			printf("\33[%d;%dH%c", (game->Offset[0] + k), (game->Offset[1] + i), c);
		}
	}

	printFrame(game);
}

void calcNewPosition(snake *game)
{
	if (game->leangh == 0)
	{
		game->position[0][_actPos][_x] = game->position[0][_newPos][_x];
		game->position[0][_actPos][_y] = game->position[0][_newPos][_y];
	}

	if (game->leangh > 0)
	{
		for (int i = 0; i < game->leangh; i++)
		{
			game->position[i + 1][_newPos][_x] = game->position[i][_actPos][_x];
			game->position[i + 1][_newPos][_y] = game->position[i][_actPos][_y];
		}

		for (int i = 0; i <= game->leangh; i++)
		{
			game->position[i][_actPos][_x] = game->position[i][_newPos][_x];
			game->position[i][_actPos][_y] = game->position[i][_newPos][_y];
		}

	}

}

void appendNewBodyPart(snake *game)
{
	static int firstRow = 0;

	if (firstRow == 0)
	{
		firstRow = 1;
	} else {
		game->leangh++;
	}
}

int getNewPosition(snake *game, int xy, char *dir)
{
	int ret;

	if (xy == _x)
	{
		switch(*dir)
		{
			case 'w': ret = game->position[0][_actPos][_x]; break;
			case 's': ret = game->position[0][_actPos][_x]; break;
			case 'a': ret = game->position[0][_actPos][_x] - 1;break;
			case 'd': ret = game->position[0][_actPos][_x] + 1;break;
			case 'b': ret = game->startPosition[_x]; break;
			default: break;
		}
	} else {
		switch(*dir)
		{
			case 'w': ret = game->position[0][_actPos][_y] - 1;break;
			case 's': ret = game->position[0][_actPos][_y] + 1;break;
			case 'a': ret = game->position[0][_actPos][_y]; break;
			case 'd': ret = game->position[0][_actPos][_y]; break;
			case 'b': ret = game->startPosition[_y]; break;
			default: break;
		}
	}
	return ret;
}

void checkMove(snake *game)
{
	if (game->position[0][_actPos][_x] == 0 || game->position[0][_actPos][_x] == _gameboardWidght)
	{
		exit(-1);
	}
	if (game->position[0][_actPos][_y] == 0 || game->position[0][_actPos][_y] == _gameboardHeight)
	{
		exit(-1);
	}

	for (int i = 0; i < (game->leangh - 1); i++)
	{
		if (game->position[0][_actPos][_x] == game->position[i + 1][_actPos][_x])
		{
			if(game->position[0][_actPos][_y] == game->position[i + 1][_actPos][_y])
			{
				exit(-1);
			}
		}
	}
}


void setNewPosition(snake *game, char dir, int x, int y, int append)
{


	if (game->leangh <= _maxSnake)
	{
		game->position[0][_newPos][_x] = getNewPosition(game, _x, &dir);
		game->position[0][_newPos][_y] = getNewPosition(game, _y, &dir);

	} else {
		printf("Success: Game complete! \n");
		exit(-1);
	}


	if (append)
	{
		appendNewBodyPart(game);
	}

	calcNewPosition(game);

	printGameboard(game);

	checkMove(game);

	sleep(1);

}


