
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//��ν�ĵ�ͷ�巨,������ͷ�ڵ�������Ԫ��,ÿ����һ��Ԫ�ض���ͷ�ڵ�
typedef struct student {
	int date;
	struct student* next;//ָ����
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
		cur = (Student*)malloc(sizeof(Student));//����ռ�
		cur->date = nodedata;		//��������

		//�������Ľڵ�����ָ��,������ԭ�е�ָ��
		cur->next = head->next;	//����Ҫ
		head->next = cur;		//����Ҫ

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
