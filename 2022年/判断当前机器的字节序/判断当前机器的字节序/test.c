#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main() {

	int a = 0;
	scanf("%d", &a);

	char* p = (char*)&a;//(ǿ��ת�����Ͱ�int����ָ��ת����char����ָ��;char���� ֻ��һ���ֽ�;)
	
		if (*p == a) {
			printf("С���ֽ������!\n");
		}
		else {
			printf("����ֽ������!\n");
		}


	return 0;
}