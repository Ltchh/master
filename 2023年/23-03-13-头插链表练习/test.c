#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
typedef struct ren {
	char name[10];
	int age;
	char gender[4];
}Ren;

typedef struct stud {
	Ren data;			//数据域
	struct stud* next;	//指针域
	
}Student;

int main() {

	Student* head = (Student*)malloc(sizeof(Student));//头
	if (NULL == head)
		return -1;
	head->next = NULL;

	Student* cur = {0};
	
	
	int num=1;
	printf("输入[1]继续/输入[0]退出\n");
	scanf("%d", &num);
	

	while (num)
	{
		cur = (Student*)malloc(sizeof(Student));//申请空间
		if (NULL == cur)
			return -1;

		cur->next = head->next;
		head->next = cur;

		printf("输入姓名:");
		scanf("%s", cur->data.name);
		printf("请输入年龄:");
		scanf("%d", &(cur->data.age));
		printf("请输入性别:");
		scanf("%s", cur->data.gender);
		printf("输入[1]继续/输入[0]退出\n");
		scanf("%d", &num);
	}

	head = head->next;

	while (head)
	{
		printf("%s ", head->data.name);
		printf("%d ", head->data.age);
		printf("%s\n", head->data.gender);

		head = head->next;

	}


	return 0;

}