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
//	for (int i = 0; i < *sz - 1; i++) {	//��������
//		for (int j = 0; j < *sz-1-i ; j++) {		//һ��ð����������
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


//����������

//void qsort(void* base,						//������ʼλ��(��Ԫ�ص�ַ)
//	size_t num,								//��������Ԫ�صĸ���
//	size_t size,							//������һ��Ԫ�صĴ�С,��λ�ֽ�
//	int (*comper)(const void*, const void*) //�����Ƚϴ����������е�2��Ԫ�صĺ���
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