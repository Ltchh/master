#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//�µ���
// line  ��,�� 

int main() {

	int line = 0;

	scanf("%d", &line);

	//�ϰ벿��
	for (int i = 0; i < line; i++) {
		//��ӡ' '
		for (int j = 0; j < line-i-1; j++) {
			printf(" ");
		}
		//��ӡ'*'
		for (int j = 0; j < 2*i+1; j++) {		//2*i+1��һ������
			printf("*");

		}
		printf("\n");

	}

	//�°벿��
	for (int i = 0; i < line - 1; i++) {
		//��ӡ' '
		for (int j = 0; j <=i ; j++) {
			printf(" ");

		}
		//��ӡ'*'
		for (int j = 0; j <2*(line-i-1)-1; j++) {
			printf("*");

		}
		printf("\n");
	}
	return 0;
}