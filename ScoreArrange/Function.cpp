/*
				ϵͳ���ܹ���
		�ܷ�
		ƽ����
		��߷�
		��ͷ�
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "LinkedlistAndFunction.h"

extern struct Student* g_head;
extern int g_people;


//����ĳѧ���ܷ�
float total_score()
{
	struct Student* ptp;
	float score;
	int num;

	ptp = g_head;

	printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
	scanf_s("%d", &num);
	printf("\n");

	//����Ŀ��ѧ��
	while (ptp->num != num)
	{
		if (ptp->next == NULL)
		{
			printf("δ�ҵ���ѧ��������ѧ�������Ƿ�����\n");
			
			return NULL;

		}

		ptp = ptp->next; //ptp����
	}

	score = ptp->chinese + ptp->math + ptp->english; //�����ܷ�
	printf("ѧ�� %d ���Ƶ��ܷ�Ϊ��%.1f\n", ptp->num, score);

	return NULL;

}


//���㵥��ƽ����
float avg_score()
{
	bool breakflag = false;
	struct Student* ptp;
	float score = 0.0;
	char subject[10]; //��Ŀ�ַ���
	subject[9] = '\0';

	ptp = g_head;

	printf("������Ҫ����Ŀ�Ŀ���硰chinese������math������english������");
	scanf_s("%s", subject, 20);
	printf("\n");
	
	//����ѧ��������ĳ��Ŀ�������ܺ�
	while (1)
	{
		if (breakflag == false)
		{
			if (strcmp(subject, "chinese") == 0)
			{
				score += ptp->chinese;

			}

			else if (strcmp(subject, "math") == 0)
			{
				score += ptp->math;

			}

			else if (strcmp(subject, "english") == 0)
			{
				score += ptp->english;

			}
			else
			{
				printf("��������������������룡\n");

				return NULL;

			}

		}

		//���ptp��һ���ڵ㣬�˳�����
		if (breakflag == true)
		{
			score /= g_people;
			printf("��Ŀ %s ��ƽ����Ϊ��%.1f\n", subject, score);

			break;

		}
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp����

		}

	}

	return NULL;

}


//���㵥����߷�
float max_score()
{
	bool breakflag = false;
	float score = 0.0; //�洢��߷�
	struct Student* ptp;
	char subject[10]; //��Ŀ�ַ���
	subject[9] = '\0';

	ptp = g_head;

	printf("������Ҫ����Ŀ�Ŀ���硰chinese������math������english������");
	scanf_s("%s", subject, 20);
	printf("\n");
	
	//����Ŀ������߷�
	while (1)
	{
		if (breakflag == false)
		{
			if (strcmp(subject, "chinese") == 0)
			{
				if (score < ptp->chinese)
					score = ptp->chinese;

			}

			else if (strcmp(subject, "math") == 0)
			{
				if (score < ptp->math)
					score = ptp->math;

			}

			else if (strcmp(subject, "english") == 0)
			{
				if (score < ptp->english)
					score = ptp->english;

			}
			else
			{
				printf("��������������������룡\n");

				return NULL;

			}
		}

		//���ptp��һ���ڵ㣬�˳�����
		if (breakflag == true)
		{
			printf("��Ŀ %s ����߷�Ϊ ѧ����%d ����Ϊ��%.1f\n", subject, ptp->num, score);

			break;
		}
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp����

		}
		
	}

	return NULL;

}


//���㵥����ͷ�
float min_score()
{
	bool breakflag = false;
	float score = 0.0; //�洢��ͷ�
	struct Student* ptp;
	char subject[10]; //��Ŀ�ַ���
	subject[9] = '\0';

	ptp = g_head;

	printf("������Ҫ����Ŀ�Ŀ���硰chinese������math������english������\n");
	scanf_s("%s", subject, 20);
	

	while (1)
	{
		if (breakflag == false)
		{
			if (strcmp(subject, "chinese") == 0)
			{
				if (score > ptp->chinese)
					score = ptp->chinese;

			}

			else if (strcmp(subject, "math") == 0)
			{
				if (score > ptp->math)
					score = ptp->math;

			}

			else if (strcmp(subject, "english") == 0)
			{
				if (score > ptp->english)
					score = ptp->english;

			}
			else
			{
				printf("��������������������룡\n");

				return NULL;

			}
		}

		//���ptp��һ���ڵ㣬�˳�����
		if (breakflag == true)
		{
			printf("��Ŀ %s ����ͷ�Ϊ ѧ����%d ����Ϊ��%.1f\n", subject, ptp->num, score);

			break;
		}
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp����

		}

	}

	return NULL;

}