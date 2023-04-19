#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//sizeof(������)- ��������ʾ��������-���������������Ĵ�С
//&������ - ��������ʾ������������ -ȡ��������������ĵ�ַ
//����֮��,���е�������������Ԫ�صĵ�ַ

//32λϵͳint��ַ��СΪ4���ֽ� 64λint��ַ��СΪ8���ֽ�
//Ԫ�ش�С��4���ֽ�

int main() {

	int arr[3] = { 0,1,2 };

	printf("sizeof(arr)=%d\n", sizeof(arr));		//����ȥ���������ַ	4*3=12						�����������arrԪ��		arrָ�������������
	printf("sizeof(arr+0)=%d\n", sizeof(arr + 0));		//����ȥ����������Ԫ�ص�ַ							������ǵ�ַarr+0		arr+0ָ�������Ԫ�ص�ַ
	printf("sizeof(*arr)=%d\n", sizeof(*arr));		//����ȥ����������Ԫ��								�����������Ԫ��		*arr����������ĵ�һ��Ԫ��
	printf("sizeof(arr+1)=%d\n", sizeof(arr + 1));		//����ȥ����������һ���������Ԫ�ص�ַ(��Ԫ�ص�ַ)	������������ַ		arr+1ָ����ǵڶ���Ԫ��
	printf("sizeof(arr[1]=)%d\n", sizeof(arr[1]));	//����ȥ��������ڶ���Ԫ��							�����������arr[1]Ԫ��	arr[1]ָ����ǵڶ���Ԫ��

	printf("sizeof(&arr)=%d\n", sizeof(&arr));		//������������ַ4/8			�����������&arr��ַ
	printf("sizeof(*&arr)%d\n", sizeof(*&arr));		//������������С	4*3=12		�����������*&arrԪ��
	printf("sizeof(&arr+1)=%d\n", sizeof(&arr + 1));	//�������һ������Ԫ�ĵ�ַ4/8	�����������&arr+1��ַ
	printf("sizeof(&arr[1])=%d\n", sizeof(&arr[1]));	//������ǵ�ַ4/8				�����������&arr[1]��ַ
	printf("sizeof(arr[1]+1)=%d\n", sizeof(arr[1] + 1));	//arr[2]+1�ĵ�ַ4/8				�����������arr[1]+1��ַ

	char ch[] = { 'a','b','c','d','e','f' };
	printf("sizeof(ch)=%d\n", sizeof(ch));		//����ȥ������Ԫ�ص�ַ			6
	printf("sizeof(ch+0)=%d\n", sizeof(ch + 0));		//����ȥ������Ԫ�ص�ַ			4/8
	printf("sizeof(*ch)=%d\n", sizeof(*ch));		//����ȥ������Ԫ��				1
	printf("sizeof(ch[1])=%d\n", sizeof(ch[1]));		//����ȥ���ǵڶ���Ԫ��			1
	printf("sizeof(&ch=%d\n", sizeof(&ch));		//����ȥ���������ַ			4/8
	printf("sizeof(&ch+1)=%d\n", sizeof(&ch + 1));		//����ȥ������һ������ĵ�ַ	4/8
	printf("sizeof(&ch[0]+1)=%d\n", sizeof(&ch[0] + 1));	//����ȥ���ǵڶ���Ԫ�صĵ�ַ	4/8


	//strlen �����Ĺؼ�����\0	
	printf("strlen(ch)=%d\n", strlen(ch));		//����ȥ������Ԫ�ص�ַ		���ֵ
	printf("strlen(ch+0)=%d\n", strlen(ch + 0));		//����ȥ������Ԫ�ص�ַ		���ֵ
	printf("strlen(*ch)=%d\n", strlen(*ch));		//����ȥ��������Ԫ��		err		����ȥ*ch-(a)��һ������ a��Ϊһ����ַ0x00097	����һ���Ϸ��ĵ�ַ
	printf("strlen(ch[1])=%d\n", strlen(ch[1]));		//����ȥ������ڶ���Ԫ��	err		����ȥ*ch[1]-(b)��һ������ b��Ϊһ����ַ0x00097	����һ���Ϸ��ĵ�ַ
	printf("strlen(&ch)=%d\n", strlen(&ch));		//����ȥ�������ַ			���ֵ	����ȥ��������ָ������
	printf("strlen(&ch+1)=%d\n", strlen(&ch + 1));		//����ȥ����һ�������ַ	���ֵ
	printf("strlen(&ch[0]+1)=%d\n", strlen(&ch[0] + 1));	//����ȥ������Ԫ�ص�ַ		���ֵ


	//�����ʼ��{ 'a','b','c','d','e','f' }��"abcdef"  ��һ����ʲô����ʲô;�ڶ���ĩβ�Զ����"\0"
	char ch1[] = "abcdef";
	printf("(sizeof(ch1))=%d", sizeof(ch1));			//����ȥ�����ַ				7	
	printf("(sizeof(ch1))=%d", sizeof(ch1 + 0));			//����ȥ�����һ��Ԫ�صĵ�ַ	4/8
	printf("(sizeof(ch1))=%d", sizeof(*ch1));			//����ȥ���ǵ�һ��Ԫ��			1
	printf("(sizeof(ch1))=%d", sizeof(ch1[1]));		//����ȥ���ǵڶ���Ԫ��			1
	printf("(sizeof(ch1))=%d", sizeof(&ch1));			//����ȥ��������ĵ�ַ			4/8
	printf("(sizeof(ch1))=%d", sizeof(&ch1 + 1));		//����ȥ������һ������ĵ�ַ	4/8
	printf("(sizeof(ch1))=%d", sizeof(&ch1[0] + 1));		//����ȥ���ǵڶ���Ԫ�صĵ�ַ	4/8

	printf("strlen(ch1)=%d\n", strlen(ch1));				//����ȥ������Ԫ�ص�ַ		6
	printf("strlen(ch1+0)=%d\n", strlen(ch1 + 0));			//����ȥ������Ԫ�ص�ַ		6
	printf("strlen(*ch1)=%d\n", strlen(*ch1));				//����ȥ��������Ԫ��		err		����ȥ*ch-(a)��һ������ a��Ϊһ����ַ0x00097	����һ���Ϸ��ĵ�ַ
	printf("strlen(ch1[1])=%d\n", strlen(ch1[1]));			//����ȥ������ڶ���Ԫ��	err		����ȥ*ch[1]-(b)��һ������ b��Ϊһ����ַ0x00097	����һ���Ϸ��ĵ�ַ
	printf("strlen(&ch1)=%d\n", strlen(&ch1));				//����ȥ�������ַ			6		����ȥ������Ԫ�ص�ַ
	printf("strlen(&ch1+1)=%d\n", strlen(&ch1 + 1));			//����ȥ����һ�������ַ	���ֵ
	printf("strlen(&ch1[0]+1)=%d\n", strlen(&ch1[0] + 1));		//����ȥ������Ԫ�ص�ַ		5

	char* p = "abcdef";
	printf("%d\n", sizeof(p));			//����ȥ����������Ԫ��Ԫ�صĵ�ַ					4/8
	printf("%d\n", sizeof(p + 1));		//����ȥ��������ڶ���Ԫ�صĵ�ַ			4/8
	printf("%d\n", sizeof(*p));			//����ȥ�ĵ�����Ԫ��						1
	printf("%d\n", sizeof(p[0]));		//����ȥ��������Ԫ��						1
	printf("%d\n", sizeof(&p));			//����ȥ����������Ԫ�ص�ַ					4/8
	printf("%d\n", sizeof(&p + 1));		//����ȥ������һ������Ԫ�صĵڶ���Ԫ�ص�ַ	4/8
	printf("%d\n", sizeof(&p[0] + 1));	//����ȥ��������ڶ���Ԫ�صĵ�ַ			4/8

	printf("%d\n", strlen(p));			//����ȥ����������Ԫ�ص�ַ									6			
	printf("%d\n", strlen(p + 1));		//����ȥ��������ڶ���Ԫ�صĵ�ַ							5
	printf("%d\n", strlen(*p));			//����ȥ��������ĵ�һ��Ԫ��								err
	printf("%d\n", strlen(p[0]));		//����ȥ��������ĵ�һ��Ԫ��								err
	printf("%d\n", strlen(&p));			//����ȥ����p�ĵ�ַ											���ֵ
	printf("%d\n", strlen(&p + 1));		//����ȥ��������p����ĵ�ַ									���ֵ
	printf("%d\n", strlen(&p[0] + 1));	//����ȥ����ĵڶ���Ԫ�ص�ַ								5

	return 0;
}