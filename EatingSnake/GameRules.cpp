//******************************************
//		
//		游戏难度设置
//		难度在游戏内的变化
//		NanodAaa 2023/12/24
//******************************************

#define _CRT_SECURE_NO_WARNINGS //消除危险警告

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "EatingSnake.h"
#include "conio.h"

//外部函数声明
extern int GAMESCORE;
extern int SPEED;
extern snake_head_position HEAD;
extern snake_food_position FOOD[3];
extern bool snakeaddFlag;
extern bool foodFlag[3];
extern int FOODNUMBER;

char DIFFICULTY[10] = "BABY"; //储存游戏难度
bool deadFlag = FALSE;        //死亡标志


//蛇蛇速度变化
void snake_speed_setting()
{
	//根据当前游戏分数改变蛇蛇速度
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
		deadFlag = TRUE; //超出游戏界面送出死亡标志
	}
}


//*****************判断蛇吃到食物*****************
void snake_eat_food()
{
	//蛇吃到食物就打开食物生成打印标志
	for (int i = 0; i < FOODNUMBER; i++)
	{
		//判断蛇蛇吃到食物
		if (HEAD.x == FOOD[i].x && HEAD.y == FOOD[i].y)
		{
			foodFlag[i] = TRUE; //送出食物 i 打印标志

			GAMESCORE++;        //得分 +1
			snakeaddFlag = TRUE; //送出蛇蛇增长标志
			
			//重新打印吃掉的食物
			snake_food_refresh(i); 
			snake_food_print();
		}
	}
}


//*****************游戏规则*****************
void GAMERULE()
{
	snake_dead_judge(); //死亡判定
	snake_eat_food(); //吃到食物判定
	snake_lenth_add(); //蛇蛇增长判定

}
