#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

////����ָ��:��ź�����ָ��
////&������-ȡ�����Ǻ����ĵ�ַ
////������ != &������ (arr != &arr)
////������ == &������	(sum == &sum)
//
////*ָ�����С��()���㼶�� =>�ص�
//
//int sum1(int* x, int* y) {
//	return (*x + *y);
//}
//int main() {
//
//	int a = 2;
//	int b = 1;
//
//	printf("%d\n", sum1(&a, &b));
//
//	printf("%p\n", sum1);//sum1==&sum1//������!=&������
//	printf("%p\n", &sum1);//
//
//	int (*pa)(int*, int*) = &sum1;//pa���Ǻ���ָ�����
//	//int�Ǻ�����������
//	//(*pa)ָ�����ĵ�ַ
//	//(int* , int*)�Ǻ����ڲ���������
//
//
//
//	int x = 6, y = 7;
//
//	int sum2 = (*pa)(&x, &y); //�����⺯��					1
//	//int sum2 =pa(&x, &y);		sum1==&sum1��ôpa==add		2
//	//int sum2=add(&x, &y)      �������					3 ��3��һģһ��
//	//
//
//	printf("%d\n", sum2);
//
//	
//
//	return 0;
//}
//
//


//��������
int test_1(int x, int y) {
	return x + y;
}
int main() {

	int(*tes_1)(int ,int) = &test_1;//tes_1==test_1
	//�ȼ���int(*tes_1)(int, int) = test_1;
	
	//���ú���ָ��
	int ret = test_1(3, 5);		//������������
	int ret = (*tes_1)(3, 5);	//ָ�뺯������	(*����ʡ,��ñ�͵��)
	//����д�� int ret = *tes_1(3,5); 
	//=>��Ϊ ���ŵ����㼶�����ָ����Ż��ȶ�ȡtes_1(3,5),Ȼ�������; 
	int ret = tes_1(3, 5);		//�����溯������(�ݻ���)

	printf("%d \n", ret);
	return 0;
}

//// ( * ( void ( * )( ) ) 0 ) (  );
////	1.void ( *  ) (  )			����ָ������
////	2.void ( *  ) (  ) 0		��0ǿ��ת��,������Ϊһ��������ַ
////	3.*void ( *  ) (  ) 0		��0��ַ���н����ò���
////	4.(*void ( *  ) (  ) 0 )(  )����0��ַ������
//// ����<<c�����ȱ��>>

void (*signal(int, void(*)(int)))(int);
//1.signal��( )�Ƚ��,˵��signal��һ��������
//2.signal�����ĵ�һ��������int,�ڶ������������Ǻ���ָ��
//	�ú���ָ��ָ��һ������Ϊint����������viod�ĺ���
//3.signal�����ķ�������Ҳ��һ������ָ��
//	�ú���ָ��,ָ��һ������Ϊint,����������void�ĺ���
//4.signal��һ����������

//�ݻ�
void (*signal(int, void(*)(int)))(int);
void(*)(int)(signal(int, void(*)(int));//�﷨����������д

//typedef- ���������¶���/������

typedef void(*)(int) pfun_t; //�Ժ���ָ������������Ϊpfun_t
//���:typedef nusigned int uint;
typedef void(*pfun_t)(int);

pfun_t signal(int, pfun_t);


