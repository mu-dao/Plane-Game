#include "stdio.h"
#include "time.h"
#include "conio.h"
#include "control.h"

extern void SetPos(COORD);
extern void SetPos(int ,int );
extern void HideCursor();
extern void failed();
extern bullet enemy_bullet[10];
bool move_flag_hp = false;
void drawRow(int y, int x1, int x2, char ch){
	SetPos(x1,y);
	for(int i = 0; i <= (x2-x1); i++)
		printf("%c",ch);
}
void drawCol(int x, int y1, int y2, char ch){
	while(y1 <= y2){
		SetPos(x,y1);
		printf("%c",ch);
		y1++;
	}
}
void drawFrame(COORD a, COORD  b, char row, char col){
	drawRow(a.Y, a.X+1, b.X-1, row);
	drawRow(b.Y, a.X+1, b.X-1, row);
	drawCol(a.X, a.Y+1, b.Y-1, col);
	drawCol(b.X, a.Y+1, b.Y-1, col);
}
void drawFrame(int x1, int y1, int x2, int y2, char row, char col){
	COORD a = {x1, y1};
	COORD b = {x2, y2};
	drawFrame(a, b, row, col);
}
void control::draw_menu(){
	HideCursor();
	SetPos(34, 1);
	printf("飞机大战\n");
    drawRow(3, 0, 79, '=');
	SetPos(28,5);
	printf("请按数字键1或2选择难度\n");
	SetPos(35, 9);
	printf("1. 简单");
	SetPos(35, 11);
	printf("2. 困难");
	drawRow(20, 0, 79, '=');
	
	int j = 9;
    SetPos(32, j);
	printf("*");
	
	while(char x = _getch()){
		switch(x){
			case '1':{
				SetPos(40,9);
				Sleep(500);system("cls");
				SetPos(30,10);
				printf("你也许可以生存很长时间\n");
				Sleep(1000);system("cls");
				speed = 40;
				return ;
			}
			case '2':{
				SetPos(32,j);
				printf(" ");
				j = 11;
				SetPos(32,j);
				printf("*");
				SetPos(40,11);
				Sleep(500);system("cls");
				SetPos(34,10);
				printf("你将难以生存!\n");
				Sleep(1000);system("cls");
				speed = 15;
				return ;
			}
			default:speed = 40;return ;
		}
	}
}
void control::draw_sky(){
	drawFrame(0, 0, 50, 24, '=', '|');
	drawFrame(51, 0, 79, 4, '-', '|');
	drawFrame(51, 4, 79, 8, '-', '|');
	drawFrame(51, 8, 79, 24, '-', '|');
	SetPos(52, 2);
	printf("状态：游戏中");
	SetPos(52, 6);
	printf("得分：0");
	SetPos(64, 6);
	printf("HP:100");
	SetPos(52,10);
	printf("操作方式：");
	SetPos(52,12);
	printf("w,s,a,d对应上下左右");
	SetPos(52,14);
	printf("k:发射子弹");
	SetPos(52,16);
	printf("p:暂停游戏");
	SetPos(52,18);
	printf("e:退出游戏");
}
void control::game(){
	plane player;
	player.draw_plane();
	enemy _enemy;
	_enemy.draw_plane();
	bullet _bullet;

	int speed_control = 0;
	int bullet_control = 0;
	while(1){
		Sleep(5);
		if(_kbhit()){
			char x = _getch();
			move_flag_hp = false;
			if(x == 'w'|| x == 'a' || x == 's' || x == 'd'){
				player.move_plane(x);
				move_flag_hp = true;
			}
			else if(x == 'k'){
				_bullet.initial_bullet(player.get_position(0));
				_bullet.draw_bullet();
			}
			else if(x == 'p'){
				pause();
			}
			else if(x == 'e'){
				failed();
			}
		}
		control_enemy(speed_control, _enemy);
		control_bullet(bullet_control, _bullet, _enemy);
		control_player(_enemy, player);
		player.draw_plane();
	}
}
void control::control_bullet(int &bullet_control, bullet &_bullet, enemy &_enemy){
	static int score = 0;
	if(bullet_control == 0){
		_bullet.move_bullet();
		move_flag_hp = true;
	}
	else{
		move_flag_hp = false;
	}
	bullet_control++;
	if(bullet_control == 8) bullet_control = 0;
	if(judge_hit(_enemy,_bullet)){
		score += 10;
		SetPos(58,6);
		printf("%d",score);
	}
	bullet_crash(_bullet,enemy_bullet);
}
void control::control_player(enemy _enemy,plane player){
	static int HP = 100;
	if(judge_crash(_enemy, player)){
		if(move_flag_hp)HP -= 10;
		SetPos(69,6);
		printf(" ");
		SetPos(64,6);
		printf("HP:%d",HP);
		if(HP == 0)failed();
	}
}
void control::control_enemy(int &speed_control, enemy &_enemy){
	if(speed_control == 0){
		_enemy.move_plane();
		move_flag_hp = true;
	}
	else{
		move_flag_hp = false;
	}
	speed_control++;
	if(speed_control == speed) speed_control = 0;

}
bool control::judge_crash(enemy &_enemy,plane player){ 
	for(int i = 0; i < 10; i++){
		if(   ((_enemy.get_position(i,3).X == player.get_position(0).X) && (_enemy.get_position(i,3).Y == player.get_position(0).Y))
			||((_enemy.get_position(i,0).X == player.get_position(5).X) && (_enemy.get_position(i,0).Y == player.get_position(5).Y))
			||((_enemy.get_position(i,2).X == player.get_position(2).X) && (_enemy.get_position(i,2).Y == player.get_position(2).Y))
			||((_enemy.get_position(i,3).X == player.get_position(1).X) && (_enemy.get_position(i,3).Y == player.get_position(1).Y))
			||((_enemy.get_position(i,3).X == player.get_position(2).X) && (_enemy.get_position(i,3).Y == player.get_position(2).Y))
			||((_enemy.get_position(i,3).X == player.get_position(5).X) && (_enemy.get_position(i,3).Y == player.get_position(5).Y)) ){
				//enemy_bullet[i].clean_bullet();
				_enemy.clean_plane(i);
				return true;
		}
	}
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++){
			COORD temp = enemy_bullet[i].get_position(j);
			if(   (temp.X == player.get_position(0).X && temp.Y == player.get_position(0).Y)
				||(temp.X == player.get_position(1).X && temp.Y == player.get_position(1).Y)
				||(temp.X == player.get_position(2).X && temp.Y == player.get_position(2).Y)
				||(temp.X == player.get_position(5).X && temp.Y == player.get_position(5).Y)){
					enemy_bullet[i].clean_bullet(j);
					return true;
			}
		}
	return false;
}
bool control::judge_hit(enemy &_enemy, bullet &_bullet){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(
				((_enemy.get_position(i,0).X == _bullet.get_position(j).X)&&(_enemy.get_position(i,0).Y == _bullet.get_position(j).Y))
				||((_enemy.get_position(i,2).X == _bullet.get_position(j).X)&&(_enemy.get_position(i,2).Y == _bullet.get_position(j).Y))
				||((_enemy.get_position(i,3).X == _bullet.get_position(j).X)&&(_enemy.get_position(i,3).Y == _bullet.get_position(j).Y))
			){
				//enemy_bullet[i].clean_bullet();
				_enemy.clean_plane(i);
				_bullet.clean_bullet(j);
				return true;
			}
		}
	}
	return false;
}
void control::bullet_crash(bullet &_bullet,bullet enemy_bullet[10]){
	for(int i = 0; i < 10; i++)   //enemy_bullet下标
		for(int j = 0; j < 10; j++) //enemy_bullet[i].position[j]
			for(int k = 0; k < 10; k++){ //_bullet.position[k]
				COORD enemy_bullet_pos = enemy_bullet[i].get_position(j);
				COORD player_bullet_pos = _bullet.get_position(k);
				if(enemy_bullet_pos.X == player_bullet_pos.X && enemy_bullet_pos.Y == player_bullet_pos.Y){
					enemy_bullet[i].clean_bullet(j);
					_bullet.clean_bullet(k);
				}
			}
}
void control::pause(){
	SetPos(58,2);
	printf("暂停中...");
	char c = _getch();
	while(c != 'p')
		c = _getch();
	SetPos(58,2);
	printf("游戏中");
}
void failed(){
	system("cls");
	SetPos(31,10);
	char buf[] = "Sorry,You failed!";
	int len = strlen(buf);
	for(int i = 0; i < len; i++){
		printf("%c",buf[i]);
		Sleep(100);	
	}
	Sleep(1000);
	SetPos(0,24);
	exit(0);
}