#include"gobang.h"
#define  _CRT_SECURE_NO_WARNINGS

//#define GRD
//
//int main() {
//	initgraph(600, 500);//����ͼ�δ���
//
//	IMAGE background;//ͼ�α���
//
//	//����ͼƬ
//	loadimage(&background, "date/background.png");
//
//	//���ͼƬ
//	putimage(0, 0, &background);
//
//	//������
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

//����һ��ѧ��
typedef struct Student{
	int stuNum;//ѧ��
	char name[20];//����
	char sex[10];//�Ա�
	int age;
	char major[40];//רҵ
	int grade;
}Student;

//�ڵ㣨���ᣩ
typedef struct Node
{
	Student stu;//ѧ��
	struct Node* pNext;//ָ����һ���ڵ��ָ��
}Node;

Node* g_pHead = NULL;//ͷ���

void Welcome();

void InputStudent(); //¼��ѧ����Ϣ

int main()
{
	int i;//ѡ��

	while (i)
	{
		Welcome();//���˵�

		
		printf("��ѡ����:>");
		scanf("%d", i);

		switch (i)
		{
		case '1': //¼��ѧ����Ϣ
			InputStudent();
			break;
		case '2': //��ӡѧ����Ϣ
			break;
		case '3': //����ѧ����Ϣ
			break;
		case '4': //��ȡѧ����Ϣ
			break;
		case '5': //ͳ������ѧ������
			break;
		case '6': //����ѧ����Ϣ
			break;
		case '7': //�޸�ѧ����Ϣ
			break;
		case '8': //ɾ��ѧ����Ϣ
			break;
		case '9': //�˳�ϵͳ
			return 0;
		}
	}
	return 0;
}
void Welcome()
{
	printf("*************************************************\n");
	printf("\t\t��ӭʹ��ѧ����Ϣ����ϵͳ\t\t\t\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t9.�˳�ϵͳ\t\t\t*\n");
}
//void InputStudent()
//{
//	//����һ���½ڵ�
//	Node* pNewNode = (Node*)malloc(sizeof(Node));//���붯̬�ڴ�
//	pNewNode->pNext = NULL;//(����ͷ��㣬����β��㡣��һ��������)
//	//ͷ�巨
//	if (g_pHead == NULL)
//	{
//		gPHead = g_pNewNode;
//	}
//	else {
//		pNewNode->pNext = g_pHead;
//		g_pHead = pNewNode;
//	}
//	printf("������ѧ��ѧ��:\n");
//	scanf("%d", &pNewNode->stu.stuNum);
//	printf("������ѧ������:\n");
//	scanf("%s", pNewNode->stu.name);
//	printf("������ѧ���Ա�:\n");
//	scanf("%s", pNewNode->stu.sex);
//	printf("������ѧ������:\n");
//	scanf("%d", &pNewNode->stu.age);
//	printf("������ѧ��רҵ:\n");
//	scanf("%s", pNewNode->stu.major);
//	printf("������ѧ���꼶:\n");
//	scanf("%d", &pNewNode->stu.grade);
//	printf("ѧ����Ϣ¼��ɹ�\n");
//	system("pause");//��ͣ
//	system("cls");//����
//}