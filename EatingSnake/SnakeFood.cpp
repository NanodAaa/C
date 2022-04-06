//******************************************
//		
//		食物的创建及
//		蛇与食物的互动
//
//******************************************




#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "EatingSnake.h"
#include "conio.h"


#define FOOD1P printf("$");  //打印“食物”
#define FOOD2P printf("&");
#define FOOD3P printf("#");


bool foodFlag[3] = {TRUE, FALSE, FALSE};  //开始生成食物位置并打印的标志


int FOODNUMBER = 1;   //同时存在的食物数量，初始为 1， 最大为3，依据难度调整

snake_food_position FOOD[3] = {50, 15};

extern snake_head_position HEAD;
extern int GAMESCORE;
extern bool snakeaddFlag;



//*****************随机生成食物位置*****************
void snake_food_refresh(int i)
{
	srand((int)time(NULL));
	FOOD[i].x = rand() % 53 + 20;

	srand((int)time(NULL));
	FOOD[i].y = rand() % 21 + 5;
	
}


//*****************打印食物*****************
void snake_food_print()
{
	if (foodFlag[0] == TRUE)
	{
		goto_XY(FOOD[0].x, FOOD[0].y);
		FOOD1P;
		foodFlag[0] = FALSE;

	}
	if (foodFlag[1] == TRUE)
	{
		goto_XY(FOOD[1].x, FOOD[1].y);
		FOOD2P;
	}
	if (foodFlag[2] == TRUE)
	{
		goto_XY(FOOD[2].x, FOOD[2].y);
		FOOD3P;
	}

}







