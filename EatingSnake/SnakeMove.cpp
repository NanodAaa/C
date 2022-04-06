//******************************************
//		
//		蛇基于方向的移动及蛇的打印
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


bool snakeaddFlag = FALSE; //蛇身长度增加标志

int SPEED = 500;           //蛇移动速度，初始为 500， 越低越快
int SNAKELENTH = 2;		   //蛇身长度，初始为2
char OLDDIRECTION = LEFT;  //蛇原始运动方向，初始运动方向为 LEFT
char DIRECTION;            //蛇新运动方向


struct snake_head_position HEAD = { 60, 20 };


//*****************打印蛇*****************
void snake_born_print()
{
	//goto_XY(HEAD.x + 1, HEAD.y);
	//printf("*");
	//goto_XY(HEAD.x + 2, HEAD.y);
	//printf("*");

	for (int i = 1; i <= SNAKELENTH; i++)
	{
		goto_XY(HEAD.x + i, HEAD.y);
		printf("*");

	}

}

//*****************蛇头向左运动*****************
void snake_move_left()
{

	//先清除蛇头及蛇尾
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x + SNAKELENTH, HEAD.y);
	SPACEP

	//重新打印蛇头
	HEAD.x--;
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************蛇头向左转向*****************
void snake_turn_left()
{
	if (OLDDIRECTION == UP)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y + SNAKELENTH);
		SPACEP;
		HEAD.x--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		


		Sleep(100);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.x--;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x + 1, HEAD.y);
			STARP;
			goto_XY(HEAD.x + j, HEAD.y + (SNAKELENTH - i));
			SPACEP;

			if(i != SNAKELENTH - 1) Sleep(100);
		}

	}

	else if (OLDDIRECTION == DOWN)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y - SNAKELENTH);
		SPACEP;
		HEAD.x--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(SPEED);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.x--;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x + 1, HEAD.y);
			STARP;
			goto_XY(HEAD.x + j, HEAD.y - (SNAKELENTH - i));
			SPACEP;

			if (i != SNAKELENTH - 1) Sleep(SPEED);
		}

	}

}


//*****************蛇头向右运动*****************
void snake_move_right()
{
	//先清除蛇头及蛇尾
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x - SNAKELENTH, HEAD.y);
	SPACEP

	//重新打印蛇头
	HEAD.x++;
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************蛇头向右转向*****************
void snake_turn_right()
{
	if (OLDDIRECTION == UP)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y + SNAKELENTH);
		SPACEP;
		HEAD.x++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(100);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.x++;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x - 1, HEAD.y);
			STARP;
			goto_XY(HEAD.x - j, HEAD.y + (SNAKELENTH - i));
			SPACEP;

			if (i != SNAKELENTH - 1) Sleep(100);
		}

	}

	else if (OLDDIRECTION == DOWN)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y - SNAKELENTH);
		SPACEP;
		HEAD.x++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(SPEED);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.x++;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x - 1, HEAD.y);
			STARP;
			goto_XY(HEAD.x - j, HEAD.y - (SNAKELENTH - i));
			SPACEP;

			if (i != SNAKELENTH - 1) Sleep(SPEED);
		}

	}

}


//*****************蛇头向上运动*****************
void snake_move_up()
{
	//先清除蛇头及蛇尾
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x, HEAD.y + SNAKELENTH);
	SPACEP

	//重新打印蛇头
	HEAD.y--; //蛇头纵坐标 -1
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************蛇头向上转向*****************
void snake_turn_up()
{
	if (OLDDIRECTION == LEFT)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x + SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(100);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.y--;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x, HEAD.y + 1);
			STARP;
			goto_XY(HEAD.x + (SNAKELENTH - i), HEAD.y + j);
			SPACEP;

			if (i != SNAKELENTH - 1) Sleep(100);
		}

	}

	else if (OLDDIRECTION == RIGHT)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x - SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(SPEED);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.y--;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x, HEAD.y + 1);
			STARP;
			goto_XY(HEAD.x - (SNAKELENTH - i), HEAD.y + j);
			SPACEP;

			if (i != SNAKELENTH - 1) Sleep(SPEED);
		}

	}
}


