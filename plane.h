#include "windows.h"
class plane{
private:
	COORD position[6];//飞机的坐标
	void clean_plane();//清除原有的飞机
public:
	plane(){
		position[0].X = 24;position[0].Y = 22;
		position[1].X = 25;position[1].Y = 22;
		for(int i = 2; i < 6; i++){
			position[i].X = 21+i;
			position[i].Y = 23;
		}
	}
	void draw_plane();//打印玩家飞机
	void move_plane(char command);//移动飞机
	COORD get_position(int i);
};