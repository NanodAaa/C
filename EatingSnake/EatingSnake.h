#pragma once
//******************************************
//		
//		贪吃蛇所有函数声明
//		NanodAaa 2021/12/24
//******************************************

//储存蛇头位置
struct snake_head_position
{
	int x;
	int y;

};

//储存食物位置,最多同时存在3个食物
struct snake_food_position
{
	int x;
	int y;

};

//*********************声明函数*********************
void goto_XY(int x, int y);	//光标跳转
void screen_START();	//开始界面
void screen_END();	//结束界面
void screen_PLAY();	//游戏界面
void snake_turn_direction();
void snake_move_down();
void snake_move_left();
void snake_move_right();
void snake_move_up();
void snake_turn_up();
void snake_turn_down();
void snake_turn_left();
void snake_turn_right();
void goto_XY(int x, int y);
void snake_born_print();
void snake_move_direction();
void snake_eat_food();
void snake_food_print();
void snake_food_refresh(int i);
void screen_score_display();
void snake_lenth_add();
void snake_eat_food();
void snake_dead_judge();
void GAMERULE();
void game_init();
