#include<stdio.h>

//typedef struct student {
//	char name[20];
//	char nume[15];
//	int age;
//}Student;

typedef struct node {
	int date;//������
	struct node* next;	//ָ����->ָ����һ���ڵ�;��һ���ڵ�����;��Ǳ��������
}Node;

int main() {
	Node a, b, c, d, e;//����ջ��

	Node* head;
	head=&a;//ͷ

	a.date = 1;		//����
	b.date = 2;
	c.date = 3;
	d.date = 4;
	e.date = 5;

	a.next = &b;	//����
	b.next = &c; 
	c.next = &d;
	d.next = &e;

	e.next = NULL;	//��β

	Node *phead = head;
	while (phead) {
		printf("%d\n", phead->date);
		phead = phead->next;

	}
	


	return 0;
}