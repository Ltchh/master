#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main() {
	char str1[] = "hello world!";//��Ԫ�ص�ַ
	char str2[] = "hello world!";//��Ԫ�ص�ַ
	//��������ĵ�ַ����ͬ-->str1!=str2(��Ϊ������������ĵ�ַ)


	char* str3[] = "hello world!";//��Ԫ�س���
	char* str4[] = "hello world!";//��Ԫ�س���
	//ָ�������ֵ���� ����������ͬ-->str3==str4(��Ϊ��������ָ�����(�൱��һ��������ֵһ�����������))



}