#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 15	
#define MAX_SEX 2
#define MAX_TELE 13
#define MAX_ADDR 50

#define MAX_SZ 4
#define MAX_CAPA 4


typedef struct peoinfo {
	int age;
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;

typedef struct contact {
	peoinfo* date;
	int num;
	int capacity;
}contact;

void initcontact(contact* con);//初始化结构体

void ifcontact_y_n(contact* con);//确认是否需要创建更多的堆区

void fread_file(contact* con);//加载文件

void addcontact(contact* con);//添加联系人

void modifycontact(contact* con);//修改联系人

void delecontact(contact* con);//删除联系人

void searchcontact(contact* con);//查找联系人信息

void sortcontact(contact* con);//排序联系人

void printcontact(contact* con);//打印联系人

void exit_save_file(contact* con);//退出保存文件

void exitcontact(contact* con);//退出程序