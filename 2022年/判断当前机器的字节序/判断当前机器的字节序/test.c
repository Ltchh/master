#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main() {

	int a = 0;
	scanf("%d", &a);

	char* p = (char*)&a;//(强制转换类型把int类型指针转换成char类型指针;char类型 只有一个字节;)
	
		if (*p == a) {
			printf("小端字节序机器!\n");
		}
		else {
			printf("大端字节序机器!\n");
		}


	return 0;
}