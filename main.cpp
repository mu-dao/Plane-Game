#include <iostream>
#include "control.h"
#include "time.h"
using namespace std;
extern void SetPos(int, int );
int main(){
	srand((unsigned int)time(NULL));
	control c;
	c.draw_menu();
	c.draw_sky();
	c.game();
	SetPos(0,25);
	return 0;
}