//******************************************
//		
//		游戏界面的显示
//
//******************************************


#include "stdio.h"
#include "EatingSnake.h"
#include "string.h"
#include "windows.h"
#include "stdlib.h"
#include "conio.h"

//游玩空间
#define LEN 50
#define HEI 20;


//外部函数声明
extern snake_head_position HEAD;
extern int SNAKELENTH;
extern char DIFFICULTY[10];


int GAMESCORE = 0;      //储存玩家分数,初始为0
char USERNAME[10];  //储存玩家姓名
char CON_OR_END[20]; //继续或者退出




//*****************开始界面，输入玩家姓名*****************
void screen_START()
{
	system("color 09");

	goto_XY(30, 5);
	printf("***************************************************************");
	goto_XY(30, 25);
	printf("***************************************************************");
	
	system("color 0A");
	goto_XY(25, 15);
	printf("游戏操作说明:");
	goto_XY(25, 16);
	printf("按 w 向上");
	goto_XY(25, 17);
	printf("按 a 向左");
	goto_XY(25, 18);
	printf("按 d 向右");
	goto_XY(25, 19);
	printf("按 s 向下");

	goto_XY(40, 7);
	printf("欢迎游玩《Eating Snake》");
	goto_XY(40, 9);
	printf("请输入你的姓名：");
	goto_XY(58, 9);
	scanf_s("%s", USERNAME, 20);

	printf("\n");

	system("cls"); //清屏

}


//*****************结束界面*****************
void screen_END()
{
	system("cls");

	goto_XY(30, 5);
	printf("*******************************************");
	goto_XY(30, 15);
	printf("*******************************************");
	goto_XY(40, 6);
	printf("游戏结束！");
	goto_XY(40, 7);
	printf("你的分数为：%d", GAMESCORE);

	goto_XY(20, 9);
	printf("输入 start 重新开始游戏");
	goto_XY(20, 10);
	printf("输入 exit 退出游戏");
	goto_XY(45, 10);
	scanf_s("%s", CON_OR_END, 10);
	
	//判断是否继续
	while (1)
	{
		if (strcmp(CON_OR_END, "exit") == 0)
		{
			system("pause");

		}
		else
		{
			break;

		}
		
	}

	printf("\n");

}


//*****************游戏界面*****************
void screen_PLAY()
{
	int hei;

	system("color 9E");

	//游戏界面长坐标为 20~72
	goto_XY(20, 5);
	printf("■■■■■■■■■■");
	printf("■■■■■■■■■■");
	printf("■■■■■■");
	goto_XY(20, 25);
	printf("■■■■■■■■■■");
	printf("■■■■■■■■■■");
	printf("■■■■■■");
	
	//游戏界面宽坐标为 5~25
	for (hei = 0; hei < 20; hei++)
	{
		goto_XY(20, 5 + hei);
		printf("■\n");

	}

	for (hei = 0; hei < 20; hei++)
	{
		goto_XY(70, 5 + hei);
		printf("■\n");

	}

}


//游戏初始化参数
void game_init()
{
	system("color 01"); //设置界面 背景为 黑色， 文字为 蓝色

}


//游戏中得分显示界面
void screen_score_display()
{
	//显示玩家名字
	goto_XY(80, 8);
	printf("玩家：%s", USERNAME);
	
	//显示玩家当前分数
	goto_XY(80, 10);
	printf("当前得分：%d", GAMESCORE);

	//显示蛇蛇长度
	goto_XY(80, 12);
	printf("蛇蛇当前长度：%d", SNAKELENTH);

	//显示当前难度
	goto_XY(80, 14);
	printf("游戏当前难度为：%s", DIFFICULTY);

}


//*****************在蛇头初始位置打印蛇*****************
void snake_born_print()
{
	for (int i = 1; i <= SNAKELENTH; i++)
	{
		goto_XY(HEAD.x + i, HEAD.y);
		printf("*");

	}

}