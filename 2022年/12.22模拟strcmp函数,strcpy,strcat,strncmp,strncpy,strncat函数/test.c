#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//strlen 计算字符串函数
//strcmp	比较字符串函数	例strcmp(arr1,arr2)=>arr>arr2返回值大于0;arr1<arr2返回值小于0;arr1=arr2返回值为0;
//strcpy	拷贝字符串函数	例strcpy(arr1,arr2)=>把arr2拷贝进arr1;
//strcat	追加字符串函数	例strcat(arr1,arr2)=>把arr2追加在arr1后面

//strncmp	比较特定个数字符串函数	例strncmp(arr1,arr2,3)比较arr1与arr2前3个字符
//strncpy	拷贝特定个数字符串函数	例strncpy(arr1,arr2,3)拷贝arr2前3个字符串放进arr1
//strncat	追加特定个数字符串函数	例strncat(arr1,arr2,3)把arr2前3个字符串追加在arr1后面然后会添加一个\0;

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
	printf("my_strcmp返回值:%d", tmp);
	return 0;
}
