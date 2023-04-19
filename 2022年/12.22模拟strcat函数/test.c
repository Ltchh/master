#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>

//新单词
//position 位置
//start	起始 

char* my_strcat(char* position, const char* start) {
	assert(position && start);
	char* pos = position;
	while (*start) {
		*position++;
		if (*position == '\0') {
			*position = *start;
			start++;
			if (start == '\0')
				break;
		}

	}
	return pos;
}

char* my_strcat_1(char* dest,const char* src)	
{
	
	assert(dest && src);
	char* tmp1 = dest;
	while (*dest) {
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return tmp1;
}

int main() {
	char arr1[30] = "hello ";
	char arr2[5] = "word";
	int len=strlen(arr1);//计算字符串长度										注意字符串的最后必须有默认的/0	
	int len1 = strcmp(arr1,arr2);//比较字符串函数返回值  //arr1>arr2返回值为1;	注意字符串的最后必须有默认的/0
													     //arr1<arr2返回值为-1;
														 //arr1=arr2返回值为0;
	//printf("strlen=%d,strcmp=%d\n", len, len1);

	//strcpy(arr1,arr2);	//拷贝字符串		把arr1拷贝给arr1;					注意字符串的最后必须有默认的/0
	//printf("%s\n", arr1);
	//strcat(arr1, arr2);	//追加字符串		把arr2追加给arr1后面;				注意字符串的最后必须有默认的/0
	//printf("%s\n",arr1);

	//my_strcat(arr1, arr2);//自己模拟
	my_strcat_1(arr1, arr2);//老师模拟
	printf("%s\n", arr1);
	return 0;
}