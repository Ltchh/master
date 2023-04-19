#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define E_NUM 15
#define E_NAME 15
#define E_SEX 3
#define E_POS 10
#define E_DEPART 10
#define E_ADDR 30

#define E_SZ 5
#define E_PA 4

#define SIZEOF(x) sizeof(x)
#define MALLOC(X,BUFF) malloc(X*sizeof(BUFF))


typedef struct Employee {//信息
	char emp_num[E_NUM];	//编号
	char emp_name[E_NAME];	//姓名
	char emp_sex[E_SEX];	//性别
	int emp_age;		//年龄
	int emp_sen;		//工龄
	char emp_pos[E_POS];	//职务
	char emp_depart[E_DEPART];//部门
	char emp_addr[E_ADDR];	//家庭住址
}Employee;

typedef struct Information {//人员
	Employee* date;
	int number;//人数
	int pa;//扩容数量
}Information;

enum {
	EXIT,
	ADD,
	DELE,
	MODIFY,
	DISPLAY,
	SEARCH
};

void InitEmpl_er(Information* empl_er);//初始化


void Full_pace(Information* empl_er);//扩容

void fread_file(Information* empl_er);//加载文件

void Add_Information(Information* empl_er);//录入

void Search_information(Information* empl_er);//查找

void Dele__Information(Information* empl_er);//删除

void Modify_Information(Information* empl_er);//修改

void Display_information(Information* empl_er);//显示

void Exit_system(Information* empl_er);//退出系统
