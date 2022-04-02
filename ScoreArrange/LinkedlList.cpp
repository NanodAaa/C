/*
				��̬�������
		����
		ɾ��
		�޸�
		����
		����
		����
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "LinkedlistAndFunction.h"

#define LEN sizeof(struct Student)

struct Student* g_head;  //����ͷ
struct Student* g_pt1;   //�ڵ�ͷ   
struct Student* g_pt2;   //�ڵ�β
struct Student* g_pt;    //���ڵ��ú�����ָ��
struct Student_s* g_save;

int g_n = 0;
int g_people = 0;


//�����µ�ѧ��
struct Student* add()
{
	printf("��������ѧ���������롰0 0 0 0�����ɽ���������\n");

	//������̬�������� ��0 0 0 0�� ��������1���ڵ�
	if (g_head == NULL)
	{
		g_pt1 = g_pt2 = (struct Student*)malloc(LEN); //�����ڴ�ռ䣬����һ���½ڵ�
		//�ж��ڴ�����Ƿ�ɹ�
		if (g_pt1 == NULL || g_pt2 == NULL)
		{
			printf("�ڴ���䲻�ɹ�!\n");

			return NULL;

		}

		printf("������ѧ���Լ����Ƴɼ��� ");
		scanf_s("%d %f %f %f", &g_pt1->num, &g_pt1->chinese, &g_pt1->math, &g_pt1->english); //����ѧ�ż����Ƴɼ�����ѧ�ż����Ƴɼ�
		g_people++;

	}

	//��2���ڵ㼰����
	while (1)
	{
		g_n++;

		//�жϵ�ǰ�Ƿ�Ϊ��1���ڵ�
		if (g_n == 1)
		{
			g_head = g_pt1; //����ǵ�1���ڵ㣬������ͷ���� head

		}
		else
		{
			g_pt2->next = g_pt1;  //������ǣ����½ڵ��ͷ���� p1������pt1 �� pt2 �Ľڵ�

		}

		g_pt2 = g_pt1; //��p2ת�Ƶ��½ڵ�

		g_pt1 = (struct Student*)malloc(LEN); //�����½ڵ�
		//�ж��ڴ�����Ƿ�ɹ�
		if (g_pt1 == NULL)
		{
			printf("�ڴ���䲻�ɹ���\n");

			return NULL;

		}

		printf("������ѧ���Լ����Ƴɼ��� ");
		scanf_s("%d %f %f %f", &g_pt1->num, &g_pt1->chinese, &g_pt1->math, &g_pt1->english); //����ѧ�ż����Ƴɼ�
		g_people++;

		//�ж��Ƿ���������ڵ�
		if (g_pt1->num == 0)
		{
			free(g_pt1); //ɾ�����ж���ֹ�����Ľڵ�

			g_pt1 = g_pt2; //�� pt1 ����������β
			g_pt2->next = NULL; //������β���һ���սڵ���Ϊ NULL
			g_people--;

			return g_head;

		}

	};

	g_pt2->next = NULL; //������β���һ���սڵ���Ϊ NULL

	return g_head;

}


//ɾ��ĳ��ѧ���ĳɼ�
struct Student* del()
{
	struct Student* ptp;
	struct Student* ptq;
	int num;

	printf("��������Ҫɾ����ѧ����ѧ�ţ�");
	scanf_s("%d", &num);
	printf("\n");

	ptp = g_head;

	//ɾ����һ���ڵ�
	if (num == 1)
	{
		g_head = ptp->next; //��ͷָ�븳����2���ڵ�

		printf("��ɾ��ѧ��Ϊ %d ��ѧ����\n", ptp->num);
		printf("ѧ�������ĳɼ�Ϊ��%.1f\n", ptp->chinese);
		printf("ѧ������ѧ�ɼ�Ϊ��%.1f\n", ptp->math);
		printf("ѧ����Ӣ��ɼ�Ϊ��%.1f\n", ptp->english);

		free(ptp); //ɾ����1���ڵ�
		g_people--;

	}

	//ɾ����2�����Ժ�Ľڵ�
	else
	{
		//Ѱ��ѧ��Ϊ num ��ѧ��
		while (ptp->num != (num-1))
		{
			ptp = ptp->next; //������

		}
		
		ptq = ptp->next; //�� ptq ָ���ɾ���Ľڵ�

		printf("��ɾ��ѧ��Ϊ %d ��ѧ����\n", ptq->num);
		printf("ѧ�������ĳɼ�Ϊ��%.1f\n", ptq->chinese);
		printf("ѧ������ѧ�ɼ�Ϊ��%.1f\n", ptq->math);
		printf("ѧ����Ӣ��ɼ�Ϊ��%.1f\n", ptq->english);

		ptp->next = ptp->next; //������ɾ���Ľڵ�

		free(ptq); //ɾ���ڵ�
		
		g_people--; //����-1
		
	}

	return g_head; //����ͷ���

}


//********************�޸�ĳ��ѧ���ĳɼ�*******************
struct Student* modify()
{
	struct Student* ptp;
	float cn, math, eng;
	int i = 0;
	int num;

	ptp = g_head;
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�\n");
	scanf_s("%d", &num);

	//����Ҫ�޸ĵ�ѧ��
	while (ptp->num != num)
	{
		//��������β���жϲ���
		if (ptp->next == NULL)
		{
			printf("δ�ҵ���ѧ�Ŷ�Ӧ��ѧ����");

			return NULL; //�жϸú���

		}

		ptp = ptp->next;
		i++;

	}

	printf("������Ҫ�޸ĵĳɼ������ġ���ѧ��Ӣ���\n");
	scanf_s("%f %f %f", &cn, &math, &eng);
	printf("\n");

	//�޸ĳɼ�
	ptp->chinese = cn;
	ptp->math = math;
	ptp->english = eng;

	//����ɼ�
	printf("ѧ��Ϊ %d ��ѧ���ĳɼ����޸�Ϊ��\n", ptp->num);
	printf("���ģ�%.1f\n", ptp->chinese);
	printf("��ѧ��%.1f\n", ptp->math);
	printf("Ӣ�%.1f\n", ptp->english);
	printf("\n");

	return g_head;

}


//****************����ѧ���ɼ�*******************
struct Student* search()
{
	struct Student* ptp;
	int num;

	ptp = g_head;
	printf("������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf_s("%d", &num);
	printf("\n");

	//Ѱ����ͬ��ѧ��
	while (ptp->num != num)
	{
		//��������β���жϲ���
		if (ptp->next == NULL)
		{
			printf("δ�ҵ���ѧ�Ŷ�Ӧ��ѧ����");

			return NULL; //�жϸú���

		}

		ptp = ptp->next; //ptp����

	}

	//�����Ӧѧ�ŵ�ѧ����ѧ�ż��ɼ�
	printf("ѧ����ѧ��Ϊ��%d\n", ptp->num);
	printf("ѧ�������ĳɼ�Ϊ��%.1f\n", ptp->chinese);
	printf("ѧ������ѧ�ɼ�Ϊ��%.1f\n", ptp->math);
	printf("ѧ����Ӣ��ɼ�Ϊ��%.1f\n", ptp->english);

	return NULL;

}


//*****************����ɼ�*******************
struct Student* insert()
{
	struct Student* ptp;
	struct Student* pts;
	int x;
	int i = 1;

	printf("������Ҫ�����λ�ã�");
	scanf_s("%d", &x);
	printf("\n");

	ptp = g_head;

	pts = (struct Student*)malloc(LEN); //�����µĽڵ�
	//����ڴ�����Ƿ�ɹ�
	if (pts == NULL)
	{
		printf("�ڴ���䲻�ɹ�!\n");
		return NULL;
	}

	printf("������Ҫ��������ݣ�");
	scanf_s("%d %f %f %f", &pts->num, &pts->chinese, &pts->math, &pts->english);
	printf("\n");

	//���뵽��1���ڵ�
	if (x == 1)
	{
		pts->next = g_head;

	}

	//�����ڵ�2�������ϵĽڵ�
	else
	{
		while (ptp && i < x-1) //ptpָ�� x-1���ڵ�� next
		{
			ptp = ptp->next;
			i++;

		}

		pts->next = ptp->next; //
		ptp->next = pts; //��s��ֵ��p����һ�����

	}

	printf("�����ѧ��Ϊ %d ��ѧ��������Ϊ��\n", pts->num);
	printf("���ĳɼ�Ϊ��%.1f\n", pts->chinese);
	printf("��ѧ�ɼ�Ϊ��%.1f\n", pts->math);
	printf("Ӣ��ɼ�Ϊ��%.1f\n", pts->english);

	g_people++;

	return g_head; //����ָ��

}

//********************���ȫ��ѧ���ĳɼ�**************************
struct Student* print_all()
{
	bool breakflag = false;
	struct Student* ptp;

	ptp = g_head;

	printf("ϵͳ�й��� %d ��ѧ���ļ�¼��\n", g_people);
	//���ϵͳ��ѧ������Ϊ 0 ���ж����
	if (g_people == 0)
	{
		return NULL;

	}

	//������˳��������ѧ���ĳɼ�
	while (1)
	{
		//���ptp��һ���ڵ㣬�˳�����
		if (breakflag == true)
		{
			break;

		}

		printf("ѧ��Ϊ %d ��ѧ���ĳɼ�Ϊ��\n", ptp->num);
		printf("���� %.1f\n", ptp->chinese);
		printf("��ѧ %.1f\n", ptp->math);
		printf("Ӣ�� %.1f\n", ptp->english);
		printf("\n\n");

		
		if (ptp->next == NULL)
		{
			breakflag = true;

		}
		if (ptp->next != NULL)
		{
			ptp = ptp->next; //ptp����

		}

	}

	printf("\n");
	printf("����ѧ���ɼ������ϣ�\n");

	return NULL;

}