#include "windows.h"
class plane{
private:
	COORD position[6];//�ɻ�������
	void clean_plane();//���ԭ�еķɻ�
public:
	plane(){
		position[0].X = 24;position[0].Y = 22;
		position[1].X = 25;position[1].Y = 22;
		for(int i = 2; i < 6; i++){
			position[i].X = 21+i;
			position[i].Y = 23;
		}
	}
	void draw_plane();//��ӡ��ҷɻ�
	void move_plane(char command);//�ƶ��ɻ�
	COORD get_position(int i);
};