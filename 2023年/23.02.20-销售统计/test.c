#define  _CRT_SECURE_NO_WARNINGS
#include"sales.h"


void interface() {
	printf("***********************\n");
	printf("****  (1号)销售员  ****\n");
	printf("****  (2号)销售员  ****\n");
	printf("****  (3号)销售员  ****\n");
	printf("****  (4号)销售员  ****\n");
	printf("***********************\n");
}

int main() {
	int input=0;
	do
	{
		interface();//界面

		Sales* sales_1[SALES_NAME_4];

		initsales_1(sales_1,&input);



		printf("请选择销售员;>");
		scanf("%d", &input);
		system("pause");//暂停
		system("cls");//清屏
		switch (input)
		{
		case SALES_NAME_1:
			
			statistics(sales_1+SALES_NAME_1,&input);
			break;
			//销售1
		case SALES_NAME_2:
			//statistics(&initsales[SALES_NAME_2]);
			break;
			//销售2
		case SALES_NAME_3:
			//statistics(&initsales[SALES_NAME_3]);
			break;
			//销售3
		case SALES_NAME_4:
			//statistics(&initsales[SALES_NAME_4]);
			break;
			//销售4

		default:
			break;
		}

	} while (input);
	return 0;
}