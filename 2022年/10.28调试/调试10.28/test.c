#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

//***************新单词*******************
//
//debug		调试版本    (可以调试 保函调试信息,并且不做优化,便于程序员调试程序)
//release   发布版本	(不可以调试,被优化,速度上更快,以便用户更好使用)
//src		来源
//dest(destination)	目的地
//count		计数
//const		关键字 (不允许更改的内容)

//int main() {
//	int arr[10]={0};
//
//	int size = sizeof(arr) / sizeof(arr[0]);
//	
//	int i = 0;
//
//	for (int *p = arr; p < &arr[10];i++ ) {
//		
//		*p++ = i;
//		printf("%d\n", arr[i]);
//	}
//	
//	return 0;
////}
//void test3() {
//	printf("王八蛋\n");
//}
//
//void test2() {
//	test3();
//}
//
//void test1()
//	{
//		test2();
//	}
//
//int main() {
//	test1();
//	
//	return 0;
//}


////例1
//void my_strcpy(char* arr1, char* arr2) {
//
//	while (*arr1 != '\0') {
//		*arr1 = *arr2;
//		*arr1++ = *arr2++;
//	}
//	*arr1 = *arr2;
//}

//演化1
//void my_strcpy(char* arr1, char* arr2) {
//
//	while (*arr1 != '\0') {
//		*arr1++ = *arr2++;
//	}
//	*arr1 = *arr2;
//}

////演化2
//void my_strcpy(char* arr1, char* arr2) {
//	while (*arr1++ = *arr2++);//*arr1=*arr2----*arr2里的'\0'赋值给*arr1后 *arr1=*arr2为'\0';'\0'为假跳出循环
//		
//}
//
//int main() {
//
//	char arr1[12] = "xxxxxxxxxxx";
//	char arr2[] = "hello word";
//
//	/*strcpy(arr1, arr2)*/;
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//int main() {
//	int n = 100;
//	const int arr = 10;		//const修饰变量 变量可以不可以做更改
//	//arr = 20; 无法赋值常量更改arr的数值
//	int* dest = &arr;
//	//*dest = 20;  //通过指针变量赋值改变arr的赋值
//
//	const int *p = dest;	//const修饰指针变量 指针变量不可以做更改,但是指针内容可以做更改
//	//*p = 30; 无法通过指针 解引用更改arr的数值
//	//p = &n;	但是指针内容可以做更改
//	printf("%d\n", arr);
//	return 0;
//}
//
//void my_strcpy(char*  dest, const char* src) {
//	//const 修饰指针:表示指针变量不能被更改,但是指针内容可以不改变
//	//const char *src:  const修饰内容是*src 
//	while ( *dest++ = *src++);
//}
// 
//int main() {
//	char arr1[20] = { 0 };
//	char arr2[15] = "hello word";
//
//	my_strcpy(arr1, arr2);
//
//	printf("%s\n", arr1);
//	return 0;
//}
int my_strlen(const char* dest) {//const  *dest不允许更改其内容

	assert(dest);//断言

	int count = 0;//计数
	while(*dest++ != '\0') {
		count++;
	}
	return count;
}
int main() {
	char ch[] = "hello word";
	
	/*my_strlen(ch);*/
	printf("%d\n", my_strlen(ch));
	return 0;
}