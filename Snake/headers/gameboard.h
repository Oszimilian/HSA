#define _gameboardHeight 10
#define _gameboardWidght 10
#define _maxSnake 10
#define _actPos 0
#define _newPos 1
#define _x 0
#define _y 1
#define _error 0
#define _success 1
#define _move 0
#define _append 1

#define _up 0
#define _down 1
#define _left 2
#define _right 3

typedef struct game
{
	int startPosition[2];
	int position[10][2][2];
	int leangh;
	int Offset[2];
	char direction;
}snake;


snake *initGameboard(char startDirection, int offsetX, int offsetY, int startX, int startY);
void freeGameboard(snake *game);
void printFrame(snake *game);
void printGameboard(snake *game);
void calcNewPosition(snake *game);
void setNewPosition(snake *game, char dir, int x, int y, int append);
void appendNewBodyPart(snake *game);
void checkMove(snake *game);

