#pragma once

#include<stdio.h>
#include<string.h>

#define MAX_NAME 20	//����
#define MAX_SEX 10	//�Ա�
#define MAX_TELE 12	//�绰
#define MAX_ADDR 50//��ַ
#define MAX 1000


//���Ͷ���

 typedef struct Peoinfo {
	char name[MAX_NAME];	//����
	char sex[MAX_SEX];		//�Ա�
	int age;				//���
	char tele[MAX_TELE];	//�绰
	char addr[MAX_ADDR];	//��ַ
}Peoinfo;


//ͨѶ¼
 typedef struct contact {
	 Peoinfo data[MAX];	//�����ӽ������˵���Ϣ	
	 int sz;			//��¼��ǰͨѶ¼��Ч��Ϣ  
}contact;

 //��ʼ��ͨѶ¼
void initcontact(contact* con);

 //�����ϵ��
void addcontact(contact* con);

 //ɾ����ϵ��
void delcontact(contact* con);

 //��ӡ��ϵ����Ϣ
void printcontact(const contact*con);

 //������ϵ��
void searchconcat(contact* con);

//�޸���ϵ��
void modfiycontact(contact*con);

//������ϵ��
void sortcontact(contact*con);