#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>

//1.memcpy		�ڴ濽������
// void * memcpy(void* destination,const void*source ,size_t num) //size_t �ֽڴ�С
//2.memmove		�ڴ�
//3.memmcmp		�ڴ�
//4.memset		�ڴ�

void print(int* arr2) {
	while (*arr2!='\0') {
		
		printf("%d ", *arr2);
		arr2++;
	}
}
void* my_memcpy(void* dest, const void* src, size_t num) {
	void* dest_1 = dest;
	assert(dest && src);
	while (num--) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return dest_1;
}
int main() {
	int arr[50] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[50] = { 0 };
	int a =  sizeof(int);
	//memcpy(arr2, arr, a * 5);
	my_memcpy(arr2, arr, a * 5);
	print(arr2);
	return 0;
}