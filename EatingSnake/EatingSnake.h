#pragma once
//******************************************
//		
//		̰�������к�������
//
//******************************************


//������ͷλ��
struct snake_head_position
{
	int x;
	int y;

};


//����ʳ��λ��,���ͬʱ����3��ʳ��
struct snake_food_position
{
	int x;
	int y;

};


//*********************��������*********************

//�����ת
void goto_XY(int x, int y);
//��ʼ����
void screen_START();
//��������
void screen_END();
//��Ϸ����
void screen_PLAY();
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