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

void initcontact(contact* con);//��ʼ���ṹ��

void ifcontact_y_n(contact* con);//ȷ���Ƿ���Ҫ��������Ķ���

void fread_file(contact* con);//�����ļ�

void addcontact(contact* con);//�����ϵ��

void modifycontact(contact* con);//�޸���ϵ��

void delecontact(contact* con);//ɾ����ϵ��

void searchcontact(contact* con);//������ϵ����Ϣ

void sortcontact(contact* con);//������ϵ��

void printcontact(contact* con);//��ӡ��ϵ��

void exit_save_file(contact* con);//�˳������ļ�

void exitcontact(contact* con);//�˳�����