#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>

//�µ���
//position λ��
//start	��ʼ 

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
	int len=strlen(arr1);//�����ַ�������										ע���ַ�������������Ĭ�ϵ�/0	
	int len1 = strcmp(arr1,arr2);//�Ƚ��ַ�����������ֵ  //arr1>arr2����ֵΪ1;	ע���ַ�������������Ĭ�ϵ�/0
													     //arr1<arr2����ֵΪ-1;
														 //arr1=arr2����ֵΪ0;
	//printf("strlen=%d,strcmp=%d\n", len, len1);

	//strcpy(arr1,arr2);	//�����ַ���		��arr1������arr1;					ע���ַ�������������Ĭ�ϵ�/0
	//printf("%s\n", arr1);
	//strcat(arr1, arr2);	//׷���ַ���		��arr2׷�Ӹ�arr1����;				ע���ַ�������������Ĭ�ϵ�/0
	//printf("%s\n",arr1);

	//my_strcat(arr1, arr2);//�Լ�ģ��
	my_strcat_1(arr1, arr2);//��ʦģ��
	printf("%s\n", arr1);
	return 0;
}