#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//define->���滻
//typedef->�����ض���


//��������:
//	�ṹ�е����һ��Ԫ����δ֪��С������,������������
//�ص�:�ṹ�е����������Աǰ���������һ��������Ա
//	   sizeif���ص����ֽṹ��С����������������ڴ�
//	   �ߺ����������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬����
//���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С,����Ӧ���������Ԥ�ڴ�С


//��:
typedef struct st_def {//=>��������
	char ch;
	int a;
	int arr[];//���������Ա - δ֪��С
	//Ҳ����дint arr[0];
}st_def;


int main() {
	st_def* ptr = (st_def*)malloc(sizeof(st_def) + 10 * sizeof(st_def));

	if (ptr == NULL){
		perror("prt");
		return;
	}

	ptr->ch = 'a';
	ptr->a = 10;

	for (int i = 0; i < 10; i++) {
		ptr->arr[i] = i;
	}

	st_def* ps = (st_def*)realloc(ps, sizeof(ptr) + 20 * sizeof(st_def));
	if (ps != NULL)
		ptr = ps;
	free(ps);
	ps = NULL;
	return 0;
}