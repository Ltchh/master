#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//1:һά���鴫��
int i = 0;
int j = 0;

void test(int arr[]) {//�β�arr[10]�е�10����ʡȥ��д void test(int arr[])
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}//������������=>�������

void test(int arr[10]) {//�����10������ 
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}//������������=>�������

void test(int *arr) {		//arr[i] <= => i[arr] <= => *(arr + i) <= => *(i + arr) <= => *(p + i) <= => *(i + p)--������
	for (i = 0; i < 10; i++) {
		printf("%d ", *(arr+i));
	}

}//������������Ԫ��=>ָ�����

void test_2(int* arr_2[20]) {


}//���鴫��=>�������

void test_2(int* *arr) {

}//����ָ�����

int main() {

	int arr[10] = { 0 };
	int* arr2[20] = { 0 };

	test(arr);

	test_2(arr2);

	return 0;
}

//2:��ά���鴫��

//(1):�����������
void test_1(int arr[3][4]) {
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}//��������Ԫ�ص�ַ=>�����������

void test_1(int arr[][4]) {

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}//��������Ԫ�ص�ַ=�����������

//�ܽ�:��ά���鴫��,�����βε����ֻ��ʡ�Ե�һ��[]������;
//��Ϊ��һ����ά����,���Բ�֪���ж�����,������֪��һ���ж���Ԫ��;
//�������ܷ�������.


//(2):ָ����ʽ����
void test_1(int(*arr_2)[4]) {//*arr_2����4��intԪ��(*arr_2==arr)
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", *((*arr_2 + i) + j));
		}
		printf("\n");//**??<<������Ҫ�����ע>>*((*p + i) + j)
	}

}//�����������ַ=>��������ָ�����


int mian() {

	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };

	test_1(arr);

	return 0;
}

