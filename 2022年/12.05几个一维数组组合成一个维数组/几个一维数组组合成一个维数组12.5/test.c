#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//���� 1:
int main() {
	int a = 10;
	int b =20;
	int c =30;

	int* p[3] = { &a,&b,&c };
	
	for (int i = 0; i < 3; i++) {
		
		printf("%d ", *(p[i]));
		  
	}

	return 0;
}

//��д1:
//������Ƕ�ά���� ��ά���������������
//���ǵ�����ŵ����鴴��ָ����������3��1ά�������һ����λ�������ʽ
int arr() {
	int a[4] = { 1,2,3,4 };
	int b[4] = { 2,3,4,5 };
	int c[4] = { 3,4,5,6 };

	int* p[3] = { a,b,c };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {

			printf("%d ", *((*p+i) + j));
			//printf("%d ", *(p[i]  [j]);�����ȼ�
		}
		printf("\n");
	}


	return 0;
}

