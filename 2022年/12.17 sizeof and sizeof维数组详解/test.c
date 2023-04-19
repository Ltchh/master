#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


//arr[0] 可以理解为第一行的数组名
//arr[0]作为数组名没有单独放在sizeof内部,也没有取地址,所以arr[0]就是第一行第一个元素的地址
//arr[0]+1,就是第一行第二个元素的地址


//sizeof(数组名),这里的数组名表示整个数组,计算的是整个数组的大小
//&数组名.		这里的数组名表示整个数组,取出的是整个数组的地址
//除此之外所有的数组名都表示首元素的地址
int main() {
	int arr[3][4] = { 0 };

	printf("%d\n", sizeof(arr));				//传过去的是整个二维数组元素			4*3*4=48
	printf("%d\n", sizeof(arr[0][0]));			//传过去的的二维数组的第一行第一个元素	4
	printf("%d\n", sizeof(arr[0]));				//传过去的是二维数组第一行的所有元素	4*4=16
	printf("%d\n", sizeof(arr[0]+1));			//传过去的是二维数组第一行第二个元素的地址	4/8
	printf("%d\n", sizeof(*(arr[0] + 1)));		//传过去的是二维数组第一行第二个元素	4
	printf("%d\n", sizeof(arr+1));				//a作为二维数组的数组名并没有取地址,也没有单独放在sizeof内部,
												//所以arr就表示二维数组的首元素地址即第一行地址
												//arr+1二维数组第二行的地址				4/8
	printf("%d\n", sizeof(*(arr + 1)));			//*(arr+1)==arr[1]						4*4=16
												//arr+1第二行的地址所以*(arr+1)表示第二行的所有元素
	printf("%d\n", sizeof(&arr[0]+1));		//传过去的是二维数组的地址					4/8
											//arr[0]是第一行的地址,取出的是第一行的地址+1就是第二行的地址
	printf("%d\n", sizeof(*(&arr[0] + 1)));	//传过去的是二维数组第二行的所有元素		4*4=16
	printf("%d\n", sizeof(*arr));			//传过去的是二维数组第1行的所有元素			4*4=16
											//arr没有取地址,没有单独放在sizeof内部
											//arr就是首元素地址即第一行所有元素
	printf("%d\n", sizeof(arr[3]));			//传过去的是二维数组的一个元素				4*4=16

	return 0;
}