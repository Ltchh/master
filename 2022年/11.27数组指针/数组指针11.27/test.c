#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//void print(int(*p)[5], int r, int c) {
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < r; i++) {
//		for (j = 0; j < c; j++) {
//			printf("%d ", *(*(p + i) + j));//*(p + i)是首元素的地址
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//
//	//arr[i] <= => i[arr] <= => *(arr + i) <= => *(i + arr) <= => *(p + i) <= => *(i + p)--解引用
//
//
//	int a = 10;		//整形指针
//	int* pa = &a;
//
//	char ch = 'a';	//字符指针
//	char* pc = &ch;
//
//	char arr[5] = { 1,2,3,4,5 };	//数组指针
//	char(*parr)[10] = &arr;		//&arr取出的是数组的地址 arr=>是数组首元素地址
//		//parr就是一个数组指针=>其中存放的是数组的地址
//		//1:char (* )[10] 是元素类型
//		//2:parr	  数组名
//		//3:(* )[10]	  *指向的是10元素,元素的类型是char
//	
//	int arr_1[3][5] = { {1,2,3,4,5} ,{2,3,4,5,6},{3,4,5,6,7} };
//
//	print(arr_1, 3, 5);
//
//	//例题1:
//	double* d[5];
//
//	double* (*pa)[5] = &d;		//pd就是一个数组指针
//
//
//	return 0;
//}
//
////	int arr[5]			数组->		 有5个元素,每个元素的类型是int;
////	int *parr[5]		指针的数组-> 有5个元素,每个元素的类型是int*;存放整形指针的数组;
////	int (*parr)[5]		数组指针->	 存放一个指针,指向一个数组;有5个元素,每个元素的类型是int,该指针能够指向一个数组;
////	int	(*parr[10])[5]	指针数组->	 存放10数组指针,每个指针指向一个数组;有10个数组指针,每个数组指针有5个元素每个元素类型是int
//
////1.sizeof(数组名) - 数组名表示整个数组,姜蒜的是整个数组名的大小,单位是字节
////2.& 数组名 - 数组表示整个数组,取出的是整个数组的地址


//别扭写法1:		一般用于二维数组

//int main() {
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int(*pa)[10] = &arr;
//
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", *((*pa)+i));
//
//
//	}
//
//	return 0;
//}

//二维数组使用
void print(int(*p)[4], int r, int c) {
	int i, j;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", *(*(p + i) + j));//(p+i)=>	数组首元素的地址也就是arr[0]
										   //*(p+i)+j=> arr[0]+j
										   //*(*(p+i)+j) 	arr[0]+j进行解引用就是当前的的元素
		}
		printf("\n");
	}
}
int main() {
	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,0,11,12 };

	print(arr, 3, 4);//传过去是二维数组首行元素的地址

	return 0;
}