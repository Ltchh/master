#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

//***************�µ���*******************
//
//debug		���԰汾    (���Ե��� ����������Ϣ,���Ҳ����Ż�,���ڳ���Ա���Գ���)
//release   �����汾	(�����Ե���,���Ż�,�ٶ��ϸ���,�Ա��û�����ʹ��)
//src		��Դ
//dest(destination)	Ŀ�ĵ�
//count		����
//const		�ؼ��� (��������ĵ�����)

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
//	printf("���˵�\n");
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


////��1
//void my_strcpy(char* arr1, char* arr2) {
//
//	while (*arr1 != '\0') {
//		*arr1 = *arr2;
//		*arr1++ = *arr2++;
//	}
//	*arr1 = *arr2;
//}

//�ݻ�1
//void my_strcpy(char* arr1, char* arr2) {
//
//	while (*arr1 != '\0') {
//		*arr1++ = *arr2++;
//	}
//	*arr1 = *arr2;
//}

////�ݻ�2
//void my_strcpy(char* arr1, char* arr2) {
//	while (*arr1++ = *arr2++);//*arr1=*arr2----*arr2���'\0'��ֵ��*arr1�� *arr1=*arr2Ϊ'\0';'\0'Ϊ������ѭ��
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
//	const int arr = 10;		//const���α��� �������Բ�����������
//	//arr = 20; �޷���ֵ��������arr����ֵ
//	int* dest = &arr;
//	//*dest = 20;  //ͨ��ָ�������ֵ�ı�arr�ĸ�ֵ
//
//	const int *p = dest;	//const����ָ����� ָ�����������������,����ָ�����ݿ���������
//	//*p = 30; �޷�ͨ��ָ�� �����ø���arr����ֵ
//	//p = &n;	����ָ�����ݿ���������
//	printf("%d\n", arr);
//	return 0;
//}
//
//void my_strcpy(char*  dest, const char* src) {
//	//const ����ָ��:��ʾָ��������ܱ�����,����ָ�����ݿ��Բ��ı�
//	//const char *src:  const����������*src 
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
int my_strlen(const char* dest) {//const  *dest���������������

	assert(dest);//����

	int count = 0;//����
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