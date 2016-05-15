#include "plane.h"
#include "stdio.h"
extern void SetPos(COORD);
void plane::draw_plane(){
	for(int i = 0; i < 6; i++){
		SetPos(position[i]);
		printf("^");
	}
}
void plane::clean_plane(){
	for(int i = 0; i < 6; i++){
		SetPos(position[i]);
		printf(" ");
	}
}
void plane::move_plane(char command){
	clean_plane();
	switch(command){
	case 'w':{
		if(position[0].Y-1 < 1) break;
		for(int i = 0; i < 6; i++)
			position[i].Y--;
		break;
	}
	case 'a':{
		if(position[0].X-1 < 2) break;
		for(int i = 0; i < 6; i++)
			position[i].X--;
		break;
	}
	case 's':{
		if(position[0].Y+1 > 22) break;
		for(int i = 0; i < 6; i++)
			position[i].Y++;
		break;
	}
	case 'd':{
		if(position[0].X+1 > 47) break;
		for(int i = 0; i < 6; i++)
			position[i].X++;
		break;
	}
	}
	draw_plane();
}
COORD plane::get_position(int i){
	return position[i];
}