//*****************蛇头向下运动*****************
void snake_move_down()
{
	//先清除蛇头及蛇尾
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x, HEAD.y - SNAKELENTH);
	SPACEP

	//重新打印蛇头
	HEAD.y++;
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************蛇头向下转向*****************
void snake_turn_down()
{
	if (OLDDIRECTION == LEFT)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x + SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;
		
		snake_eat_food();

		Sleep(100);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.y++;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x, HEAD.y - 1);
			STARP;
			goto_XY(HEAD.x + (SNAKELENTH - i), HEAD.y - j);
			SPACEP;

			if (i != SNAKELENTH - 1) Sleep(100);
		}


	}

	else if (OLDDIRECTION == RIGHT)
	{
		//转向第一帧
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x - SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;
		
		snake_eat_food();

		Sleep(SPEED);

		//转向第 2 及 后面所有帧
		for (int i = 1, j = 2; i < SNAKELENTH; i++, j++)
		{
			HEAD.y++;
			goto_XY(HEAD.x, HEAD.y);
			ATP;
			goto_XY(HEAD.x, HEAD.y - 1);
			STARP;
			goto_XY(HEAD.x - (SNAKELENTH - i), HEAD.y - j);
			SPACEP;

			if (i != SNAKELENTH - 1) Sleep(SPEED);
		}

	}

}


//*****************蛇头运动方向*****************
void snake_move_direction()
{
	switch (OLDDIRECTION)
	{
		case UP:
			snake_move_up();
			break;

		case DOWN:
			snake_move_down();
			break;

		case LEFT:
			snake_move_left();
			break;

		case RIGHT:
			snake_move_right();
			break;
	}
}

//*****************蛇头转向方向*****************
void snake_turn_direction()
{
	//firstFlag = FALSE;
	DIRECTION = _getch();
	switch (DIRECTION)
	{
		case UP:
			//判断蛇头运动方向是否需要转向
			if (OLDDIRECTION == LEFT || OLDDIRECTION == RIGHT)
			{
				snake_turn_up();
				//snake_move_up();

			}
			else
			{
				break;
			}

			break;

		case DOWN:
			//判断蛇头运动方向是否需要转向
			if (OLDDIRECTION == LEFT || OLDDIRECTION == RIGHT)
			{
				snake_turn_down();
				//snake_move_down();
			}
			else
			{
				break;
			}

			break;

		case LEFT:
			//判断蛇头运动方向是否需要转向
			if (OLDDIRECTION == UP || OLDDIRECTION == DOWN)
			{
				snake_turn_left();
				//snake_move_left();
			}
			else
			{
				break;
			}

			break;

		case RIGHT:
			//判断蛇头运动方向是否需要转向
			if (OLDDIRECTION == UP || OLDDIRECTION == DOWN)
			{
				snake_turn_right();
				//snake_move_right();
			}
			else
			{
				break;
			}

			break;

		default:
			break;
	}

	OLDDIRECTION = DIRECTION;
	DIRECTION = NULL;

}


//蛇身增长
void snake_lenth_add()
{
	if (snakeaddFlag == TRUE)
	{
		SNAKELENTH++;

		switch (OLDDIRECTION)
		{
			case UP:
				goto_XY(HEAD.x, HEAD.y + SNAKELENTH);
				STARP;
				break;

			case DOWN:
				goto_XY(HEAD.x, HEAD.y - SNAKELENTH);
				STARP;
				break;

			case LEFT:
				goto_XY(HEAD.x + SNAKELENTH, HEAD.y);
				STARP;
				break;

			case RIGHT:
				goto_XY(HEAD.x - SNAKELENTH, HEAD.y);
				STARP;
				break;

		}

		snakeaddFlag = FALSE; //将标志归位

	}

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







