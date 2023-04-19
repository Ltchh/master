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


typedef struct Employee {//��Ϣ
	char emp_num[E_NUM];	//���
	char emp_name[E_NAME];	//����
	char emp_sex[E_SEX];	//�Ա�
	int emp_age;		//����
	int emp_sen;		//����
	char emp_pos[E_POS];	//ְ��
	char emp_depart[E_DEPART];//����
	char emp_addr[E_ADDR];	//��ͥסַ
}Employee;

typedef struct Information {//��Ա
	Employee* date;
	int number;//����
	int pa;//��������
}Information;

enum {
	EXIT,
	ADD,
	DELE,
	MODIFY,
	DISPLAY,
	SEARCH
};

void InitEmpl_er(Information* empl_er);//��ʼ��


void Full_pace(Information* empl_er);//����

void fread_file(Information* empl_er);//�����ļ�

void Add_Information(Information* empl_er);//¼��

void Search_information(Information* empl_er);//����

void Dele__Information(Information* empl_er);//ɾ��

void Modify_Information(Information* empl_er);//�޸�

void Display_information(Information* empl_er);//��ʾ

void Exit_system(Information* empl_er);//�˳�ϵͳ
