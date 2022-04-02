/*
				动态链表管理
		增加
		删除
		修改
		查找
		覆盖
		插入
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "LinkedlistAndFunction.h"

#define LEN sizeof(struct Student)

struct Student* g_head;  //链表头
struct Student* g_pt1;   //节点头   
struct Student* g_pt2;   //节点尾
struct Student* g_pt;    //用于调用函数的指针
struct Student_s* g_save;

int g_n = 0;
int g_people = 0;


//增加新的学生
struct Student* add()
{
	printf("这是新增学生程序，输入“0 0 0 0”即可结束新增！\n");

	//创建动态链表，输入 “0 0 0 0” 结束，第1个节点
	if (g_head == NULL)
	{
		g_pt1 = g_pt2 = (struct Student*)malloc(LEN); //开辟内存空间，开辟一个新节点
		//判断内存分配是否成功
		if (g_pt1 == NULL || g_pt2 == NULL)
		{
			printf("内存分配不成功!\n");

			return NULL;

		}

		printf("请输入学号以及三科成绩： ");
		scanf_s("%d %f %f %f", &g_pt1->num, &g_pt1->chinese, &g_pt1->math, &g_pt1->english); //输入学号及三科成绩输入学号及三科成绩
		g_people++;

	}

	//第2个节点及以上
	while (1)
	{
		g_n++;

		//判断当前是否为第1个节点
		if (g_n == 1)
		{
			g_head = g_pt1; //如果是第1个节点，将链表头赋给 head

		}
		else
		{
			g_pt2->next = g_pt1;  //如果不是，将新节点的头赋给 p1，连接pt1 和 pt2 的节点

		}

		g_pt2 = g_pt1; //将p2转移到新节点

		g_pt1 = (struct Student*)malloc(LEN); //开辟新节点
		//判断内存分配是否成功
		if (g_pt1 == NULL)
		{
			printf("内存分配不成功！\n");

			return NULL;

		}

		printf("请输入学号以及三科成绩： ");
		scanf_s("%d %f %f %f", &g_pt1->num, &g_pt1->chinese, &g_pt1->math, &g_pt1->english); //输入学号及三科成绩
		g_people++;

		//判断是否结束新增节点
		if (g_pt1->num == 0)
		{
			free(g_pt1); //删除用判断终止新增的节点

			g_pt1 = g_pt2; //将 pt1 后移至链表尾
			g_pt2->next = NULL; //将链表尾后的一个空节点设为 NULL
			g_people--;

			return g_head;

		}

	};

	g_pt2->next = NULL; //将链表尾后的一个空节点设为 NULL

	return g_head;

}


//删除某个学生的成绩
struct Student* del()
{
	struct Student* ptp;
	struct Student* ptq;
	int num;

	printf("请输入需要删除的学生的学号：");
	scanf_s("%d", &num);
	printf("\n");

	ptp = g_head;

	//删除第一个节点
	if (num == 1)
	{
		g_head = ptp->next; //将头指针赋给第2个节点

		printf("已删除学号为 %d 的学生！\n", ptp->num);
		printf("学生的语文成绩为：%.1f\n", ptp->chinese);
		printf("学生的数学成绩为：%.1f\n", ptp->math);
		printf("学生的英语成绩为：%.1f\n", ptp->english);

		free(ptp); //删除第1个节点
		g_people--;

	}

	//删除第2个及以后的节点
	else
	{
		//寻找学号为 num 的学生
		while (ptp->num != (num-1))
		{
			ptp = ptp->next; //结点后移

		}
		
		ptq = ptp->next; //让 ptq 指向待删除的节点

		printf("已删除学号为 %d 的学生！\n", ptq->num);
		printf("学生的语文成绩为：%.1f\n", ptq->chinese);
		printf("学生的数学成绩为：%.1f\n", ptq->math);
		printf("学生的英语成绩为：%.1f\n", ptq->english);

		ptp->next = ptp->next; //跳过待删除的节点

		free(ptq); //删除节点
		
		g_people--; //人数-1
		
	}

	return g_head; //返回头结点

}


//********************修改某个学生的成绩*******************
struct Student* modify()
{
	struct Student* ptp;
	float cn, math, eng;
	int i = 0;
	int num;

	ptp = g_head;
	printf("请输入要修改的学生的学号：\n");
	scanf_s("%d", &num);

	//查找要修改的学生
	while (ptp->num != num)
	{
		//到达链表尾，中断查找
		if (ptp->next == NULL)
		{
			printf("未找到该学号对应的学生！");

			return NULL; //中断该函数

		}

		ptp = ptp->next;
		i++;

	}

	printf("请输入要修改的成绩（语文、数学、英语）：\n");
	scanf_s("%f %f %f", &cn, &math, &eng);
	printf("\n");

	//修改成绩
	ptp->chinese = cn;
	ptp->math = math;
	ptp->english = eng;

	//输出成绩
	printf("学号为 %d 的学生的成绩已修改为：\n", ptp->num);
	printf("语文：%.1f\n", ptp->chinese);
	printf("数学：%.1f\n", ptp->math);
	printf("英语：%.1f\n", ptp->english);
	printf("\n");

	return g_head;

}


//****************查找学生成绩*******************
struct Student* search()
{
	struct Student* ptp;
	int num;

	ptp = g_head;
	printf("请输入要查找的学生的学号：");
	scanf_s("%d", &num);
	printf("\n");

	//寻找相同的学号
	while (ptp->num != num)
	{
		//到达链表尾，中断查找
		if (ptp->next == NULL)
		{
			printf("未找到该学号对应的学生！");

			return NULL; //中断该函数

		}

		ptp = ptp->next; //ptp后移

	}

	//输出对应学号的学生的学号及成绩
	printf("学生的学号为：%d\n", ptp->num);
	printf("学生的语文成绩为：%.1f\n", ptp->chinese);
	printf("学生的数学成绩为：%.1f\n", ptp->math);
	printf("学生的英语成绩为：%.1f\n", ptp->english);

	return NULL;

}


//*****************插入成绩*******************
struct Student* insert()
{
	struct Student* ptp;
	struct Student* pts;
	int x;
	int i = 1;

	printf("请输入要插入的位置：");
	scanf_s("%d", &x);
	printf("\n");

	ptp = g_head;

	pts = (struct Student*)malloc(LEN); //创建新的节点
	//检查内存分配是否成功
	if (pts == NULL)
	{
		printf("内存分配不成功!\n");
		return NULL;
	}

	printf("请输入要插入的数据：");
	scanf_s("%d %f %f %f", &pts->num, &pts->chinese, &pts->math, &pts->english);
	printf("\n");

	//插入到第1个节点
	if (x == 1)
	{
		pts->next = g_head;

	}

	//插入在第2个及以上的节点
	else
	{
		while (ptp && i < x-1) //ptp指向 x-1个节点的 next
		{
			ptp = ptp->next;
			i++;

		}

		pts->next = ptp->next; //
		ptp->next = pts; //把s赋值给p的下一个结点

	}

	printf("插入的学号为 %d 的学生的数据为：\n", pts->num);
	printf("语文成绩为：%.1f\n", pts->chinese);
	printf("数学成绩为：%.1f\n", pts->math);
	printf("英语成绩为：%.1f\n", pts->english);

	g_people++;

	return g_head; //返回指针

}

//********************输出全部学生的成绩**************************
struct Student* print_all()
{
	bool breakflag = false;
	struct Student* ptp;

	ptp = g_head;

	printf("系统中共有 %d 名学生的记录！\n", g_people);
	//如果系统中学生数量为 0 ，中断输出
	if (g_people == 0)
	{
		return NULL;

	}

	//按链表顺序逐个输出学生的成绩
	while (1)
	{
		//如果ptp下一个节点，退出查找
		if (breakflag == true)
		{
			break;

		}

		printf("学号为 %d 的学生的成绩为：\n", ptp->num);
		printf("语文 %.1f\n", ptp->chinese);
		printf("数学 %.1f\n", ptp->math);
		printf("英语 %.1f\n", ptp->english);
		printf("\n\n");

		
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp后移

		}

	}

	printf("\n");
	printf("所有学生成绩输出完毕！\n");

	return NULL;

}