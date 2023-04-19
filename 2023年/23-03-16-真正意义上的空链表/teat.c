#define _CRT_SECURE_NO_WARNINGS

#define MALLOC(BUFF) ((BUFF*)malloc(sizeof(BUFF)))

#include<stdio.h>
#include<stdlib.h>

typedef struct student {
	int data;				//������	
	struct student* next;	//ָ����
}Student;

//���������ϵĴ�������,���Ǵ���һ����������
Student* cerate_lelist() {
	Student* head = MALLOC(Student);
	if (NULL==head)
		return -1;
	head->next = NULL;
	return head;
}

void trvaerse_list(Student* head) {
	head = head->next;			//ͷ�巢��һ���������ǿ�;������һ�����ݵ�ָ��
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;		//�𴫶�ָ����һ������
	}
	printf("\n");
}

int len_list(Student* head) {//��

	int len = 0;

	head = head->next;//ͷ�巢��һ���������ǿ�;������һ�����ݵ�ָ��

	while (head){
		len++;
		head = head->next;//�𴫶�ָ����һ������
	}
	return len;
}

Student* search_list(Student* head, int* num_1) {//����

	head = head->next;//ͷ�巢��һ���������ǿ�;������һ�����ݵ�ָ��

	while (head)
	{

			//����һ��Ҫ������
			//headָ�������һ���ṹ��;head->dataǰһ���Ľṹ��
			//head->dateָ�������һ��������; head����һ���ṹ���������
			//head->nextָ�������һ��ָ����; head����һ���ṹ���ָ����;��ָ�����ֿ���ָ�����¸���������andָ����
		if (head->data == *num_1)
			break; //return head;
		head = head->next;
	}
	return head;
}

void delete_list(Student* head, Student* pfind) {//ɾ��
	if (pfind->next == NULL) {
		while (head->next != pfind)
			head = head->next;
		head->next = pfind->next;
		free(pfind);
		pfind = NULL;
	}
	else {
		Student* t = pfind->next;

		pfind->data = pfind->next->data;//��һ�����ݴ���pfind��������
		pfind->next = pfind->next->next;//��ָ����ָ����һ��ָ����
		free(t);
		t = NULL;
	}
 
}

void sort_list(Student* head) {//����������

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
				t->data ^= f->data;//1^=2->������ת����λ��
			}

			t = t->next;
			f = f->next;
		}
	}	
}

void sort_list_1(Student* t_1) {//ָ������ʽ����

	int len = len_list(t_1);
	Student* prep, * x, * y,*t;


	for (int i = 0; i < len-1; i++){
		prep = t_1;
		x = t_1->next;	//���Ƚϵ�Ԫ��
		y = x->next;	//�Ƚ�Ԫ��

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

void reverse_list(Student *t_2) {//��ת����
	Student* cur = t_2->next;   //��ֵ�һ���ռ�����,��ֳ���������ɵ�����
	t_2->next = NULL;			//���׽ڵ�ָ����Ϊ��
	Student* t;
	while (cur)
	{
		t = cur;
		cur = cur->next;//����

		//�������Ľڵ�����ָ��
		cur->next = t_2->next;//NULL
		t_2->next = t;
	}
}

void free_list(Student* t_3) {//��������
	Student* t;

	while (t_3){
		t = t_3;
		t_3 = t_3->next;

		free(t);
		t = NULL;
	}
}

int main() {

	Student* head=cerate_lelist();//��������

	Student* cur;

	int num;
	scanf("%d", &num);

	while (num){
		cur = (MALLOC(Student));
		if (cur == NULL)
			return -1;

		cur->data = num;
		
		//�������Ľڵ�����ָ��,������ԭ�е�Ԫ��
		cur->next = head->next;
		head->next = cur;

		scanf("%d", &num);
	}

	int len = len_list(head);//���ݼ���
	printf("len_list=%d\n", len);

	int num_1;	//Ҫ���ҵ�����
	printf("����Ҫ��ѯ������:");
	scanf("%d", &num_1);

	Student* pfind=search_list(head,&num_1);//����
	if (pfind == NULL)
		printf("δ�ҵ�");

	else
		printf("�ҵ���%d;\n", pfind->data);
		//δ�ҵ�

	printf("ɾ��������:");
	scanf("%d", &num_1);
	pfind = search_list(head, &num_1);

	if(pfind!=NULL)
	delete_list(head, pfind);//ɾ��

	Student* t = head;
	sort_list(t);//��������ʽ����
	trvaerse_list(t);

	Student* t_1 = head;
	sort_list_1(t_1);//ָ������ʽ����
	trvaerse_list(t_1);

	Student* t_2 = head;
	reverse_list(t_2);//��ת����
	trvaerse_list(t_2);

	Student* t_3 = head;
	free_list(t_3);//��������

	return 0;
}
