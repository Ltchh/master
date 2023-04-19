#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include <conio.h>

#define PROD_MAX 4

#define SZ_MAX 4
#define PA_MAX 3

typedef struct Product {
	char Product_1[PROD_MAX];
	int	S_price_1;
	char Product_2[PROD_MAX];
	int	S_price_2;
	char Product_3[PROD_MAX];
	int	S_price_3;
	char Product_4[PROD_MAX];
	int	S_price_4;
	char Product_5[PROD_MAX];
	int	S_price_5;
	int sum;

}Product;

typedef struct Sales {
	Product* Sales_name;
	int sz[SZ_MAX];
	int pa[SZ_MAX];
}Sales;

enum {
	SALES_NAME_0,
	SALES_NAME_1,
	SALES_NAME_2,
	SALES_NAME_3,
	SALES_NAME_4
};


void initsales_1(Sales* sales_1);//初始化结构体

void statistics(Product* initsales[],int* input);//销售员1

