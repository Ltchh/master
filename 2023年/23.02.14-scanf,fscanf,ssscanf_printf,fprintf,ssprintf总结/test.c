#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//������-��׼�����
//stdin - ��׼������ -����
//stdout - ��׼����� -��Ļ
//stderr - ��׼������ -��Ļ

//scanf		��Ա�׼����ĸ�ʽ��������� - stdin
//fscanf	���������������������� - stdin/�ļ�
//sscanf	��һ���ַ����ж�ȡһ����ʽ��������

//printf	��Ա�׼����ĸ�ʽ�������� - stdout
//fprintf	�������������ĸ�ʽ�������� - stdout/�ļ�
//sprintf	��һ����ʽ������,ת�����ַ���

typedef struct A {
	char arr[10];
	int age;
	int ar;
}A;
int main() {
	A a = { "�ַ���",15,12 };//��ʼ���ṹ��

	char arr_1[150];//�ַ���

	A tmp = {0};//�ṹ��

	sprintf(arr_1, "%s %d %d", a.arr, a.age,a.ar);//��һ���ṹ�������ַ�����
	 //����:��a(arr,age)�Ľṹ���ȡ������д�뵽arr_1�ַ���������
	printf("%s\n", arr_1);

	sscanf(arr_1, "%s %d %d", tmp.arr, &(tmp.age),&(tmp.ar));//���ַ����е������Խṹ��ķ�ʽ�洢
	 //����:��arr_1�ַ��������ж�ȡ�����Ի����巽ʽ��ŵ�tmp(arr,age)��������
	printf("%s %d %d\n", tmp.arr,tmp.age,tmp.ar);

	return 0;
}