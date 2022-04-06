#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "windows.h"
#include "time.h"
#include "EatingSnake.h"


bool firstFlag = TRUE;
bool endFlag = FALSE;

extern int SPEED;
extern int GAMESCORE;
extern char DIRECTION;
extern bool deadFlag;


int main()
{
	
	screen_START(); //开始界面



	screen_PLAY(); //游戏界面
	snake_food_print(); //生成食物1
	snake_born_print(); //生成蛇
	
	while (1)
	{
		
		

		snake_move_direction(); //蛇蛇移动指令

		//检测按键按下，进入蛇头转向程序
		if(_kbhit())
		{
			snake_turn_direction();
		}


		screen_score_display(); //显示玩家分数
		GAMERULE();             //游戏规则


		//死亡判定
		if (deadFlag == TRUE)
		{
			screen_END();
		}


		Sleep(SPEED);

	}


	

}



