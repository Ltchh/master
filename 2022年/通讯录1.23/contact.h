#pragma once

#include<stdio.h>
#include<string.h>

#define MAX_NAME 20	//姓名
#define MAX_SEX 10	//性别
#define MAX_TELE 12	//电话
#define MAX_ADDR 50//地址
#define MAX 1000


//类型定义

 typedef struct Peoinfo {
	char name[MAX_NAME];	//姓名
	char sex[MAX_SEX];		//性别
	int age;				//年纪
	char tele[MAX_TELE];	//电话
	char addr[MAX_ADDR];	//地址
}Peoinfo;


//通讯录
 typedef struct contact {
	 Peoinfo data[MAX];	//存放添加进来的人的信息	
	 int sz;			//记录当前通讯录有效信息  
}contact;

 //初始化通讯录
void initcontact(contact* con);

 //添加联系人
void addcontact(contact* con);

 //删除联系人
void delcontact(contact* con);

 //打印联系人信息
void printcontact(const contact*con);

 //查找联系人
void searchconcat(contact* con);

//修改联系人
void modfiycontact(contact*con);

//排序联系人
void sortcontact(contact*con);