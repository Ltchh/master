#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


//strtok 分割字符串函数
//例 strtok(arr,p1)//arr字符串 p1分隔符隔开的标记集合地址
//1.第一个参数指定一个字符串,它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记
//2.strtok函数找到str中的下一个标记,并将其用\0结尾,返回一个指向这个标记的指针(该函数会改变被操作的字符串,
//所以使用strtok函数切割字符串都是使用临时拷贝的内容修改(strcpy函数))
//3.strtok函数的第一个参数不为NULL,函数将找到str中第一个标记,strtok函数将保存它在字符串的位置
//4.如果字符串中不存在更多标记返回一个NULL指针
int main() {
	char arr[50] = "lifetime_chhui@163.com";
	char* p1 = "_@.";
	char arr2[50] = {0};

	strcpy(arr2, arr);
	//char* ret = NULL;

	//ret=strtok(arr2, p1);
	//printf("%s\n", ret);

	//ret=strtok(NULL, p1);
	//printf("%s\n", ret);

	//ret=strtok(NULL, p1);
	//printf("%s\n", ret);

	//三句简化版
	for (char* tmp = strtok(arr2, p1); tmp != NULL; tmp = strtok(NULL, p1)) {
		printf("%s\n", tmp);
	}

	return 0;
}