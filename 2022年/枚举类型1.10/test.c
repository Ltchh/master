#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//枚举
//

//声明枚举类型
enum day {  //enum day 是一个类型 默认0 1 2 3 (递增1);可以自己赋值大小
	RED,	//枚举类型的可能取值
	GREEN,	//常量
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
		printf("请输入:>");
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

//枚举的优点
//1.增加代码的阅读性,可维护行
//2.和#define定义的标识符比较枚举有类型检查,更加严谨
//3.防止了命名污染(封装)
//4.使用方便,一次可以定义多个常量