#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 18
#define MAX_ADDR 50

#define MAX 1000

#define DEEFAULT_SZ 5	//�洢����
#define INC_SZ 4		//����



typedef struct peoinfo {//�ṹ������-�˵���Ϣ

	//����
	char name[MAX_NAME];
	//����
	int age;
	//�Ա�
	char sex[MAX_SEX];
	//�绰
	char tele[MAX_TELE];
	//��ַ
	char addr[MAX_ADDR];
}peoinfo;

typedef struct contact{ //
	peoinfo* date;	//�ṹ��ָ��ָ��һ���ṹ��
	int sz;			//�����Ա��Ϣ�ĸ���
	int capacity;	//���ٵĿռ������������
}contact;


//��ʼ��
void initcontact(contact* con);

//���
void addcontact(contact* con);

//�޸�
void modifycontact(contact* con);

//ɾ��
void delecontact(contact* con);

//����
void searchcontact(contact* con);

//����
void sortcontact(contact* con);

//��ӡ
void printcontact(contact* con);

//���ٶ�̬�ڴ�
void deletecontact(contact*con);