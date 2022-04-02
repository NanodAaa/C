/*
				系统功能管理
		总分
		平均分
		最高分
		最低分
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "LinkedlistAndFunction.h"

extern struct Student* g_head;
extern int g_people;


//计算某学生总分
float total_score()
{
	struct Student* ptp;
	float score;
	int num;

	ptp = g_head;

	printf("请输入要查询的学生的学号：");
	scanf_s("%d", &num);
	printf("\n");

	//查找目标学生
	while (ptp->num != num)
	{
		if (ptp->next == NULL)
		{
			printf("未找到该学生，请检查学号输入是否有误！\n");
			
			return NULL;

		}

		ptp = ptp->next; //ptp后移
	}

	score = ptp->chinese + ptp->math + ptp->english; //计算总分
	printf("学生 %d 各科的总分为：%.1f\n", ptp->num, score);

	return NULL;

}


//计算单科平均分
float avg_score()
{
	bool breakflag = false;
	struct Student* ptp;
	float score = 0.0;
	char subject[10]; //科目字符串
	subject[9] = '\0';

	ptp = g_head;

	printf("请输入要计算的科目（如“chinese”、“math”、“english”）：");
	scanf_s("%s", subject, 20);
	printf("\n");
	
	//查找学生并计算某科目分数的总和
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
				printf("输入有误，请检查后重新输入！\n");

				return NULL;

			}

		}

		//如果ptp下一个节点，退出查找
		if (breakflag == true)
		{
			score /= g_people;
			printf("科目 %s 的平均分为：%.1f\n", subject, score);

			break;

		}
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp后移

		}

	}

	return NULL;

}


//计算单科最高分
float max_score()
{
	bool breakflag = false;
	float score = 0.0; //存储最高分
	struct Student* ptp;
	char subject[10]; //科目字符串
	subject[9] = '\0';

	ptp = g_head;

	printf("请输入要计算的科目（如“chinese”、“math”、“english”）：");
	scanf_s("%s", subject, 20);
	printf("\n");
	
	//按科目查找最高分
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
				printf("输入有误，请检查后重新输入！\n");

				return NULL;

			}
		}

		//如果ptp下一个节点，退出查找
		if (breakflag == true)
		{
			printf("科目 %s 的最高分为 学生：%d 分数为：%.1f\n", subject, ptp->num, score);

			break;
		}
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp后移

		}
		
	}

	return NULL;

}


//计算单科最低分
float min_score()
{
	bool breakflag = false;
	float score = 0.0; //存储最低分
	struct Student* ptp;
	char subject[10]; //科目字符串
	subject[9] = '\0';

	ptp = g_head;

	printf("请输入要计算的科目（如“chinese”、“math”、“english”）：\n");
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
				printf("输入有误，请检查后重新输入！\n");

				return NULL;

			}
		}

		//如果ptp下一个节点，退出查找
		if (breakflag == true)
		{
			printf("科目 %s 的最低分为 学生：%d 分数为：%.1f\n", subject, ptp->num, score);

			break;
		}
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp后移

		}

	}

	return NULL;

}