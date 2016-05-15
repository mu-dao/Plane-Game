#include "bullet.h"
#include "stdio.h"

extern void SetPos(COORD);
extern void SetPos(int ,int );

void bullet::draw_bullet(){
	for(int i = 0; i < num; i++){
		if(position[i].Y != 0){
			SetPos(position[i]);
			printf("^");
		}
	}
}
void bullet::draw_enemy_bullet(){
	for(int i = 0; i < num; i++){
		if(position[i].Y != 0){
			SetPos(position[i]);
			printf(".");
		}
	}
}
void bullet::move_bullet(){
	clean_bullet();
	for(int i = 0; i < num; i++){
		if(position[i].Y != 0){
			position[i].Y--;
			if(position[i].Y == 1)
				position[i].Y = 0;
		}
	}
	draw_bullet();
}
void bullet::initial_bullet(COORD m){
	for(int i = 0; i < num; i++){
		if(position[i].Y == 0){
			position[i].X = m.X;
			if(m.Y-1 > 1)
				position[i].Y = m.Y-1;
			break;
		}
	}
}
void bullet::clean_bullet(){
	for(int i = 0; i < num; i++){
		if(position[i].Y != 0){
			SetPos(position[i]);
			printf(" ");
		}
	}
}
void bullet::clean_bullet(int i){
	SetPos(position[i]);
	if(position[i].Y != 0)
		printf(" ");
	for(int j = 0; j < num; j++){
		if(position[j].X == position[i].X && position[j].Y == position[i].Y)
			position[i].Y = 0;
	}
}
COORD bullet::get_position(int i){
	return position[i];
}
void bullet::initial_enemy_bullet(COORD m){
	for(int i = 0; i < num; i++){
		if(position[i].Y == 0){
			position[i].X = m.X;
			if(m.Y+1 < 23)
				position[i].Y = m.Y+1;
			break;
		}
	}
}
void bullet::move_enemy_bullet(){
	clean_bullet();
	for(int i = 0; i < num; i++){
		if(position[i].Y != 0){
			position[i].Y++;
			if(position[i].Y > 23)
				position[i].Y = 0;
		}
	}
	draw_bullet();
}