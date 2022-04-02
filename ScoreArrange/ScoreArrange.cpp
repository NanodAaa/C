/*
*		学生成绩管理系统
*			至高30名学生
*
*
*/

#include "stdio.h"
#include "stdlib.h" 
#include "string.h"
#include "LinkedlistAndFunction.h"

#define LEN sizeof(struct Student)

float g_score;    //储存各个分数
char g_function[10]; //功能
extern struct Student* g_pt;

//函数声明
void screen_menu();
void function_jump();


//主函数
int main()
{
	char GO[10];
	GO[9] = '/0';

	printf("	<<<<<学生程序管理系统>>>>>\n");
	printf("	Powered by NanodAaa\n");
	printf("*********************************************\n");

	//启动时输入学生信息
	g_pt = add();


	//主循环
	while (1)
	{
		memset(g_function, '/0', sizeof(g_function)); //清零 g_function
		
		//菜单
		screen_menu();

		//跳转到功能
		function_jump();

		//判断是否结束
		printf("是否继续查询？ 如继续请输入任意文字，如要退出请输入 exit\n ");
		printf("请输入：");
		scanf_s("%s", GO, 10);
		printf("\n");

		if (strcmp(GO, "exit") == 0)
		{
			return NULL;

		}

	}

}


//屏幕菜单
void screen_menu()
{
	printf("\n");
	printf("*********************************************\n");

	printf("功能英文代号如下：\n");
	printf("输入 add	增加成绩\n");
	printf("输入 del	删除成绩\n");
	printf("输入 modify     修改成绩\n");
	printf("输入 cover      覆盖学生成绩\n");
	printf("输入 search     查找成绩\n");
	printf("输入 insert     插入成绩\n");
	printf("输入 total	  查找总分\n");
	printf("输入 avg	查找平均分\n");
	printf("输入 max	查找最高分\n");
	printf("输入 min	查找最低分\n");
	printf("输入 print      输出所有学生的成绩\n");

	printf("*********************************************\n");

	printf("\n");
	printf("请输入要使用的功能的英文代号：");
	scanf_s("   %s", g_function, 10); //输入要使用的功能
	printf("\n");

}


//跳转到相关功能
void function_jump()
{
	if (strcmp(g_function, "add") == 0)
	{
		printf("\n");
		printf("正在执行功能 “add”......\n\n");
		g_pt = add();
	}
	else if (strcmp(g_function, "del") == 0)
	{
		printf("\n");
		printf("正在执行功能 “del”......\n\n");
		g_pt = del();
	}
	else if (strcmp(g_function,  "modify") == 0)
	{
		printf("\n");
		printf("正在执行功能 “modify”......\n\n");
		g_pt = modify();
	}
	else if (strcmp(g_function, "search") == 0)
	{
		printf("\n");
		printf("正在执行功能 “search”......\n\n");
		g_pt = search();
	}
	else if (strcmp(g_function, "insert") == 0)
	{
		printf("\n");
		printf("正在执行功能 “insert”......\n\n");
		g_pt = insert();
	}
	else if (strcmp(g_function, "total") == 0)
	{
		printf("\n");
		printf("正在执行功能 “total”......\n\n");
		g_score = total_score();
	}
	else if (strcmp(g_function, "avg") == 0)
	{
		printf("\n");
		printf("正在执行功能 “avg”......\n\n");
		g_score = avg_score();
	}
	else if (strcmp(g_function, "max") == 0)
	{
		printf("\n");
		printf("正在执行功能 “max”......\n\n");
		g_score = max_score();
	}
	else if (strcmp(g_function, "min") == 0)
	{
		printf("\n");
		printf("正在执行功能 “min”......\n\n");
		g_score = min_score();
	}
	else if (strcmp(g_function, "print") == 0)
	{
		printf("\n");
		printf("正在执行功能 “print”......\n\n");
		g_pt = print_all();
	}
	else
	{
		printf("功能代号有误，请检查后重新输入!\n");
	}

	printf("\n");
	printf("已完成该功能，现在返回菜单\n");
	printf("\n");
	printf("***************************************\n");

}