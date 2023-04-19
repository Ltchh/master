#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//单词
//Structure  结构体

//整形数组排序(升序)

void print(int* pe, int* sz) {
	for (int i = 0; i < *sz; i++) {
		printf("%d ", pe[i]);
	}
	printf("\n");
}

int compare(const void* e1, const void* e2) {

	return *(int*)e1 - *(int*)e2;//反序*(int*)e2 - *(int*)e1
}

int main() {
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]), compare);

	print(arr, &sz);
	return 0;
}

//结构体数组排序(升序)

//结构体->年龄排序(1)
struct student {	//结构体
	char arr[10];	//姓名
	int age;		//年龄

};

int sort_age(const void* e1, const void* e2) {	//qsort函数指针内容		(!1)

	return ((struct student *)e1)->age - ((struct student*)e2)->age;//返回值  //反序((struct student *)e2)->age - ((struct student*)e1)->age
}
void test() {
	
	struct student stu[3] = { {"wangfang",25} ,{"zhangqiang",26}, {"liying",31}};//结构体初始化
	
	int sz = sizeof(stu) / sizeof(stu);	//计算数组元素个数
	
	//年龄排序
	qsort(stu, sz, sizeof(stu[0]), sort_age);//传参 首元素地址,元素个数,元素类型大小,比较函数指针=>(!1)
}

int main() {

	test();
	
	return 0;
}

//结构体->姓名排序(2)
struct student {
	char name[20];
	int age;
};

int sort_by_name(const void* e1, const void* e2) {

	return   strcmp(((struct student*)e1)->name, ((struct student*)e2)->name); //反序((struct student *)e2)->age - ((struct student*)e1)->age
}

test() {
	
	struct student sort[3] = { { "wangfangfang",31 }, { "lidaying",26 }, { "xiaolizhi",29 } };
	
	int sz = sizeof(sort) / sizeof(sort[0]);
		
	qsort(sort, sz, sizeof(sort[0]), sort_by_name);
}

int main() {
	test();

	return 0;
}