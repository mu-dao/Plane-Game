#include "windows.h"
#include "stdlib.h"
int random(int a, int b){
	int c=(rand() % (a-b))+ a;
	return c;
}
COORD random(COORD a, COORD b){
	int x=random(a.X, b.X);
	int y=random(a.Y, b.Y);
	COORD c={x, y};
	return c;
}