#define _CRT_SECURE_NO_WARNINGS


#include<stdlib.h>
#include<stdio.h>

typedef struct student {
	int date;				//数据域
	struct student* next;	//指针域

}Student;

Student* createlist() {		//空链表
	Student* head = (Student*)malloc(sizeof(Student));
	if (NULL == head)
		return -1;
	head->next = NULL;

	Student* t = head, *cur;

	int nodedate;
	scanf("%d", &nodedate);

	while (nodedate){
		cur = (Student*)malloc(sizeof(Student));
		if (cur == NULL)
			return -1;
		cur->date = nodedate;
		t->next = cur;
		t = cur;
		scanf("%d", &nodedate);

	}
	t->next = NULL;
	return head;
}

int main() {

	Student* head = createlist();

	head = head->next;

	while (head) {
		printf("%d ", head->date);
		head = head->next;
	}

	return 0;
}