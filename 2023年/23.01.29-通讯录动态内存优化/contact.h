#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 18
#define MAX_ADDR 50

#define MAX 1000

#define DEEFAULT_SZ 5	//存储计数
#define INC_SZ 4		//增量



typedef struct peoinfo {//结构体类型-人的信息

	//姓名
	char name[MAX_NAME];
	//年龄
	int age;
	//性别
	char sex[MAX_SEX];
	//电话
	char tele[MAX_TELE];
	//地址
	char addr[MAX_ADDR];
}peoinfo;

typedef struct contact{ //
	peoinfo* date;	//结构体指针指向一个结构体
	int sz;			//存放人员信息的个数
	int capacity;	//开辟的空间满后的增加量
}contact;


//初始化
void initcontact(contact* con);

//添加
void addcontact(contact* con);

//修改
void modifycontact(contact* con);

//删除
void delecontact(contact* con);

//查找
void searchcontact(contact* con);

//排序
void sortcontact(contact* con);

//打印
void printcontact(contact* con);

//销毁动态内存
void deletecontact(contact*con);