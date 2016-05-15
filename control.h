#include "enemy.h"
#include "plane.h"
#include "bullet.h"
class control{
private:
	int speed;
public:
	void draw_menu();//打印进入游戏界面
	void draw_sky();//打印游戏界面
	void game();//进入游戏
	void control_enemy(int &m,enemy &_enemy);
	void control_player(enemy _enemy, plane player);
	void control_bullet(int &m,bullet &_bullet, enemy &_enemy);
	bool judge_crash(enemy &_enemy, plane player);
	bool judge_hit(enemy &_enemy, bullet &_bullet);
	void bullet_crash(bullet &_bullet, bullet enemy_bullet[10]);
	void pause();
};