#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//ö��
//

//����ö������
enum day {  //enum day ��һ������ Ĭ��0 1 2 3 (����1);�����Լ���ֵ��С
	RED,	//ö�����͵Ŀ���ȡֵ
	GREEN,	//����
	BLUE
};

void menu() {
	printf("*********************************\n");
	printf("****     1.add    2.sub      ****\n");
	printf("****     3.mul    4.div      ****\n");
	printf("****     0.exit              ****\n");
	printf("*********************************\n");

}

enum option 
{
	exit,//0
	add,//1
	sub,//2
	mul,//3
	div,//4
};

int main() {
	
	int input = 0;
	menu();
	
	do {
		printf("������:>");
		scanf("%d", &input);
		switch (input) {

		case add:
			break;
		case sub:
			break;
		case mul:
			break;
		case div:
			break;
		default:
			break;

		}

	} while (input);
	return 0;
}

//ö�ٵ��ŵ�
//1.���Ӵ�����Ķ���,��ά����
//2.��#define����ı�ʶ���Ƚ�ö�������ͼ��,�����Ͻ�
//3.��ֹ��������Ⱦ(��װ)
//4.ʹ�÷���,һ�ο��Զ���������