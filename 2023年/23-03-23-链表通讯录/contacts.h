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

void window();//ϵͳ����

Contacts_n* create_heap(Contacts_n* head);//��������ڴ�

void Contacts_file(Contacts_n* head);//�����ļ�

void Contacts_ADD(Contacts_n* head);//����

void contacts_delete(Contacts_n* head);//ɾ��

void contacts_modify(Contacts_n* head);//�޸�

void contacts_query(Contacts_n* head);//����

void Constacts_SORT(Contacts_n* head);//����

void Constacts_SORT_1(Contacts_n* head);//�����ַ����

void Contacts_DISPLAY(Contacts_n* head);//��ʾ

void Contacts_exit(Contacts_n* head);//�˳�-����������ڴ