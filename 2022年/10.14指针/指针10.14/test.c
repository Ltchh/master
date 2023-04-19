#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//****************************************************************
//** p���ǽ����ã���ָ���ַ��Ӧ�����ݣ�p��ָ��������ŵ�ַ��   **
//**															**
//****************************************************************
//int main()
//{
//	int arr[10] = { 0 };
//	int* pc = arr;
//	
//	for (int i = 0,j=0; i < 10; i++) {
//		*(pc + i) = j++;
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


//ָ���ָ���������ָ��֮���Ԫ��
// ����ָ�����ָ��ͬһ���ռ���ܼ���
//int main() {
//	int arr[10] = { 0 };
//	
//	printf("%d\n", &arr[10]-&arr[0]);
//	return 0;
//}
//int my_strlen(char* str) {
//	int count = 0;
//	while (*str != '\0') {
//		count++;
//		*str++;
//	}
//	return count;
//}
//int main() {
//
//	char ch[] = "abc";
//	int len = my_strlen(ch);
//	int str_1 = strlen(ch);
//	printf("%d\n", str_1);
//	printf("%d\n", len);
//	return 0;
//}


//����ָ�����
//int my_strlen(char* arr) {
//	char* strlen_1 = arr;
//	while (*arr != '\0') {
//		arr++;
//	}
//	return arr - strlen_1;
//}
//int main() {
//	
//	
//	int len_1 = my_strlen("arr");
//
//	printf("%d\n", len_1);
//
//	return 0;
//}

//int main() {
//	int arr[10] = { 0 };
//	int* p = arr;
//	
//	for (int i = 0; i < 10; i++) {
//		printf("%p==%p\n", &arr[i], p + i);
//	}
//	return 0;
//}
//ָ������
//int main() {
//	int arr[5] = { 0 };//��ŵ�����������
//	char ch[5] = { 0 };//��ŵ����ַ�����
//	int* parr[5];		//��ŵ�������ָ������
//	int* char[5];		//��ŵ����ַ�ָ������
//}\


//ָ������
#define N_VALUES 5 

//int main() {		//ָ��Ϊ�����ʼ�� 
//	int values[N_VALUES];
//	int* vp;
//	for (vp = &values[0]; vp < &values[N_VALUES];) {   //ָ���߼�����
//		*vp++ = 0;				//ָ��+����
//	}
//	for (int i = 0; i < N_VALUES; i++) {
//		printf("%d ", values[i]);
//	}
//		return 0;
//}

int main() {
	int values[N_VALUES];
	int* vp;

	for (vp = &values[N_VALUES]; vp > &values[0];) {
		*vp-- = 0;
		printf("%d \n",*vp);
	}

	return 0;
}