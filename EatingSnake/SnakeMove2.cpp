//******************************************
//		
//		�߻��ڷ�����ƶ����ߵĴ�ӡ
//			����2�����ת��ʱ��
//			ת��ʱ����ת��
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

#define LEN sizeof(struct SNAKE)


bool snakeaddFlag = FALSE; //���������ӱ�־
int SPEED = 500;           //���ƶ��ٶȣ���ʼΪ 500�� Խ��Խ��
int SNAKELENTH = 2;		   //�����ȣ���ʼΪ2
int LISTLENTH = 0;		   //�����ȣ���ʼΪ0
char OLDDIRECTION = LEFT;  //��ԭʼ�˶����򣬳�ʼ�˶�����Ϊ LEFT
char DIRECTION;            //�����˶�����

//struct snake_head_position HEAD = { 60, 20 }; //������ͷ���꣬��ͷ��ʼ����Ϊ {x = 60, y = 20}


//��̬�������ߵ�λ������
struct SNAKE
{
	int x;
	int y;
	struct SNAKE* next; //ָ����һ���ڵ��ָ��
};

struct SNAKE* HEAD;
struct SNAKE* PT1;
struct SNAKE* PT2;



//��������ͷ�����嶯̬����
struct SNAKE* snake_creat()
{

	//����ͷ�Ľڵ�
	if (HEAD == NULL)
	{
		PT1 = PT2 = (struct SNAKE*)malloc(LEN);
		//����ڴ�����Ƿ�ɹ�
		if (PT1 == NULL || PT2 == NULL)
		{
			printf("������������ʧ�ܣ�\n");

			return NULL;

		}

		PT1->x = 60;
		PT2->y = 20;

	}

	//�������������ӽڵ�
	while (LISTLENTH != SNAKELENTH)
	{
		//����ͷ�Ľڵ����ͷ���
		if (LISTLENTH == 0)
		{
			HEAD = PT1; //ͷ���� HEAD
		}
		else
		{
			PT2->next = PT1; //����ǰ��ڵ�
		}

		PT2 = PT1; //PT1 ���� PT2

		PT1 = (struct SNAKE*)malloc(LEN);
		//����ڴ�����Ƿ�ɹ�
		if (PT1 == NULL || PT2 == NULL)
		{
			printf("������������ʧ�ܣ�\n");

			return NULL;

		}

		//����ԭʼ����Ϊ�½ڵ㸳������
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

	PT2->next = PT1; //�������һ���ڵ�
	 
	return HEAD;

}


//�������˶�����
void snake_move_left()
{

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
