//******************************************
//		
//		游戏难度设置
//		难度在游戏内的变化
//
//******************************************


#define _CRT_SECURE_NO_WARNINGS


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "EatingSnake.h"
#include "conio.h"

//#define _CRT_SECURE_NO_WARNINGS 1

char DIFFICULTY[10] = "BABY";
bool deadFlag = FALSE;



extern int GAMESCORE;
extern int SPEED;
extern snake_head_position HEAD;
extern snake_food_position FOOD[3];
extern bool snakeaddFlag;
extern bool foodFlag[3];
extern int FOODNUMBER;


//蛇蛇速度变化
void snake_speed_setting()
{
	if (GAMESCORE == 5)
	{
		SPEED = 400;
		strcpy(DIFFICULTY, "EASY");

	}
	if (GAMESCORE == 10)
	{
		SPEED = 300;
		strcpy(DIFFICULTY, "MODERATE");

	}
	if (GAMESCORE == 15)
	{
		SPEED = 200;
		strcpy(DIFFICULTY, "DIFFICULT");
	}
	if (GAMESCORE == 20)
	{
		SPEED = 100;
		strcpy(DIFFICULTY, "!!ULTRA!!");
	}
}


//*****************撞墙死亡判定*****************
void snake_dead_judge()
{
	if (HEAD.x > 69 || HEAD.x < 22 || HEAD.y > 24 || HEAD.y < 6)
	{
		deadFlag = TRUE;

	}
}


//*****************判断蛇吃到食物*****************
void snake_eat_food()
{
	//蛇吃到食物就打开食物生成打印标志
	for (int i = 0; i < FOODNUMBER; i++)
	{
		if (HEAD.x == FOOD[i].x && HEAD.y == FOOD[i].y)
		{
			foodFlag[i] = TRUE;

			GAMESCORE++;
			snakeaddFlag = TRUE;
			
			snake_food_refresh(i);
			snake_food_print();
		}
	}
}


void GAMERULE()
{
	snake_dead_judge();
	snake_eat_food();
	snake_lenth_add();
}