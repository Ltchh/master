#define  _CRT_SECURE_NO_WARNINGS
#include"sales.h"

void initsales_1(Sales* sales,int * input) {//��ʼ���ṹ��
	Product* pt = (Product*)malloc(SZ_MAX * sizeof(Product));
	if (pt==NULL){
		perror("initsales_1");
		return;
	}
	sales->Sales_name = pt;
	sales->sz[*input] = 0;
	sales->pa[*input] = PA_MAX;

}

Enlarge_capacity(Product* initsales[], int* input) {//����
	
}
//����Ա
void statistics(Product* initsales[],int* input) {

	Enlarge_capacity(initsales,input);//����

	printf("��������1�ļ۸�:>");
	printf("��������2�ļ۸�:>");
	printf("��������3�ļ۸�:>");
	printf("��������4�ļ۸�:>");
	scanf("%d");

}


