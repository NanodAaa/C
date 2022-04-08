//******************************************
//		
//		��Ϸ�������ʾ
//
//******************************************


#include "stdio.h"
#include "EatingSnake.h"
#include "string.h"
#include "windows.h"
#include "stdlib.h"
#include "conio.h"

//����ռ�
#define LEN 50
#define HEI 20;


//�ⲿ��������
extern snake_head_position HEAD;
extern int SNAKELENTH;
extern char DIFFICULTY[10];


int GAMESCORE = 0;      //������ҷ���,��ʼΪ0
char USERNAME[10];  //�����������
char CON_OR_END[20]; //���������˳�




//*****************��ʼ���棬�����������*****************
void screen_START()
{
	system("color 09");

	goto_XY(30, 5);
	printf("***************************************************************");
	goto_XY(30, 25);
	printf("***************************************************************");
	
	system("color 0A");
	goto_XY(25, 15);
	printf("��Ϸ����˵��:");
	goto_XY(25, 16);
	printf("�� w ����");
	goto_XY(25, 17);
	printf("�� a ����");
	goto_XY(25, 18);
	printf("�� d ����");
	goto_XY(25, 19);
	printf("�� s ����");

	goto_XY(40, 7);
	printf("��ӭ���桶Eating Snake��");
	goto_XY(40, 9);
	printf("���������������");
	goto_XY(58, 9);
	scanf_s("%s", USERNAME, 20);

	printf("\n");

	system("cls"); //����

}


//*****************��������*****************
void screen_END()
{
	system("cls");

	goto_XY(30, 5);
	printf("*******************************************");
	goto_XY(30, 15);
	printf("*******************************************");
	goto_XY(40, 6);
	printf("��Ϸ������");
	goto_XY(40, 7);
	printf("��ķ���Ϊ��%d", GAMESCORE);

	goto_XY(20, 9);
	printf("���� start ���¿�ʼ��Ϸ");
	goto_XY(20, 10);
	printf("���� exit �˳���Ϸ");
	goto_XY(45, 10);
	scanf_s("%s", CON_OR_END, 10);
	
	//�ж��Ƿ����
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


//*****************��Ϸ����*****************
void screen_PLAY()
{
	int hei;

	system("color 9E");

	//��Ϸ���泤����Ϊ 20~72
	goto_XY(20, 5);
	printf("��������������������");
	printf("��������������������");
	printf("������������");
	goto_XY(20, 25);
	printf("��������������������");
	printf("��������������������");
	printf("������������");
	
	//��Ϸ���������Ϊ 5~25
	for (hei = 0; hei < 20; hei++)
	{
		goto_XY(20, 5 + hei);
		printf("��\n");

	}

	for (hei = 0; hei < 20; hei++)
	{
		goto_XY(70, 5 + hei);
		printf("��\n");

	}

}


//��Ϸ��ʼ������
void game_init()
{
	system("color 01"); //���ý��� ����Ϊ ��ɫ�� ����Ϊ ��ɫ

}


//��Ϸ�е÷���ʾ����
void screen_score_display()
{
	//��ʾ�������
	goto_XY(80, 8);
	printf("��ң�%s", USERNAME);
	
	//��ʾ��ҵ�ǰ����
	goto_XY(80, 10);
	printf("��ǰ�÷֣�%d", GAMESCORE);

	//��ʾ���߳���
	goto_XY(80, 12);
	printf("���ߵ�ǰ���ȣ�%d", SNAKELENTH);

	//��ʾ��ǰ�Ѷ�
	goto_XY(80, 14);
	printf("��Ϸ��ǰ�Ѷ�Ϊ��%s", DIFFICULTY);

}


//*****************����ͷ��ʼλ�ô�ӡ��*****************
void snake_born_print()
{
	for (int i = 1; i <= SNAKELENTH; i++)
	{
		goto_XY(HEAD.x + i, HEAD.y);
		printf("*");

	}

}