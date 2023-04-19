#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//函数指针=>存放函数的指针
//整形指针 int*
//整形指针数组 int* arr[5]
//函数指针 int (*arr)(int , int) 
//函数指针数组 int (*arr[2])(int , int)

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
//	int (*pf_arr[2])(int, int) = { add,sub };	//函数指针=>存放同类型的函数指针  //正常函数调用
//	int (*pf_arr[2])(int, int) = { pf_1,pf_2 };	//和上一句等价					  //函数指针调用	
//	return 0;
//}


//正常调用
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
//		printf("请选择=>:");
//		scanf("%d", &input);
//		
//
//		switch (input) {
//		case 1:
//			printf("输入两个数=>:");
//			scanf("%d %d", &x, &y); 
//			ret = add(&x, &y); break;
//		case 2:
//			printf("输入两个数=>:");
//			scanf("%d %d", &x, &y);
//			ret = sub(&x, &y); break;
//		case 3:
//			printf("输入两个数=>:");
//			scanf("%d %d", &x, &y);
//			ret = mul(&x, &y); break;
//		case 4:
//			printf("输入两个数=>:");
//			scanf("%d %d", &x, &y);
//			ret = div(&x, &y); break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("输入错误,请重新输入=>\n");
//			break;
//		}
//		if(input>0&&input<5)
//			printf("ret=%d\n", ret);
//	} while (input);
//	return 0;
//}

//函数指针数组调用
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
//		printf("请选择=>:");
//		scanf("%d", &input);
//
//		int (*pt_arr[5])(int*, int*) = { NULL,add,sub,mul,div };
//		//这种函数地址赋值给函数指针数组,以函数指针数组调用函数的方法就是转移表
//		//pt_arr是函数指针数组
//
//
//
//		if (input > 0 && input < 5){
//			printf("输入两个数=>:");
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
//			printf("选择错误!请重新输入=>\n");
//	
//		
//	} while (input);
//	return 0;
//}



//整形数组
//int arr[5]
//int (*pa)[5]=&arr 取出的是数组地址
//pa指向数组的指针

//整形指针数组
//int* arr[5]
//int* (*pa)[5]=&arr 取出的是数组指针的地址
//pa指向{整形指针数组}的指针


//函数指针
//int(*p)(int,int);取出的是函数的地址
// p指向的是一个函数指针

//函数指针数组 
//取出的也是函数指针数组的地址
//int(*parr[5])(int,int);取出的是函数数组的地址
//parr指向的是函数数组的指针

//int (*(*ppa)[5])(int,int)=&parr;取处的是函数指针数组的地址
//ppa就是指向函数指针的数组的指针


//例
//int arr[10]
//数组元素类型=>int
//arr数组的类型=>int [10]
// 
//衍生函数指针数组理解
//int (*p[5])(int, int);
//函数指针数组元素类型=>int* 
//函数指针类型是int(* )(int,int)

//回调函数:
//    回调函数就是一个通过函数指针调用的函数.如果你把函数指针(地址)作为参数传递给另一个
//函数,当这个指针被用来调用其所指向的函数时,我们就称为是回调函数,回调函数不是由该函数的
//实现方直接调用,而是在特定的时间或者条件发生时由另一方调用,用于对该时间或条件进行响应
//例如: A函数地址传给B,A函数指针作为形参部分出现;通过B函数访问A函数这种机制叫做:回调函数机制

void menu() {
	printf("**********************\n");
	printf("**** 1.add  2.sub ****\n");
	printf("**** 3.mul  4.div ****\n");
	printf("******  0.exit *******\n");
	printf("**********************\n");
}
int add(int x, int y) {  //加法函数
	return x + y;
}
int sub(int x, int y) {	//减法函数
	return x - y;
}
int mul(int x, int y) {	//乘法函数
	return x * y;
}
int div(int x, int y) {	//除法函数
	return x / y;
}
int calc(int(*pf)(int, int)) {
	int x, y;
	char arr = 0;
	printf("输入两个数=>:");
	scanf("%d%c%d", &x, &arr, &y);
	return pf(x, y);//函数回调机制
}
int main() {
	int input = 0;

	do {
		int ret = 0;
		menu();
		printf("请选择=>:");
		scanf("%d", &input);
		switch (input) {
		case 1:
			ret = calc(add); break;//加法
		case 2:
			ret = calc(sub); break;//减法
		case 3:
			ret = calc(mul); break;//乘法
		case 4:
			ret = calc(div); break;//除法
		case 0:
			printf("退出程序\n"); break;
		default:
			printf("输入错误,请重新输入=>\n"); break;
		}
		if (input > 0 && input < 5)
			printf("ret=%d\n", ret);
	} while (input);
	return 0;
}
