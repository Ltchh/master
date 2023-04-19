#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//关机程序->输入"我是猪"取消关机>...
	char arr[20] = { 0 };
	again:
	system("shutdown -s -t 60");
	printf("输入\"我行我可以\"消关机\n:");
	scanf("%s", arr);
	if (strcmp(arr,"我行我可以")==0) {
		system("shutdown -a");
	}
	else
		goto again;
	return 0;
}
	