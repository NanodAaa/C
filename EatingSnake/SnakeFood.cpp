//******************************************
//		
//		ʳ��Ĵ�����
//		����ʳ��Ļ���
//
//******************************************




#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "EatingSnake.h"
#include "conio.h"


#define FOOD1P printf("$");  //��ӡ��ʳ�
#define FOOD2P printf("&");
#define FOOD3P printf("#");


bool foodFlag[3] = {TRUE, FALSE, FALSE};  //��ʼ����ʳ��λ�ò���ӡ�ı�־


int FOODNUMBER = 1;   //ͬʱ���ڵ�ʳ����������ʼΪ 1�� ���Ϊ3�������Ѷȵ���

snake_food_position FOOD[3] = {50, 15};

extern snake_head_position HEAD;
extern int GAMESCORE;
extern bool snakeaddFlag;



//*****************�������ʳ��λ��*****************
void snake_food_refresh(int i)
{
	srand((int)time(NULL));
	FOOD[i].x = rand() % 53 + 20;

	srand((int)time(NULL));
	FOOD[i].y = rand() % 21 + 5;
	
}


//*****************��ӡʳ��*****************
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







