#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//memset 内存设置函数-以字节为单位设置内存
//void memset(viod*ptr,int value ,size_t num);
//ptr->数组的首元素地址
//value->需要设置的常量
//num->需要设置变量的个数


void my_print(int(*p)[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//printf("%d ", *((*p + i) + j));
			//printf("%d ",(*p + i)[j]);
			printf("%d ", p[i][j]);

		}
		printf("\n");
	}
}

int main() {

	int arr[5][5];
	int num = sizeof(arr);
	memset(arr, 0,num);

	my_print(arr);


	return 0;
}