#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//�ṹ���Ա������˳��Ӧ�ô�С�������п��Լ�Сʹ�ÿռ�
//#pragma pack �����޸�Ĭ�϶�����(vsĬ�϶�������8,LinX��Ĭ�϶�����)


#pragma pack(2)//�޸�Ĭ�϶�����(vsĬ�϶�������8,LinX��Ĭ�϶�����)
struct S1{
	char ch1;
	int i;
	double ch2;
};
#pragma pack()//�����޸�Ĭ�϶�����

print0(struct S1 p) {	//��ֵ�β�
	printf("%c\n", p.ch1);
}

print1(struct S1* p) {	//��ַ�β�

	printf("%c\n", p->ch1);
}

int main() {

	struct S1 s = { 'c',3,5.2};

	print0(s);//��ֵ
	print1(&s);//����ַ


	return 0;
}


//λ��
//λ�ε������ͺͽṹ�����Ƶ�,��������ͬ
//1.λ�εĳ�Ա������int, unsigned int ,signed int(char����Ҳ��int����)
//2.λ�εĳ�Ա��������һ��ð�ź�����

//һ��int����4���ֽ�,һ���ֽ�8������λ

struct acc {
	int _a : 2;//_a��Առ2������λ
	int _b : 3;//_b��Առ3������λ
	int _c : 20;//_c��Առ��20������λ
}abb;

int main() {

	printf("%d\n",sizeof(abb));
	return 0;
}