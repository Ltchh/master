#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//����ָ��=>��ź�����ָ��
//����ָ�� int*
//����ָ������ int* arr[5]
//����ָ�� int (*arr)(int , int) 
//����ָ������ int (*arr[2])(int , int)

//int add(int x, int y) {
//	return x + y;
//}
//
//int sub(int x, int y) {
//	return x - y;
//}
//
//
//int main() {
//	int (*pf_1)(int, int) = add;
//	int (*pf_2)(int, int) = sub;
//
//	int (*pf_arr[2])(int, int) = { add,sub };	//����ָ��=>���ͬ���͵ĺ���ָ��  //������������
//	int (*pf_arr[2])(int, int) = { pf_1,pf_2 };	//����һ��ȼ�					  //����ָ�����	
//	return 0;
//}


//��������
//void menu() {
//	printf("**********************\n");
//	printf("**** 1.add  2.sub ****\n");
//	printf("**** 3.mul  4.div ****\n");
//	printf("******  0.exit *******\n");
//	printf("**********************\n");
//}
//int add(int *x, int *y) {
//
//	return *x + *y;
//}
//
//int sub(int* x, int* y) {
//	return *x - *y;
//}
//
//int mul(int* x, int* y) {
//	return *x * *y;
//}
//
//int div(int *x, int* y) {
//	return *x / *y;
//}
//
//
//int main() {
//	int input = 0;
//	
//
//	do {
//		int ret = 0;
//		int x, y;
//		menu();
//		printf("��ѡ��=>:");
//		scanf("%d", &input);
//		
//
//		switch (input) {
//		case 1:
//			printf("����������=>:");
//			scanf("%d %d", &x, &y); 
//			ret = add(&x, &y); break;
//		case 2:
//			printf("����������=>:");
//			scanf("%d %d", &x, &y);
//			ret = sub(&x, &y); break;
//		case 3:
//			printf("����������=>:");
//			scanf("%d %d", &x, &y);
//			ret = mul(&x, &y); break;
//		case 4:
//			printf("����������=>:");
//			scanf("%d %d", &x, &y);
//			ret = div(&x, &y); break;
//		case 0:
//			printf("�˳�����\n");
//			break;
//		default:
//			printf("�������,����������=>\n");
//			break;
//		}
//		if(input>0&&input<5)
//			printf("ret=%d\n", ret);
//	} while (input);
//	return 0;
//}

//����ָ���������
//void menu() {
//	printf("**********************\n");
//	printf("**** 1.add  2.sub ****\n");
//	printf("**** 3.mul  4.div ****\n");
//	printf("******  0.exit *******\n");
//	printf("**********************\n");
//}
//int add(int *x, int *y) {
//
//	return *x + *y;
//}
//
//int sub(int* x, int* y) {
//	return *x - *y;
//}
//
//int mul(int* x, int* y) {
//	return *x * *y;
//}
//
//int div(int* x, int* y) {
//	return *x / *y;
//}
//
//
//int main() {
//	int input = 0;
//
//
//	do {
//		int ret = 0;
//		int x, y;
//		menu();
//		printf("��ѡ��=>:");
//		scanf("%d", &input);
//
//		int (*pt_arr[5])(int*, int*) = { NULL,add,sub,mul,div };
//		//���ֺ�����ַ��ֵ������ָ������,�Ժ���ָ��������ú����ķ�������ת�Ʊ�
//		//pt_arr�Ǻ���ָ������
//
//
//
//		if (input > 0 && input < 5){
//			printf("����������=>:");
//			scanf("%d %d", &x, &y);
//
//			ret = pt_arr[input](&x, &y);
//			printf("ret=%d\n", ret);
//		}
//
//		else if (input == 0)
//			break;
//
//		else
//			printf("ѡ�����!����������=>\n");
//	
//		
//	} while (input);
//	return 0;
//}



//��������
//int arr[5]
//int (*pa)[5]=&arr ȡ�����������ַ
//paָ�������ָ��

//����ָ������
//int* arr[5]
//int* (*pa)[5]=&arr ȡ����������ָ��ĵ�ַ
//paָ��{����ָ������}��ָ��


//����ָ��
//int(*p)(int,int);ȡ�����Ǻ����ĵ�ַ
// pָ�����һ������ָ��

//����ָ������ 
//ȡ����Ҳ�Ǻ���ָ������ĵ�ַ
//int(*parr[5])(int,int);ȡ�����Ǻ�������ĵ�ַ
//parrָ����Ǻ��������ָ��

//int (*(*ppa)[5])(int,int)=&parr;ȡ�����Ǻ���ָ������ĵ�ַ
//ppa����ָ����ָ��������ָ��


//��
//int arr[10]
//����Ԫ������=>int
//arr���������=>int [10]
// 
//��������ָ���������
//int (*p[5])(int, int);
//����ָ������Ԫ������=>int* 
//����ָ��������int(* )(int,int)

//�ص�����:
//    �ص���������һ��ͨ������ָ����õĺ���.�����Ѻ���ָ��(��ַ)��Ϊ�������ݸ���һ��
//����,�����ָ�뱻������������ָ��ĺ���ʱ,���Ǿͳ�Ϊ�ǻص�����,�ص����������ɸú�����
//ʵ�ַ�ֱ�ӵ���,�������ض���ʱ�������������ʱ����һ������,���ڶԸ�ʱ�������������Ӧ
//����: A������ַ����B,A����ָ����Ϊ�ββ��ֳ���;ͨ��B��������A�������ֻ��ƽ���:�ص���������

void menu() {
	printf("**********************\n");
	printf("**** 1.add  2.sub ****\n");
	printf("**** 3.mul  4.div ****\n");
	printf("******  0.exit *******\n");
	printf("**********************\n");
}
int add(int x, int y) {  //�ӷ�����
	return x + y;
}
int sub(int x, int y) {	//��������
	return x - y;
}
int mul(int x, int y) {	//�˷�����
	return x * y;
}
int div(int x, int y) {	//��������
	return x / y;
}
int calc(int(*pf)(int, int)) {
	int x, y;
	char arr = 0;
	printf("����������=>:");
	scanf("%d%c%d", &x, &arr, &y);
	return pf(x, y);//�����ص�����
}
int main() {
	int input = 0;

	do {
		int ret = 0;
		menu();
		printf("��ѡ��=>:");
		scanf("%d", &input);
		switch (input) {
		case 1:
			ret = calc(add); break;//�ӷ�
		case 2:
			ret = calc(sub); break;//����
		case 3:
			ret = calc(mul); break;//�˷�
		case 4:
			ret = calc(div); break;//����
		case 0:
			printf("�˳�����\n"); break;
		default:
			printf("�������,����������=>\n"); break;
		}
		if (input > 0 && input < 5)
			printf("ret=%d\n", ret);
	} while (input);
	return 0;
}
