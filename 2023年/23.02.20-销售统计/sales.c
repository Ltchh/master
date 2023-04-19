#define  _CRT_SECURE_NO_WARNINGS
#include"sales.h"

void initsales_1(Sales* sales,int * input) {//初始化结构体
	Product* pt = (Product*)malloc(SZ_MAX * sizeof(Product));
	if (pt==NULL){
		perror("initsales_1");
		return;
	}
	sales->Sales_name = pt;
	sales->sz[*input] = 0;
	sales->pa[*input] = PA_MAX;

}

Enlarge_capacity(Product* initsales[], int* input) {//扩容
	
}
//销售员
void statistics(Product* initsales[],int* input) {

	Enlarge_capacity(initsales,input);//扩容

	printf("请输入编号1的价格:>");
	printf("请输入编号2的价格:>");
	printf("请输入编号3的价格:>");
	printf("请输入编号4的价格:>");
	scanf("%d");

}


