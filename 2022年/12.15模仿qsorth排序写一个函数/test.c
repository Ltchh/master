#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

swap(char* buf1, char* buf2,size_t size) {
	for (int i = 0; i < size; i++) {
		int tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}

}

int short_sort(void* base, size_t num, size_t size, int(*comper)(const void* e1, const void* e2)) {
	for (int i = 0; i < num; i++) {	//躺数
		for (int j = 0; j < num - i - 1; j++) {//一趟排序交换
			
			//两个元素比较
			if (comper( (char*)base+j*size,(char*)base+(j+1)*size ) > 0) {
				//交换
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}

	}
}

print(const int*  arr, int* sz) {
	for (int i = 0; i < *sz; i++) {
		printf("%d ", *(arr + i));
	}
}

int comper(const void* e1, const void* e2) {

	return *(int*)e1 - *(int*)e2;
}

void test1() {
	int arr[10] = { 9,8,7,6,5,4,3,2,1 ,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	short_sort(arr, sz, sizeof(arr[0]), comper);

	print(arr, &sz);
}

struct student {
	char name[10];//姓名

	int arr;//年纪
};

int comper_test_2_name(const void* e1, const void* e2) {

	return strcmp(((struct student*)e2)->name, ((struct student*)e1)->name);
}
void test2() {
	
	struct student stu[3] = { {"wanling",26}, {"zha",23}, {"cuim",29}};//结构体初始化
	int sz = sizeof(stu) / sizeof(stu[0]);
	short_sort(stu, sz, sizeof(stu[0]), comper_test_2_name);

}
void comper_test_2_age(const void* e1, const void* e2) {
	return (((struct student*)e1)->arr-((struct student*)e2)->arr);
}

void test3() {
	struct student stu[3] = { {"wanling",26}, {"zha",23}, {"cuim",29} };//结构体初始化
	int sz = sizeof(stu) / sizeof(stu[0]);
	short_sort(stu, sz, sizeof(stu[0]), comper_test_2_age);
}
int main() {
	test1();
	//test2();
	//test3();
	return 0;
}