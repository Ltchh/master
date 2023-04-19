#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//strlen �����ַ�������
//strcmp	�Ƚ��ַ�������	��strcmp(arr1,arr2)=>arr>arr2����ֵ����0;arr1<arr2����ֵС��0;arr1=arr2����ֵΪ0;
//strcpy	�����ַ�������	��strcpy(arr1,arr2)=>��arr2������arr1;
//strcat	׷���ַ�������	��strcat(arr1,arr2)=>��arr2׷����arr1����

//strncmp	�Ƚ��ض������ַ�������	��strncmp(arr1,arr2,3)�Ƚ�arr1��arr2ǰ3���ַ�
//strncpy	�����ض������ַ�������	��strncpy(arr1,arr2,3)����arr2ǰ3���ַ����Ž�arr1
//strncat	׷���ض������ַ�������	��strncat(arr1,arr2,3)��arr2ǰ3���ַ���׷����arr1����Ȼ������һ��\0;

int my_strcmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {
		if(*s1=='\0')
			return 0;
		s1++;
		s2++;
	}
	return *s1-*s2;	
	
}

int main() {
	char arr1[30] = "hellow ";
	char arr2[20] = "word";

	int tmp=my_strcmp(arr1, arr2);
	printf("my_strcmp����ֵ:%d", tmp);
	return 0;
}
