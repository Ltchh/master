#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//memset �ڴ����ú���-���ֽ�Ϊ��λ�����ڴ�
//void memset(viod*ptr,int value ,size_t num);
//ptr->�������Ԫ�ص�ַ
//value->��Ҫ���õĳ���
//num->��Ҫ���ñ����ĸ���


void my_print(int(*p)[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//printf("%d ", *((*p + i) + j));
			//printf("%d ",(*p + i)[j]);
			printf("%d ", p[i][j]);

		}
		printf("\n");
	}
}

int main() {

	int arr[5][5];
	int num = sizeof(arr);
	memset(arr, 0,num);

	my_print(arr);


	return 0;
}