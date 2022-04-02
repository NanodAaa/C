#pragma once

//**********************声明变量***********************

//学生结构体，储存学生学号、成绩
struct Student
{
	int num; //学号
	float chinese;
	float math;
	float english;
	struct Student* next;
};

//学生成绩储存结构体
struct Student_s
{
	int num;
	float chinese;
	float math;
	float english;
};


//***********************声明函数*******************************

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
