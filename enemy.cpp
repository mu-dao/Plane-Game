#include "enemy.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "bullet.h"
extern void SetPos(COORD);
COORD a={1, 1};
COORD b={46, 10};
bullet enemy_bullet[10];
void enemy::draw_plane(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 4; j++){
			if(_enemy[i].position[j].Y < 24){
				SetPos(_enemy[i].position[j]);
				printf("*");
			}
		}
	}
}
void enemy::clean_plane(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 4; j++){
			if(_enemy[i].position[j].Y < 24){
				SetPos(_enemy[i].position[j]);
				printf(" ");
			}
		}
	}
}
void enemy::clean_plane(int i){
	for(int j = 0; j < 4; j++){
		if(_enemy[i].position[j].Y < 24){
			SetPos(_enemy[i].position[j]);
			printf(" ");
		}
	}
	new_plane(a, b, i);
}
void enemy::move_plane(){
	clean_plane();
	for(int i = 0; i < 10; i++){
		if(_enemy[i].position[3].Y+1 > 24){
			new_plane(a, b, i);
		}
		else{
			for(int j = 0; j < 4; j++)
				_enemy[i].position[j].Y++;
		}
		int pos = random(a, b).X%4;
		switch(pos){
		case 0://Ïò×óÒÆ¶¯
			{
				if(_enemy[i].position[0].X-1 < 1){
					new_plane(a, b, i);
				}
				else{
					for(int j = 0; j < 4; j++)
						_enemy[i].position[j].X--;
				}
				break;
			}
		case 1:
			{
				if(_enemy[i].position[2].X+1 > 49){
					new_plane(a, b, i);
				}
				else{
					for(int j = 0; j < 4; j++)
						_enemy[i].position[j].X++;
				}
				break;
			}
		default:enemy_bullet[i].initial_enemy_bullet(_enemy[i].position[3]);break;
		}
		enemy_bullet[i].move_enemy_bullet();
		enemy_bullet[i].draw_enemy_bullet();
	}
	draw_plane();
}
void enemy::new_plane(COORD a, COORD b, int i){
	_enemy[i].position[0] = random(a, b);
	_enemy[i].position[1].X = _enemy[i].position[3].X = _enemy[i].position[0].X+1;
	_enemy[i].position[2].X = _enemy[i].position[0].X+2;
	_enemy[i].position[1].Y = _enemy[i].position[2].Y = _enemy[i].position[0].Y;
	_enemy[i].position[3].Y = _enemy[i].position[0].Y+1;
	enemy_bullet[i].initial_enemy_bullet(_enemy[i].position[3]);
}
COORD enemy::get_position(int i, int j){
	return _enemy[i].position[j];
}