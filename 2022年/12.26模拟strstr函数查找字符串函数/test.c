#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>//断言

//strstr 查找字符串函数
//例:strstr(arr1,arr2)在arr1中查找arr2字符串找到返回arr1中arr2的位置指针未找到返回一个空指针
char* my_strstr(const char* str1, const char* str2) {
	assert(str1 && str2);
	char* sp1 = NULL;
	char* sp2 = NULL;
	char* cmp = str1;
	if (*str2 == '\0') {
		return (char*)str1;
	}
	while (*cmp) {
		sp1 = cmp;
		sp2 = str2;
		while (*sp1 != '\0' && *sp2 != '\0' && (*sp1 == *sp2)) {//(*sp1&&*sp2&&(*sp1==*sp2))
			sp1++;
			sp2++;
		}
		if (*sp2 == '\0') {
			return (char *)cmp;
		}
		cmp++;
	}
	return NULL;
}
int main() {

	char arr1[40] = "hello word";
	char arr2[4] = "llo";

	char* ret = my_strstr(arr1, arr2);
	if (ret == NULL) {
		printf("没找到\n");
	}
	else
		printf("找到了\n%s", ret);
	return 0;
}