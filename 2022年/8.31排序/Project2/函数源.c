#define _CRT_SECURE_NO_WARNINGS 1
#define SIZE ((int)(sizeof(arr)/sizeof(arr[0])))

#include<stdio.h>
#include<math.h>
#include<string.h>
//-----8/31号
//int main() {
//	char num1[20] = { 0 };
 //	char num2[20] = "I want you";
//	strcpy(num1, num2);//num2的字符串拷贝到num1
//	printf("%s", num1);
//	if (strcmp(num1 , num2)==0)//字符串没有办法直接比较需要使用strcmp函数来比较;返回int "0"值
//	{
//		printf("\n beautiful;");
//	}
//	return 0;
//}

//(0)----100-200 之间的素数
//int prime_number(int x) {
//
//	for (int j = 2; j < x; j++) {
//		if (x % j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main() {
//	int num = 0;
//	for (num = 100; num <= 200; num++) {
//
//		if(prime_number(num)==1)
//			printf("%d ", num);
//	}
//	return 0;
//
//
//}


//----自定义函数
//(1)--比较大小/-传值调用
//int get_max(int x, int y) {//
//	int z = 0;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//
//	return z;
//}
//int main()
//{
//	int a = 4;
//	int b = 9;
//
//	int max=get_max (a, b);//get max是自定义函数返回int类型赋值给max;
//	printf("max=%d",max);
//
//	return 0;
//}

//(2)--交换数值/-传址调用
//void swap(int* pa, int* pb) {//
//	int z = 0;
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前:a=%d;b=%d\n", a, b);
//
//	swap(&a, &b);
//
//	printf("交换后:a=%d;b=%d\n",a,b);
//
//
//	return 0;
//}


//----9/1号

//int is_prime(int x) {
//	int y = 0;
//	for (y = 2; y < x/2; y++) {
//		if (x % y == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main() {
//	//100-200之间的素数
//	int num = 0;
//	int count = 0;
//	for (num = 100; num <= 200; num++) {
//
//		if (is_prime(num) == 1){
//			printf("%d ", num);
//		count++;
//		}
//	}
//	printf("\ncount=%d", count);
//
//	return 0;
//}

//函数调用查闰年
//int is_leap_year(int year1) {
//
//	if (year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//
//
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++) {
//
//		if (is_leap_year(year) == 1){
//			printf("%d ", year);
//			count++;
//
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}
//----9/2号
// 二分法找下标
//int binary_search(int arr1[], int num1, int zs1) {
//	int left = 0;//左下标
//	int right = zs1 - 1;//右下标;数组长度减去1就是右下标的指数
//
//	while (left <= right) {
//		int mid = (left + right) / 2;//二分查找开始
//
//		if (arr1[mid] > num1) {
//			right = mid - 1;
//		}
//		else if (arr1[mid] < num1) {
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return  -1;
//
//}
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = 0;
//	printf("请输入你要查询的元素:");
//	scanf("%d", &num);
//	int zs = SIZE;
//
//	int key = binary_search(arr, num, zs);
//
//	if(key==-1){
//		printf("这个元素不存在这数组中;");
//
//	}
//	else {
//		printf("这个元素的下标是%d\n", key);
//	}
//	return 0;
//}

//---
//void add(int* x) {
//
//	(*x)++;
//}
//int main() {
//	int num = 0;
//
//	add(&num);
//	printf("%d", num);
//	return 0;
//}


 
//----9/3号函数的嵌套调用和链式访问

//(1)嵌套调用---不能嵌套定义只能嵌套使用

//传值调用
//void printf_table(int num) {
//	int x = 0;//行
//		for (x = 1; x <= num; x++) {
//			int y = 0;//列
//			for (y = 1; y <= x; y++) {
//				printf("%d/%d=%d  ", x, y, x / y);
//			}
//			printf("\n");
//		}
//}
//int main() {
//	int a;
//	scanf("%d", &a);
//
//	printf_table(a);
//
//	return 0;
//}

//传址调用
//void swap(int* pa, int* pb) {
//	int z = 0;
//
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//
//}
//int main() {
//	int a = 4;
//	int b = 10;
//
//	int x = 9;
//	int y = 12;
//
//	printf("交换前:a=%x,b=%x\n", &a, &b);
//	swap(&a, &b);
//	printf("交换后:a=%d,b=%d\n", a, b);
//
//	printf("交换前:x=%d,y=%d\n", x, y);
//	swap(&x, &y);
//	printf("交换后:x=%d,y=%d\n", x, y);
//	return 0;
//}


