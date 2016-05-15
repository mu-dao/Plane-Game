#include "windows.h"
const int num = 10;
class bullet{
private:
	COORD position[num];
public:
	bullet(){
		for(int i = 0; i < num; i++)
			position[i].Y = 0;
	}
	void draw_bullet();
	void draw_enemy_bullet();
	void move_bullet();
	void move_enemy_bullet();
	void clean_bullet();
	void clean_bullet(int i);
	void initial_bullet(COORD m);
	void initial_enemy_bullet(COORD m);
	COORD get_position(int i);
};