#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//新单词
// line  线,行 

int main() {

	int line = 0;

	scanf("%d", &line);

	//上半部分
	for (int i = 0; i < line; i++) {
		//打印' '
		for (int j = 0; j < line-i-1; j++) {
			printf(" ");
		}
		//打印'*'
		for (int j = 0; j < 2*i+1; j++) {		//2*i+1是一个奇数
			printf("*");

		}
		printf("\n");

	}

	//下半部分
	for (int i = 0; i < line - 1; i++) {
		//打印' '
		for (int j = 0; j <=i ; j++) {
			printf(" ");

		}
		//打印'*'
		for (int j = 0; j <2*(line-i-1)-1; j++) {
			printf("*");

		}
		printf("\n");
	}
	return 0;
}