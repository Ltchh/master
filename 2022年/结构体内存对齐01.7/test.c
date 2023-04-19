#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//结构体成员变量的顺序应该从小到大排列可以减小使用空间
//#pragma pack 可以修改默认对齐数(vs默认对齐数是8,LinX无默认对齐数)


#pragma pack(2)//修改默认对齐数(vs默认对齐数是8,LinX无默认对齐数)
struct S1{
	char ch1;
	int i;
	double ch2;
};
#pragma pack()//结束修改默认对齐数

print0(struct S1 p) {	//传值形参
	printf("%c\n", p.ch1);
}

print1(struct S1* p) {	//传址形参

	printf("%c\n", p->ch1);
}

int main() {

	struct S1 s = { 'c',3,5.2};

	print0(s);//传值
	print1(&s);//传地址


	return 0;
}


//位段
//位段的声明和和结构是类似的,有两个不同
//1.位段的成员必须是int, unsigned int ,signed int(char类型也是int类型)
//2.位段的成员名后面又一个冒号和数字

//一个int类型4个字节,一个字节8个比特位

struct acc {
	int _a : 2;//_a成员占2个比特位
	int _b : 3;//_b成员占3个比特位
	int _c : 20;//_c成员占用20个比特位
}abb;

int main() {

	printf("%d\n",sizeof(abb));
	return 0;
}