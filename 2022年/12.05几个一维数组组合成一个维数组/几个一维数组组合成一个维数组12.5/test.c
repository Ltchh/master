#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//例题 1:
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

//改写1:
//这个不是二维数组 二维数组是连续储存的
//这是单独存放的数组创建指针数组链接3个1维数组组成一个二位数组的形式
int arr() {
	int a[4] = { 1,2,3,4 };
	int b[4] = { 2,3,4,5 };
	int c[4] = { 3,4,5,6 };

	int* p[3] = { a,b,c };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {

			printf("%d ", *((*p+i) + j));
			//printf("%d ", *(p[i]  [j]);两个等价
		}
		printf("\n");
	}


	return 0;
}

