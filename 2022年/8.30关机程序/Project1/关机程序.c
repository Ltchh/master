#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//�ػ�����->����"������"ȡ���ػ�>...
	char arr[20] = { 0 };
	again:
	system("shutdown -s -t 60");
	printf("����\"�����ҿ���\"���ػ�\n:");
	scanf("%s", arr);
	if (strcmp(arr,"�����ҿ���")==0) {
		system("shutdown -a");
	}
	else
		goto again;
	return 0;
}
	