#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define MALLOC(X,BUFF) malloc(X*sizeof(BUFF))

int main(){
	int i = 5;
	int* pc = MALLOC(i, int);
	if (pc == NULL){
		perror("MALLOC");
		return 1;
	}

	free(pc);
	pc == NULL;

	FILE* pt = fopen("test.txt", "r");//���ļ�
	if (pt == NULL) {
		perror("fopen");
		return 1;
	}

	FILE* pf = fopen("test2.txt", "w");//���ļ�
	if (pf == NULL) {
		fclose(pt);
		pt == NULL;
		return 1;
	}

	//�򿪳ɹ�

	//fgetc�����ڶ�ȡ������ʱ��,�᷵��EOF
	//������ȡ��ʱ��,���ص��Ƕ�ȡ�������ַ���ASCLL��ֵ

	//fgets�����ڶ�ȡ������ʱ��,�᷵��NULL
	//���������ʱ�򷵻ش���ַ����ռ����ʼ��ַ

	//frend �����ڶ�ȡ��ʱ��,���ص���ʵ�ʶ�ȡ��������Ԫ�صĸ���
	//������ֶ�ȡ����������Ԫ�صĸ���С��ָ��Ԫ�صĸ���,��������һ�ζ�ȡ

	int ch;
	while ((ch = fgetc(pt)) != EOF)
	{
		//��д�ļ�
		fputc(ch, pf);
		//����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򶼻᷵��EOF
		
	}

	//�ж�ʲôԭ�������
	if (feof(pt))//ferror����ֵΪint ��0
		printf("�����ļ�������׼,�ļ���������");
	else if (ferror(pf)) //��eof�Ƚ�
		printf("�ļ���ȡʧ��");

	//�ر��ļ�
	fclose(pt, pf);
	pt = NULL;
	pf == NULL;
	return 0;
}