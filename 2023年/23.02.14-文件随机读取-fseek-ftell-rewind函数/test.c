#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//�µ���
//stream	��
//offset	����(ƫ����)
//origin	��Դ(��ʼλ��)


void my_fseek(FILE* pf) {
	

	//��ȡ�ļ�
	int ch = fgetc(pf);
	printf("%c", ch);
	fseek(pf, 5, SEEK_CUR); //-1��ǰ��һλ 1�������һλ->��ȡpf�ļ���ʼλ��ƫ����Ϊ5���ַ�
	//����:pf�ļ�ָ��,-1��ƫ����,SEEK_CURƫ�Ʒ���
	//int fseek(FILE* stream,long offset,int origin);

	//�����ļ�ָ��
	//SEEK_CUR		��ǰ�ļ�ָ���λ��
	//SEEK_END		�ļ�ĩβ
	//SEEK_SET		�ļ���ʼλ��

	ch = fgetc(pf);
	printf("%c", ch);

	ch = fgetc(pf);
	printf("%c", ch);
}

int my_ftell(FILE* pf) {//����ֵΪint����->��ȡ�ļ�fseek������ƫ����
	int num=ftell(pf);
	return num;
}

void my_rewind() {
	//fgetc�����ڶ�ȡ������ʱ��,�᷵��EOF
	//������ȡ��ʱ��,���ص��Ƕ�ȡ�������ַ���ASCLL��ֵ

	//fgets�����ڶ�ȡ������ʱ��,�᷵��NULL
	//���������ʱ�򷵻ش���ַ����ռ����ʼ��ַ

	//frend �����ڶ�ȡ��ʱ��,���ص���ʵ�ʶ�ȡ��������Ԫ�صĸ���
	//������ֶ�ȡ����������Ԫ�صĸ���С��ָ��Ԫ�صĸ���,��������һ�ζ�ȡ

}

int main() {
	FILE* pf = fopen("fseek_file.dat", "r");//��-ֻ��
	if (pf == NULL) {
		perror("fopen");
		return;
	}

	my_fseek(pf);//�ļ������ȡ��λ->�����ı�ƫ������ȡ

	int num = my_ftell(pf);//����ֵΪint����->��ȡ�ļ�fseek������ƫ����
	printf("\n%d\n", num);

	void my_rewind(pf);//�ж��ļ���������ֵ
	//��תteat.txt����һ������һ��test2.txt�ļ�

	fclose(pf);//�ر�
	pf = NULL;

	return 0;
}

