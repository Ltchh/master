#define  _CRT_SECURE_NO_WARNINGS

#include"struct.h"

void initnumber(class* number) {
	number->stru = (strudent*)malloc(4 * sizeof(strudent));//��������ڶ����濪�ٿռ�û�г�ʼ��0ַ���涼�����ֵ
	number->stru = (strudent*)calloc(4, sizeof(strudent));//�⺯���ڶ����濪�ٿռ��ʼ��0ֵ; 
	if (number->stru == NULL) {
		perror("initnumber");
		return ;
	}

	number->people = 0;
	number->capacity = 3;
}
void addnumber(class* number) {
	
	
	if (number->people == number->capacity) {
		strudent* ptr = (strudent*)realloc(number->stru, CAP_Y * sizeof(strudent));
		if (ptr != NULL) {
			number->stru = ptr;
			number->capacity += CAP_Y;
		}
		else
		{
			preor("addnumber");
		}
		return;
	}
}