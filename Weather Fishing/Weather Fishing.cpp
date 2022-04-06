#include<stdio.h>
#include<stdlib.h>
#include "time.h"
#include "string.h"

struct DATE
{
	int YEAR;
	int MONTH;
	int DAY;
};

struct DATE dtBegin;

char g_DATE[20]; //用于判断的日期 
char s_DATE[3][5]; //存放日、月、年 

//输入日期，存入字符 
void date_input()
{
	int i = 0, j = 0, k = 0;

//	sprintf_s(g_DATE, "2000/02/01", 20);
	scanf_s("%s", g_DATE, 10); //输入用于判断的日期 

	//分别储存 g_DATE 中的日期到 s_DATE 
	while (g_DATE[i] != '\0')
	{
		//遇到 '/' 跳过 
		if (g_DATE[i] != '/')
		{
			s_DATE[j][k] = g_DATE[i]; //分别存储 年月日
			i++;
			k++;
		}
		else
		{
			s_DATE[j][k] = '\0';
			i++;
			j++;
			k = 0;
		}
	}
}

int main()
{
	int i, j;

	//输入日期存入字符 
	date_input();

	//判断日期是否合法（不合法结束） "自己写" 



//计算经过天数总和 
	
	tm tmStart, tmSave;

	//清零 tmStart tmSave
	memset(&tmStart, 0, sizeof(tm));
	memset(&tmSave, 0, sizeof(tm));

	//开始的日期
	tmStart.tm_year = 2000 - 1900;
	tmStart.tm_mon = 1 - 1;
	tmStart.tm_mday = 1;

	//储存的日期
	tmSave.tm_year = atoi(s_DATE[0]) - 1900;
	tmSave.tm_mon = atoi(s_DATE[1]) - 1;
	tmSave.tm_mday = atoi(s_DATE[2]);

	time_t ttStart, ttSave;

	ttStart = mktime(&tmStart);
	ttSave = mktime(&tmSave);

	double fSecond = difftime(ttSave, ttStart); //计算自 2001/1/1 经过秒数
	int nDay = fSecond / (3600 * 24);			//秒数转换为天数



	//判断是否钓鱼 
	
	int tDay = nDay % 5;
	if (tDay >= 1 && tDay <= 3)
	{
		printf("fishing");
	}

	else
	{
		printf("No fishing");
	}

	printf("\n");

	system("pause");

	return 0;
}