//(2)链式访问
//int main() {
//	char arr[20] = { 0 };
//	char arr1[] = "Hellow word;";
//
//	printf("%s\n", strcpy(arr, arr1));//这就是简单的链时访问
//
//	printf("%d", printf("%d",  printf("%d", 43)));//4321
//	return 0;
//}
//----9/4号函数的定义(P61)
//
//int main() {
//	int a = 3;
//	int b = 4;
//	
//	int add(int, int);    //--函数声明(告知函数)
//	int c = add(a, b);
//
//	printf("c=%d\n", c);
//
//	return 0;
//}
//
///*    一般函数定义放在函数上面,
//  如果需要放在下面取药函数声明;
//  代码是自上向下放在使用之前*/
//int add(int x, int y) {    //--函数的定义
//	return x + y;
//}

//void swcap(int* p, int* b) {
//	int arr5 = 0;
//	arr5 = *p;
//
//	*p = *b;
//	*b = arr5;
//}
//int main() {
//	int arr1 = 3;
//	int arr2 = 4;
//
//	printf("交换前arr1:%d;arr2:%d\n", arr1, arr2);
//	
//	swcap(&arr1, &arr2);
//	printf("交换后arr1:%d;arr2:%d\n", arr1, arr2);
//
//	return 0;
//}
//----9/5号-9/6号递归


//int print(int num_1) {
//	
//	if (num_1 > 9) {
//		
//		print(num_1 / 10);
//		int sum(num_1);
//		
//	}
//	printf("%d  ", num_1 % 10);
//	
//
//
//}
//int sum(int a) {
//
//	printf("%d", a);
//	return print;
//}
//
//int main() {
//
//	unsigned int num;
//	char arr[20] = { 0 };
//	scanf("%u", &num);
//
//	int print(num);
//
//	
//
//	return 0;
//}
//int fun_1(int num) {
//	
//	if (num == 8)
//		return num;
//	else
//		return 2 * fun_1( num+1);
//
//}
//int main() {
//	int num = 0;
//	scanf("%d", &num);
//
//	int fun_1(num);
//
//	printf("%d", fun_1(num));
//
//	return 0;
//}
//int digit_sum(int num_1) {
//	if (num_1 > 9)
//		return digit_sum(num_1 / 10)+num_1%10;
//	else{
//		
//	return num_1;
//	}
//
//
//}
//int main() {
//	int num = 0;
//
//	scanf("%d", &num);
//
//	int sum = digit_sum(num);
//
//	printf("%d", sum);
//
//	return 0;
//
//}

//9-14
////冒泡排序
//void bubble_sort(int arr[], int sz) {
//
//	int i = 0;
//	for (i = 0; i < sz - 1; i++) {
//		for (int j = 0; j < sz - 1 - i; j++) {
//			if (arr[j] > arr[j+1]) {
//				int tmp = arr[j+1];
//				arr[j+1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//int main() {
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr,sz);
//
//	return 0;
//}


// ----9-16数组
// 数组名是首元素地址
//int main() {
//	char arr[10] = { 1,2,3,4,5,6, };
//	printf("%p\n", &arr[0]);//数组首元素地址
//	printf("%p\n", arr);    //数组首元素地址
//	printf("%p\n", &arr);   //整个数组地址--&arr+1是整个地址的向后移一位跨度(是类型*元素的数量)
//
//
//	return 0;
//}
void bubble_sort(int arr[], int num) {
	int i = 0;								      //冒泡需要几躺
	int flag = 1;
	for (i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i;j++) {	  //元素交换躺数
			if (arr[j] < arr[j+1]) {			  //和后一个元素比较
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
		
}


int main() {

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//整个需要整理的数组


	int sz = sizeof(arr) / sizeof(arr[0]);//这个数组的个数

	bubble_sort(arr, sz);				  //冒泡排序函数

	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}


//下标形式排序
int main()
{
	int n = 0;
	int arr[5001] = { 0 };
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		//进行整数的存储
		int tmp = 0;		//让输入的整数变成下标改变元素的值
		scanf("%d", &tmp);
		if (arr[tmp] == 0)	
			arr[tmp] = 1;
	}
	for (i = 0; i < 5001; i++)
	{
		if (arr[i] == 1)	//用改变的元素打印其下标
			printf("%d ", i);
	}
	return 0;
}