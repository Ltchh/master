#define _CRT_SECURE_NO_WARNINGS

#define MALLOC(BUFF) ((BUFF*)malloc(sizeof(BUFF)))

#include<stdio.h>
#include<stdlib.h>

typedef struct student {
	int data;				//数据域	
	struct student* next;	//指针域
}Student;

//真正意义上的创建链表,就是创建一个而空链表
Student* cerate_lelist() {
	Student* head = MALLOC(Student);
	if (NULL==head)
		return -1;
	head->next = NULL;
	return head;
}

void trvaerse_list(Student* head) {
	head = head->next;			//头插发第一个数据域是空;跳入下一个数据的指针
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;		//起传动指向下一个数据
	}
	printf("\n");
}

int len_list(Student* head) {//求长

	int len = 0;

	head = head->next;//头插发第一个数据域是空;跳入下一个数据的指针

	while (head){
		len++;
		head = head->next;//起传动指向下一个数据
	}
	return len;
}

Student* search_list(Student* head, int* num_1) {//查找

	head = head->next;//头插发第一个数据域是空;跳入下一个数据的指针

	while (head)
	{

			//这里一定要高明白
			//head指向的是哪一个结构体;head->data前一个的结构体
			//head->date指向的是哪一个数据域; head的下一个结构体的数据域
			//head->next指向的是哪一个指针域; head的下一个结构体的指针域;这指针域又可以指向下下个的数据域and指针域
		if (head->data == *num_1)
			break; //return head;
		head = head->next;
	}
	return head;
}

void delete_list(Student* head, Student* pfind) {//删除
	if (pfind->next == NULL) {
		while (head->next != pfind)
			head = head->next;
		head->next = pfind->next;
		free(pfind);
		pfind = NULL;
	}
	else {
		Student* t = pfind->next;

		pfind->data = pfind->next->data;//下一个数据存入pfind数据域中
		pfind->next = pfind->next->next;//把指针域指向下一个指针域
		free(t);
		t = NULL;
	}
 
}

void sort_list(Student* head) {//数据域排序

	int len = len_list(head);

	head = head->next;
	Student* t, * f;
	
	for (int i = 0; i < len - 1; i++) {
		t = head;
		f = t->next;
		
		for (int j = 0; j < len - 1 - i; j++) {
			if (t->data > f->data) {
				t->data ^= f->data;//1^=2
				f->data ^= t->data;//2^=1
				t->data ^= f->data;//1^=2->三步反转交换位置
			}

			t = t->next;
			f = f->next;
		}
	}	
}

void sort_list_1(Student* t_1) {//指针域形式排序

	int len = len_list(t_1);
	Student* prep, * x, * y,*t;


	for (int i = 0; i < len-1; i++){
		prep = t_1;
		x = t_1->next;	//被比较的元素
		y = x->next;	//比较元素

		for (int j = 0; j < len-i-1; j++){
			if (x->data > y->data) {
				prep = y;
				x->next = y->next;
				y->next = x;

				t = x;
				x = y;
				y = t;
			}

			prep = x->next;
			x = x->next;
			y = x->next;
		}
	}
}

void reverse_list(Student *t_2) {//反转链表
	Student* cur = t_2->next;   //拆分第一个空间链表,拆分成两个步相干的链表
	t_2->next = NULL;			//让首节点指针域为空
	Student* t;
	while (cur)
	{
		t = cur;
		cur = cur->next;//传动

		//让新来的节点又所指向
		cur->next = t_2->next;//NULL
		t_2->next = t;
	}
}

void free_list(Student* t_3) {//销毁链表
	Student* t;

	while (t_3){
		t = t_3;
		t_3 = t_3->next;

		free(t);
		t = NULL;
	}
}

int main() {

	Student* head=cerate_lelist();//创建链表

	Student* cur;

	int num;
	scanf("%d", &num);

	while (num){
		cur = (MALLOC(Student));
		if (cur == NULL)
			return -1;

		cur->data = num;
		
		//让新来的节点有所指向,避免打断原有的元素
		cur->next = head->next;
		head->next = cur;

		scanf("%d", &num);
	}

	int len = len_list(head);//数据计数
	printf("len_list=%d\n", len);

	int num_1;	//要查找的数据
	printf("输入要查询的数据:");
	scanf("%d", &num_1);

	Student* pfind=search_list(head,&num_1);//查找
	if (pfind == NULL)
		printf("未找到");

	else
		printf("找到了%d;\n", pfind->data);
		//未找到

	printf("删除的数据:");
	scanf("%d", &num_1);
	pfind = search_list(head, &num_1);

	if(pfind!=NULL)
	delete_list(head, pfind);//删除

	Student* t = head;
	sort_list(t);//数据域形式排序
	trvaerse_list(t);

	Student* t_1 = head;
	sort_list_1(t_1);//指针域形式排序
	trvaerse_list(t_1);

	Student* t_2 = head;
	reverse_list(t_2);//反转链表
	trvaerse_list(t_2);

	Student* t_3 = head;
	free_list(t_3);//链表销毁

	return 0;
}
