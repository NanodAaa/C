//******************************************
//		
//		蛇基于方向的移动及蛇的打印
//			方案2更多的转向时机
//			转向时可以转向
//
//******************************************

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "EatingSnake.h"
#include "conio.h"

//控制方向键
#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'

#define SPACEP printf(" "); //打印空格
#define STARP  printf("*"); //打印蛇身
#define ATP    printf("@"); //打印蛇头
#define BLOCKP printf("■"); //打印方块

#define LEN sizeof(struct SNAKE)

bool snakeaddFlag = FALSE; //蛇身长度增加标志
int SPEED = 500;           //蛇移动速度，初始为 500， 越低越快
int SNAKELENTH = 2;		   //蛇身长度，初始为2
int LISTLENTH = 0;		   //链表长度，初始为0
char OLDDIRECTION = LEFT;  //蛇原始运动方向，初始运动方向为 LEFT
char DIRECTION;            //蛇新运动方向

//struct snake_head_position HEAD = { 60, 20 }; //储存蛇头坐标，蛇头初始坐标为 {x = 60, y = 20}

//动态链表储存蛇的位置坐标
struct SNAKE
{
	int x;
	int y;
	struct SNAKE* next; //指向下一个节点的指针
};

struct SNAKE* HEAD;
struct SNAKE* PT1;
struct SNAKE* PT2;

//创建蛇蛇头及身体动态链表
struct SNAKE* snake_creat()
{
	//创建头的节点
	if (HEAD == NULL)
	{
		PT1 = PT2 = (struct SNAKE*)malloc(LEN);
		//检测内存分配是否成功
		if (PT1 == NULL || PT2 == NULL)
		{
			printf("创建蛇蛇身体失败！\n");
			return NULL;
		}

		PT1->x = 60;
		PT2->y = 20;
	}

	//根据蛇身长度增加节点
	while (LISTLENTH != SNAKELENTH)
	{
		//把蛇头的节点给到头结点
		if (LISTLENTH == 0){
			HEAD = PT1; //头结点给 HEAD
		}else{
			PT2->next = PT1; //连接前后节点
		}

		PT2 = PT1; //PT1 给到 PT2

		PT1 = (struct SNAKE*)malloc(LEN);
		//检测内存分配是否成功
		if (PT1 == NULL || PT2 == NULL)
		{
			printf("创建蛇蛇身体失败！\n");
			return NULL;
		}

		//根据原始方向为新节点赋予坐标
		switch (OLDDIRECTION)
		{
			case UP:
				PT1->x = PT2->x;
				PT2->y = PT2->y - 1;
				break;

			case DOWN:
				PT1->x = PT2->x;
				PT2->y = PT2->y + 1;
				break;

			case LEFT:
				PT1->x = PT2->x - 1;
				PT2->y = PT2->y;
				break;

			case RIGHT:
				PT1->x = PT2->x + 1;
				PT2->y = PT2->y;
				break;
		}
		LISTLENTH++;
	}
	PT2->next = PT1; //连接最后一个节点	 
	return HEAD;
}


//蛇向左运动函数
void snake_move_left()
{
}


//*****************跳转光标至指定位置*****************
void goto_XY(int x, int y)
{
	// 更新光标位置 
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
	// 隐藏光标 
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	SetConsoleCursorInfo(hOutput, &cursor);
}
