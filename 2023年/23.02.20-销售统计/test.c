#define  _CRT_SECURE_NO_WARNINGS
#include"sales.h"


void interface() {
	printf("***********************\n");
	printf("****  (1��)����Ա  ****\n");
	printf("****  (2��)����Ա  ****\n");
	printf("****  (3��)����Ա  ****\n");
	printf("****  (4��)����Ա  ****\n");
	printf("***********************\n");
}

int main() {
	int input=0;
	do
	{
		interface();//����

		Sales* sales_1[SALES_NAME_4];

		initsales_1(sales_1,&input);



		printf("��ѡ������Ա;>");
		scanf("%d", &input);
		system("pause");//��ͣ
		system("cls");//����
		switch (input)
		{
		case SALES_NAME_1:
			
			statistics(sales_1+SALES_NAME_1,&input);
			break;
			//����1
		case SALES_NAME_2:
			//statistics(&initsales[SALES_NAME_2]);
			break;
			//����2
		case SALES_NAME_3:
			//statistics(&initsales[SALES_NAME_3]);
			break;
			//����3
		case SALES_NAME_4:
			//statistics(&initsales[SALES_NAME_4]);
			break;
			//����4

		default:
			break;
		}

	} while (input);
	return 0;
}