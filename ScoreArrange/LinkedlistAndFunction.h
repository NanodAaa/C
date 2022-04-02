#pragma once

//**********************��������***********************

//ѧ���ṹ�壬����ѧ��ѧ�š��ɼ�
struct Student
{
	int num; //ѧ��
	float chinese;
	float math;
	float english;
	struct Student* next;
};

//ѧ���ɼ�����ṹ��
struct Student_s
{
	int num;
	float chinese;
	float math;
	float english;
};


//***********************��������*******************************

float total_score();
float avg_score();
float max_score();
float min_score();
struct Student* add();
struct Student* modify();
struct Student* insert();
struct Student* del();
struct Student* search();
struct Student* print_all();
