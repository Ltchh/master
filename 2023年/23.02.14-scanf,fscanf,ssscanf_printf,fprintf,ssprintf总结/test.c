#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//流概念-标准输出流
//stdin - 标准输入流 -键盘
//stdout - 标准输出流 -屏幕
//stderr - 标准错误流 -屏幕

//scanf		针对标准输入的格式的输入语句 - stdin
//fscanf	针对所有输入流的输入语句 - stdin/文件
//sscanf	从一个字符串中读取一个格式化的数据

//printf	针对标准输出的格式化输出语句 - stdout
//fprintf	针对所有输出流的格式化输出语句 - stdout/文件
//sprintf	从一个格式化数据,转换成字符串

typedef struct A {
	char arr[10];
	int age;
	int ar;
}A;
int main() {
	A a = { "字符串",15,12 };//初始化结构体

	char arr_1[150];//字符串

	A tmp = {0};//结构体

	sprintf(arr_1, "%s %d %d", a.arr, a.age,a.ar);//把一个结构体存放在字符串中
	 //解释:从a(arr,age)的结构体读取出数据写入到arr_1字符串数组中
	printf("%s\n", arr_1);

	sscanf(arr_1, "%s %d %d", tmp.arr, &(tmp.age),&(tmp.ar));//把字符串中的数据以结构体的方式存储
	 //解释:从arr_1字符串数组中读取数据以机构体方式存放到tmp(arr,age)机构体中
	printf("%s %d %d\n", tmp.arr,tmp.age,tmp.ar);

	return 0;
}