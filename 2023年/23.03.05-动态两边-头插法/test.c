
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//所谓的的头插法,就是再头节点后面插入元素,每插入一个元素都是头节点
typedef struct student {
	int date;
	struct student* next;//指针域
}Student;



//Student* createlist() {
//	Student* head = (Student*)malloc(sizeof(Student));
//	if (NULL == head)
//		return -1;
//	head->next = NULL;
//
//	Student* t = head,*cur;
//
//	int nodedate;
//
//	scanf("%d", &nodedate);
//	while (nodedate){
//		cur = (Student*)malloc(sizeof(Student));
//		if (NULL == cur)
//			return -1;
//		cur->date = nodedate;
//		t->next = cur;
//		t = cur;
//		scanf("%d", &nodedate);
//	}
//	t->next = NULL;
//	return head;
//}
//
//void print(Student* head) {
//	head = head->next;
//	while (head)
//	{
//		printf("%d ", head->date);
//		head = head->next;
//	}	
//}
//
//int  main() {
//	Student* head = createlist();
//	
//	print(head);
//
//	return 0;
//}

Student* createlist() {
	Student* head = (Student*)malloc(sizeof(Student));
	if (NULL == head)
		return -1;
	head->next = NULL;

	Student* cur;
	int nodedata;

	scanf("%d", &nodedata);

	while (nodedata){
		cur = (Student*)malloc(sizeof(Student));//申请空间
		cur->date = nodedata;		//保存数据

		//让新来的节点有所指向,避免打断原有的指向
		cur->next = head->next;	//最主要
		head->next = cur;		//最主要

		scanf("%d", &nodedata);
	}

	return head;
}


int main() {
	Student* head = createlist();

	head = head->next;

	while (head)
	{
		printf("%d ", head->date);
		head = head->next;
	}

	return 0;
}
