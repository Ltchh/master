#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define CODE 10

int main() {

	FILE* ptr = fopen("beautiful.txt","r");	//���ļ� ��
	if (NULL == ptr) {
		perror("ptr fopen failure!");
		return;
	}

	FILE* pta = fopen("beautiful-1.txt", "w");	//���ļ� д
	if (NULL==pta){
		perror("pta fopen failure");
		return;
	}

	char ch;

	
	while (ch = fgetc(ptr) != EOF) { //fgetc��ȡ�ļ�һ���ַ���ֵ��ch
		
		ch += CODE;				  //�Ը��ַ���10��ֵ��ch
		fputc(ch, pta);			  //fputcд���ļ� ch�ж�ȡһ���ַ�д�뵽pta;
	}

	fclose(ptr);	//�ر��ļ�	
	fclose(pta);

	return 0;
}

//�����������