//******************************************
//		
//		��Ϸ�Ѷ�����
//		�Ѷ�����Ϸ�ڵı仯
//
//******************************************


#define _CRT_SECURE_NO_WARNINGS //����Σ�վ���

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "EatingSnake.h"
#include "conio.h"


//�ⲿ��������
extern int GAMESCORE;
extern int SPEED;
extern snake_head_position HEAD;
extern snake_food_position FOOD[3];
extern bool snakeaddFlag;
extern bool foodFlag[3];
extern int FOODNUMBER;


char DIFFICULTY[10] = "BABY"; //������Ϸ�Ѷ�
bool deadFlag = FALSE;        //������־


//�����ٶȱ仯
void snake_speed_setting()
{
	//���ݵ�ǰ��Ϸ�����ı������ٶ�
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


//*****************ײǽ�����ж�*****************
void snake_dead_judge()
{
	if (HEAD.x > 69 || HEAD.x < 22 || HEAD.y > 24 || HEAD.y < 6)
	{
		deadFlag = TRUE; //������Ϸ�����ͳ�������־

	}

}


//*****************�ж��߳Ե�ʳ��*****************
void snake_eat_food()
{
	//�߳Ե�ʳ��ʹ�ʳ�����ɴ�ӡ��־
	for (int i = 0; i < FOODNUMBER; i++)
	{
		//�ж����߳Ե�ʳ��
		if (HEAD.x == FOOD[i].x && HEAD.y == FOOD[i].y)
		{
			foodFlag[i] = TRUE; //�ͳ�ʳ�� i ��ӡ��־

			GAMESCORE++;        //�÷� +1
			snakeaddFlag = TRUE; //�ͳ�����������־
			
			//���´�ӡ�Ե���ʳ��
			snake_food_refresh(i); 
			snake_food_print();

		}

	}

}


//*****************��Ϸ����*****************
void GAMERULE()
{
	snake_dead_judge(); //�����ж�
	snake_eat_food(); //�Ե�ʳ���ж�
	snake_lenth_add(); //���������ж�

}