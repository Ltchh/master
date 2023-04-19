#include<stdio.h>

//typedef struct student {
//	char name[20];
//	char nume[15];
//	int age;
//}Student;

typedef struct node {
	int date;//数据域
	struct node* next;	//指针域->指向下一个节点;下一个节点的类型就是本身的类型
}Node;

int main() {
	Node a, b, c, d, e;//都在栈上

	Node* head;
	head=&a;//头

	a.date = 1;		//内容
	b.date = 2;
	c.date = 3;
	d.date = 4;
	e.date = 5;

	a.next = &b;	//连接
	b.next = &c; 
	c.next = &d;
	d.next = &e;

	e.next = NULL;	//结尾

	Node *phead = head;
	while (phead) {
		printf("%d\n", phead->date);
		phead = phead->next;

	}
	


	return 0;
}