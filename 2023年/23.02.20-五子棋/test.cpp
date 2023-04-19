#include"gobang.h"
#define  _CRT_SECURE_NO_WARNINGS

//#define GRD
//
//int main() {
//	initgraph(600, 500);//创建图形窗口
//
//	IMAGE background;//图形变量
//
//	//加载图片
//	loadimage(&background, "date/background.png");
//
//	//输出图片
//	putimage(0, 0, &background);
//
//	//画线条
//	setlinecolor(BLACK);
//	line(50, 50,550,50 );
//	getchar();
//
//	return 0;
//}


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include<stdio.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS 1

//定义一个学生
typedef struct Student{
	int stuNum;//学号
	char name[20];//姓名
	char sex[10];//性别
	int age;
	char major[40];//专业
	int grade;
}Student;

//节点（车厢）
typedef struct Node
{
	Student stu;//学生
	struct Node* pNext;//指向下一个节点的指针
}Node;

Node* g_pHead = NULL;//头结点

void Welcome();

void InputStudent(); //录入学生信息

int main()
{
	int i;//选择

	while (i)
	{
		Welcome();//主菜单

		
		printf("请选择功能:>");
		scanf("%d", i);

		switch (i)
		{
		case '1': //录入学生信息
			InputStudent();
			break;
		case '2': //打印学生信息
			break;
		case '3': //保存学生信息
			break;
		case '4': //读取学生信息
			break;
		case '5': //统计所有学生人数
			break;
		case '6': //查找学生信息
			break;
		case '7': //修改学生信息
			break;
		case '8': //删除学生信息
			break;
		case '9': //退出系统
			return 0;
		}
	}
	return 0;
}
void Welcome()
{
	printf("*************************************************\n");
	printf("\t\t欢迎使用学生信息管理系统\t\t\t\n");
	printf("*************************************************\n");
	printf("*\t\t请选择功能列表\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计所有学生人数\t\t*\n");
	printf("*\t\t6.查找学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
	printf("*\t\t9.退出系统\t\t\t*\n");
}
//void InputStudent()
//{
//	//创建一个新节点
//	Node* pNewNode = (Node*)malloc(sizeof(Node));//申请动态内存
//	pNewNode->pNext = NULL;//(既是头结点，又是尾结点。是一个空链表)
//	//头插法
//	if (g_pHead == NULL)
//	{
//		gPHead = g_pNewNode;
//	}
//	else {
//		pNewNode->pNext = g_pHead;
//		g_pHead = pNewNode;
//	}
//	printf("请输入学生学号:\n");
//	scanf("%d", &pNewNode->stu.stuNum);
//	printf("请输入学生姓名:\n");
//	scanf("%s", pNewNode->stu.name);
//	printf("请输入学生性别:\n");
//	scanf("%s", pNewNode->stu.sex);
//	printf("请输入学生年龄:\n");
//	scanf("%d", &pNewNode->stu.age);
//	printf("请输入学生专业:\n");
//	scanf("%s", pNewNode->stu.major);
//	printf("请输入学生年级:\n");
//	scanf("%d", &pNewNode->stu.grade);
//	printf("学生信息录入成功\n");
//	system("pause");//暂停
//	system("cls");//清屏
//}