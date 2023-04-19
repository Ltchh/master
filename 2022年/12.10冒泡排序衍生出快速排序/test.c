#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//void print(int *parr, int* sz){
//	for (int i = 0; i < *sz; i++) {
//		printf("%d ", parr[i]);
//	}
//	printf("\n");
//}
//void bubble_sort(int *parr, int *sz) {
//	int arr[10] = { 0 };
//	for (int i = 0; i < *sz - 1; i++) {	//排序躺数
//		for (int j = 0; j < *sz-1-i ; j++) {		//一次冒泡排序躺数
//			if (*(parr + j) < *(parr + j + 1)) {
//				int tmp = *(parr + j + 1);
//				*(parr + j + 1) = *(parr + j);
//				*(parr + j) = tmp;
//			}		
//		}	
//	}
//	return print(parr, sz);
// }
//void oper(void(*parr)(int*,int *)) {
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	return parr(arr, &sz);
//}
//
//int main() {
//	oper(print);
//	oper(bubble_sort);
//	
//	return 0;
//}


//快速排序函数

//void qsort(void* base,						//数组起始位置(首元素地址)
//	size_t num,								//排序数据元素的个数
//	size_t size,							//排序中一个元素的大小,单位字节
//	int (*comper)(const void*, const void*) //用来比较待排序数据中的2个元素的函数
//);
void print(int* parr, int* sz) {
	for (int i = 0; i < *sz; i++) {
		printf("%d ", parr[i]);
	}
	printf("\n");
}

int comper(const void* e1, const void* e2) {
	return *(int*)(e1)-*(int*)(e2);
}


int main() {
	int arr[10] = { 9,8,7,6,5,3,4,2,1,0 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	print(arr, &sz);

	qsort(arr, sz, sizeof(arr[0]), comper);

	print(arr,&sz);

	return 0;
}