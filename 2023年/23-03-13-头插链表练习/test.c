#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
typedef struct ren {
	char name[10];
	int age;
	char gender[4];
}Ren;

typedef struct stud {
	Ren data;			//������
	struct stud* next;	//ָ����
	
}Student;

int main() {

	Student* head = (Student*)malloc(sizeof(Student));//ͷ
	if (NULL == head)
		return -1;
	head->next = NULL;

	Student* cur = {0};
	
	
	int num=1;
	printf("����[1]����/����[0]�˳�\n");
	scanf("%d", &num);
	

	while (num)
	{
		cur = (Student*)malloc(sizeof(Student));//����ռ�
		if (NULL == cur)
			return -1;

		cur->next = head->next;
		head->next = cur;

		printf("��������:");
		scanf("%s", cur->data.name);
		printf("����������:");
		scanf("%d", &(cur->data.age));
		printf("�������Ա�:");
		scanf("%s", cur->data.gender);
		printf("����[1]����/����[0]�˳�\n");
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