//******************************************
//		
//		�߻��ڷ�����ƶ����ߵĴ�ӡ
//
//******************************************



#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "EatingSnake.h"
#include "conio.h"


//���Ʒ����
#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'

#define SPACEP printf(" "); //��ӡ�ո�
#define STARP  printf("*"); //��ӡ����
#define ATP    printf("@"); //��ӡ��ͷ
#define BLOCKP printf("��"); //��ӡ����


bool snakeaddFlag = FALSE; //���������ӱ�־

int SPEED = 500;           //���ƶ��ٶȣ���ʼΪ 500�� Խ��Խ��
int SNAKELENTH = 2;		   //�����ȣ���ʼΪ2
char OLDDIRECTION = LEFT;  //��ԭʼ�˶����򣬳�ʼ�˶�����Ϊ LEFT
char DIRECTION;            //�����˶�����


struct snake_head_position HEAD = { 60, 20 };


//*****************��ӡ��*****************
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

//*****************��ͷ�����˶�*****************
void snake_move_left()
{

	//�������ͷ����β
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x + SNAKELENTH, HEAD.y);
	SPACEP

	//���´�ӡ��ͷ
	HEAD.x--;
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************��ͷ����ת��*****************
void snake_turn_left()
{
	if (OLDDIRECTION == UP)
	{
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y + SNAKELENTH);
		SPACEP;
		HEAD.x--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		


		Sleep(100);

		//ת��� 2 �� ��������֡
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
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y - SNAKELENTH);
		SPACEP;
		HEAD.x--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(SPEED);

		//ת��� 2 �� ��������֡
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


//*****************��ͷ�����˶�*****************
void snake_move_right()
{
	//�������ͷ����β
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x - SNAKELENTH, HEAD.y);
	SPACEP

	//���´�ӡ��ͷ
	HEAD.x++;
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************��ͷ����ת��*****************
void snake_turn_right()
{
	if (OLDDIRECTION == UP)
	{
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y + SNAKELENTH);
		SPACEP;
		HEAD.x++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(100);

		//ת��� 2 �� ��������֡
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
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x, HEAD.y - SNAKELENTH);
		SPACEP;
		HEAD.x++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(SPEED);

		//ת��� 2 �� ��������֡
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


//*****************��ͷ�����˶�*****************
void snake_move_up()
{
	//�������ͷ����β
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x, HEAD.y + SNAKELENTH);
	SPACEP

	//���´�ӡ��ͷ
	HEAD.y--; //��ͷ������ -1
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************��ͷ����ת��*****************
void snake_turn_up()
{
	if (OLDDIRECTION == LEFT)
	{
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x + SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(100);

		//ת��� 2 �� ��������֡
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
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x - SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y--;
		goto_XY(HEAD.x, HEAD.y);
		ATP;

		snake_eat_food();

		Sleep(SPEED);

		//ת��� 2 �� ��������֡
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


//*****************��ͷ�����˶�*****************
void snake_move_down()
{
	//�������ͷ����β
	goto_XY(HEAD.x, HEAD.y);
	STARP
	goto_XY(HEAD.x, HEAD.y - SNAKELENTH);
	SPACEP

	//���´�ӡ��ͷ
	HEAD.y++;
	goto_XY(HEAD.x, HEAD.y);
	ATP

}


//*****************��ͷ����ת��*****************
void snake_turn_down()
{
	if (OLDDIRECTION == LEFT)
	{
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x + SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;
		
		snake_eat_food();

		Sleep(100);

		//ת��� 2 �� ��������֡
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
		//ת���һ֡
		goto_XY(HEAD.x, HEAD.y);
		STARP;
		goto_XY(HEAD.x - SNAKELENTH, HEAD.y);
		SPACEP;
		HEAD.y++;
		goto_XY(HEAD.x, HEAD.y);
		ATP;
		
		snake_eat_food();

		Sleep(SPEED);

		//ת��� 2 �� ��������֡
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


//*****************��ͷ�˶�����*****************
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

//*****************��ͷת����*****************
void snake_turn_direction()
{
	//firstFlag = FALSE;
	DIRECTION = _getch();
	switch (DIRECTION)
	{
		case UP:
			//�ж���ͷ�˶������Ƿ���Ҫת��
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
			//�ж���ͷ�˶������Ƿ���Ҫת��
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
			//�ж���ͷ�˶������Ƿ���Ҫת��
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
			//�ж���ͷ�˶������Ƿ���Ҫת��
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


//��������
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

		snakeaddFlag = FALSE; //����־��λ

	}

}





//*****************��ת�����ָ��λ��*****************
void goto_XY(int x, int y)
{
	// ���¹��λ�� 
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
	// ���ع�� 
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	SetConsoleCursorInfo(hOutput, &cursor);
}







