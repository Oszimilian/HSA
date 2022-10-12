#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char start, char ablage, char ziel);

int main(void)
{
	hanoi(4, 'A', 'B', 'C');

	return EXIT_SUCCESS;
}

void hanoi(int n, char start, char ablage, char ziel)
{
	if (n == 1)
	{
		printf("Start: %c --> Ziel: %c \n", start, ziel);
	}else{
		hanoi(n-1, start, ziel, ablage);
		printf("Start: %c --> Ziel: %c \n", start, ziel);
		hanoi(n-1, ablage, start, ziel);
	}
}
