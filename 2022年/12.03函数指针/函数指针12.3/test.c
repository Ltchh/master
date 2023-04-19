#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

////函数指针:存放函数的指针
////&函数名-取到的是函数的地址
////数组名 != &数组名 (arr != &arr)
////函数名 == &函数名	(sum == &sum)
//
////*指针符号小于()运算级别 =>重点
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
//	printf("%p\n", sum1);//sum1==&sum1//数组名!=&数组名
//	printf("%p\n", &sum1);//
//
//	int (*pa)(int*, int*) = &sum1;//pa就是函数指针变量
//	//int是函数返回类型
//	//(*pa)指向函数的地址
//	//(int* , int*)是函数内部参数类型
//
//
//
//	int x = 6, y = 7;
//
//	int sum2 = (*pa)(&x, &y); //调用这函数					1
//	//int sum2 =pa(&x, &y);		sum1==&sum1那么pa==add		2
//	//int sum2=add(&x, &y)      常规调用					3 这3种一模一样
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


//函数调用
int test_1(int x, int y) {
	return x + y;
}
int main() {

	int(*tes_1)(int ,int) = &test_1;//tes_1==test_1
	//等价于int(*tes_1)(int, int) = test_1;
	
	//调用函数指针
	int ret = test_1(3, 5);		//正常函数调用
	int ret = (*tes_1)(3, 5);	//指针函数调用	(*可以省,最好别偷懒)
	//不可写成 int ret = *tes_1(3,5); 
	//=>因为 括号的运算级别高于指针符号会先读取tes_1(3,5),然后解引用; 
	int ret = tes_1(3, 5);		//进化版函数调用(演化版)

	printf("%d \n", ret);
	return 0;
}

//// ( * ( void ( * )( ) ) 0 ) (  );
////	1.void ( *  ) (  )			函数指针类型
////	2.void ( *  ) (  ) 0		对0强制转换,被解释为一个函数地址
////	3.*void ( *  ) (  ) 0		对0地址进行解引用操作
////	4.(*void ( *  ) (  ) 0 )(  )调用0地址处函数
//// 出处<<c陷阱和缺陷>>

void (*signal(int, void(*)(int)))(int);
//1.signal和( )先结合,说明signal是一个函数名
//2.signal函数的第一个参数是int,第二个参数类型是函数指针
//	该函数指针指向一个参数为int返回类型是viod的函数
//3.signal函数的返回类型也是一个函数指针
//	该函数指针,指向一个参数为int,返回类型是void的函数
//4.signal是一个函数声明

//演化
void (*signal(int, void(*)(int)))(int);
void(*)(int)(signal(int, void(*)(int));//语法不允许这样写

//typedef- 对类型重新定义/重命名

typedef void(*)(int) pfun_t; //对函数指针类型重命名为pfun_t
//类比:typedef nusigned int uint;
typedef void(*pfun_t)(int);

pfun_t signal(int, pfun_t);


