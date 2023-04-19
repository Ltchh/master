#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main() {
	char str1[] = "hello world!";//首元素地址
	char str2[] = "hello world!";//首元素地址
	//两个数组的地址不相同-->str1!=str2(因为这两个是数组的地址)


	char* str3[] = "hello world!";//首元素常量
	char* str4[] = "hello world!";//首元素常量
	//指针变量赋值常量 两个常量相同-->str3==str4(因为这两个是指针变量(相当于一个变量赋值一样这两个相等))



}