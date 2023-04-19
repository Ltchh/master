#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>


//2.memmove		�����ڴ��ص�����
// void* memmove(void* destination, const void* source, size_t num);

//�ص����ַ�Ϊ
//			С��(<)Ŀ��λ��
//			����(>)Ŀ��λ��

void print(int* arr) {
	while (*arr) {
		printf("%d ", *(arr++));
	}
}
void * my_memmove(void* dest, const void* src, size_t num) {
	void* tmp = dest;
	assert(dest && src);

	if (dest < src) {	//����(>)Ŀ��λ��
		while (num--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}

	}
	else {				//С��(<)Ŀ��λ��
		while (num--) {
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return tmp;
}
int main() {
	int arr1[50] = { 1,2,3,4,5,6,7,8,9,10 };
	
	int a = sizeof(arr1[0]);

	//memmove(arr1+2, arr1,a*5);

	//my_memmove(arr1+2, arr1, a * 4);//��arr1��ǰa*4���ֽڿ�����arr1+2��λ��
	my_memmove(arr1, arr1+2, a * 4);//��arr1��ǰa*4���ֽڿ�����arr1+2��λ��

	print(arr1);


	return 0;
}