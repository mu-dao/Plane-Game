#include "windows.h"
extern int random(int, int);
extern COORD random(COORD, COORD);

class enemy{
private:
	struct index{
		COORD position[4];//�л�������
	}_enemy[10];
	void clean_plane();//���ԭ�еĵл�
public:
	enemy(){
		COORD a={1, 1};
		COORD b={45, 15};
		for(int i=0; i<10; i++){
			new_plane(a, b, i);
		}
	}
	void draw_plane();//��ӡ�л�
	void move_plane();//�ƶ��л�
	void clean_plane(int i);//һ�ܵл�������
	void new_plane(COORD a, COORD b, int i);
	COORD get_position(int i, int j);
};