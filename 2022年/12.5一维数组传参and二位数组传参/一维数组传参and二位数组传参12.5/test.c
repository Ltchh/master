#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//1:一维数组传参
int i = 0;
int j = 0;

void test(int arr[]) {//形参arr[10]中的10可以省去不写 void test(int arr[])
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}//传过来数组名=>数组接收

void test(int arr[10]) {//这里的10无意义 
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}//传过来数组名=>数组接收

void test(int *arr) {		//arr[i] <= => i[arr] <= => *(arr + i) <= => *(i + arr) <= => *(p + i) <= => *(i + p)--解引用
	for (i = 0; i < 10; i++) {
		printf("%d ", *(arr+i));
	}

}//传过来数组首元素=>指针接收

void test_2(int* arr_2[20]) {


}//数组传参=>数组接收

void test_2(int* *arr) {

}//二级指针接收

int main() {

	int arr[10] = { 0 };
	int* arr2[20] = { 0 };

	test(arr);

	test_2(arr2);

	return 0;
}

//2:二维数组传参

//(1):创建数组接收
void test_1(int arr[3][4]) {
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}//传数组首元素地址=>创建数组接收

void test_1(int arr[][4]) {

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}//传数组首元素地址=创建数组接收

//总结:二维数组传参,函数形参的设计只能省略第一个[]的数字;
//因为对一个二维数组,可以不知道有多少行,但必须知道一行有多少元素;
//这样才能方便运算.


//(2):指针形式接收
void test_1(int(*arr_2)[4]) {//*arr_2里有4个int元素(*arr_2==arr)
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", *((*arr_2 + i) + j));
		}
		printf("\n");//**??<<这里需要更多关注>>*((*p + i) + j)
	}

}//传过来数组地址=>创建数组指针接收


int mian() {

	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };

	test_1(arr);

	return 0;
}

