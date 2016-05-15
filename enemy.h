#include "windows.h"
extern int random(int, int);
extern COORD random(COORD, COORD);

class enemy{
private:
	struct index{
		COORD position[4];//敌机的坐标
	}_enemy[10];
	void clean_plane();//清除原有的敌机
public:
	enemy(){
		COORD a={1, 1};
		COORD b={45, 15};
		for(int i=0; i<10; i++){
			new_plane(a, b, i);
		}
	}
	void draw_plane();//打印敌机
	void move_plane();//移动敌机
	void clean_plane(int i);//一架敌机被击落
	void new_plane(COORD a, COORD b, int i);
	COORD get_position(int i, int j);
};