#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>


//2.memmove		拷贝内存重叠函数
// void* memmove(void* destination, const void* source, size_t num);

//重叠部分分为
//			小于(<)目标位置
//			大于(>)目标位置

void print(int* arr) {
	while (*arr) {
		printf("%d ", *(arr++));
	}
}
void * my_memmove(void* dest, const void* src, size_t num) {
	void* tmp = dest;
	assert(dest && src);

	if (dest < src) {	//大于(>)目标位置
		while (num--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}

	}
	else {				//小于(<)目标位置
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

	//my_memmove(arr1+2, arr1, a * 4);//把arr1的前a*4个字节拷贝给arr1+2的位置
	my_memmove(arr1, arr1+2, a * 4);//把arr1的前a*4个字节拷贝给arr1+2的位置

	print(arr1);


	return 0;
}