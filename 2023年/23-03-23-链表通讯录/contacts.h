#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MALLOC(BUFF) (BUFF*)malloc(sizeof(BUFF))

typedef struct contacts_data {
	char name[10];
	char mobilenum[12];
	char fixenum[12];
	char companynum[30];
}Contacts_d;

typedef struct contact_node {
	Contacts_d data;
	struct contact_node* next;
}Contacts_n;

enum sequence {
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	QUERY,
	SORT,
	DISPLAY
};

void window();//系统命令

Contacts_n* create_heap(Contacts_n* head);//申请堆区内存

void Contacts_file(Contacts_n* head);//加载文件

void Contacts_ADD(Contacts_n* head);//增加

void contacts_delete(Contacts_n* head);//删除

void contacts_modify(Contacts_n* head);//修改

void contacts_query(Contacts_n* head);//查找

void Constacts_SORT(Contacts_n* head);//排序

void Constacts_SORT_1(Contacts_n* head);//链表地址排序

void Contacts_DISPLAY(Contacts_n* head);//显示

void Contacts_exit(Contacts_n* head);//退出-销毁申请的内存