#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//联合体类型(共用体类型)
//联合也是一种特殊的自定义类型
//这种类型的变量也包含了一系列的成员,特殊是这些成员变量共用同一块空间()所以联合体也叫做共用体
//联合体的大小,至少是最大成员类型的大小(因为联合体至少有保存最大的那个成员变量)
// 当最大成员大小不是最大对齐数的整数倍数的时候,就要对齐到最大对齐数的整数倍数

union un {//联合体类型的声明
	char c;
	int i;
};

void print (union un * p) {
	printf("%p\n", p);
}

int main() {

	union un u = {10};		//联合体变量的定义/初始化

	//同一个时间只能使用同一个值
	u.c = 'b';
	u.i = 6;

	printf("%d\n", sizeof(u));//计算空间 

	print(&u);
	print(&(u.c));
	print(&(u.i));


	return 0;
}