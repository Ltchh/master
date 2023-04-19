#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//sizeof(数组名)- 数组名表示整个数组-计算的是整个数组的大小
//&数组名 - 数组名表示的是整个数组 -取出的是整个数组的地址
//除此之外,所有的数组名都是首元素的地址

//32位系统int地址大小为4个字节 64位int地址大小为8个字节
//元素大小是4个字节

int main() {

	int arr[3] = { 0,1,2 };

	printf("sizeof(arr)=%d\n", sizeof(arr));		//传过去的是数组地址	4*3=12						计算的是数组arr元素		arr指向的是整个数组
	printf("sizeof(arr+0)=%d\n", sizeof(arr + 0));		//传过去的是数组首元素地址							计算的是地址arr+0		arr+0指向的是首元素地址
	printf("sizeof(*arr)=%d\n", sizeof(*arr));		//传过去的是数组首元素								计算的是数组元素		*arr解引用数组的第一个元素
	printf("sizeof(arr+1)=%d\n", sizeof(arr + 1));		//传过去的是数组下一个数组的首元素地址(首元素地址)	计算的是数组地址		arr+1指向的是第二个元素
	printf("sizeof(arr[1]=)%d\n", sizeof(arr[1]));	//传过去的是数组第二个元素							计算的是数组arr[1]元素	arr[1]指向的是第二个元素

	printf("sizeof(&arr)=%d\n", sizeof(&arr));		//计算的是数组地址4/8			计算的是数组&arr地址
	printf("sizeof(*&arr)%d\n", sizeof(*&arr));		//计算的是数组大小	4*3=12		计算的是数组*&arr元素
	printf("sizeof(&arr+1)=%d\n", sizeof(&arr + 1));	//计算的下一个数组元的地址4/8	计算的是数组&arr+1地址
	printf("sizeof(&arr[1])=%d\n", sizeof(&arr[1]));	//计算的是地址4/8				计算的是数组&arr[1]地址
	printf("sizeof(arr[1]+1)=%d\n", sizeof(arr[1] + 1));	//arr[2]+1的地址4/8				计算的是数组arr[1]+1地址

	char ch[] = { 'a','b','c','d','e','f' };
	printf("sizeof(ch)=%d\n", sizeof(ch));		//传过去的是首元素地址			6
	printf("sizeof(ch+0)=%d\n", sizeof(ch + 0));		//传过去的是首元素地址			4/8
	printf("sizeof(*ch)=%d\n", sizeof(*ch));		//传过去的是首元素				1
	printf("sizeof(ch[1])=%d\n", sizeof(ch[1]));		//传过去的是第二个元素			1
	printf("sizeof(&ch=%d\n", sizeof(&ch));		//传过去的是数组地址			4/8
	printf("sizeof(&ch+1)=%d\n", sizeof(&ch + 1));		//传过去的是下一个数组的地址	4/8
	printf("sizeof(&ch[0]+1)=%d\n", sizeof(&ch[0] + 1));	//传过去的是第二个元素的地址	4/8


	//strlen 计数的关键的是\0	
	printf("strlen(ch)=%d\n", strlen(ch));		//传过去数组首元素地址		随机值
	printf("strlen(ch+0)=%d\n", strlen(ch + 0));		//传过去数组首元素地址		随机值
	printf("strlen(*ch)=%d\n", strlen(*ch));		//传过去是数组首元素		err		传过去*ch-(a)是一个常量 a做为一个地址0x00097	不是一个合法的地址
	printf("strlen(ch[1])=%d\n", strlen(ch[1]));		//传过去是数组第二个元素	err		传过去*ch[1]-(b)是一个常量 b做为一个地址0x00097	不是一个合法的地址
	printf("strlen(&ch)=%d\n", strlen(&ch));		//传过去是数组地址			随机值	传过去的是数组指针类型
	printf("strlen(&ch+1)=%d\n", strlen(&ch + 1));		//传过去是下一个数组地址	随机值
	printf("strlen(&ch[0]+1)=%d\n", strlen(&ch[0] + 1));	//传过去是数组元素地址		随机值


	//数组初始化{ 'a','b','c','d','e','f' }和"abcdef"  第一个给什么就是什么;第二个末尾自动添加"\0"
	char ch1[] = "abcdef";
	printf("(sizeof(ch1))=%d", sizeof(ch1));			//传过去数组地址				7	
	printf("(sizeof(ch1))=%d", sizeof(ch1 + 0));			//传过去数组第一个元素的地址	4/8
	printf("(sizeof(ch1))=%d", sizeof(*ch1));			//传过去的是第一个元素			1
	printf("(sizeof(ch1))=%d", sizeof(ch1[1]));		//传过去的是第二个元素			1
	printf("(sizeof(ch1))=%d", sizeof(&ch1));			//传过去的是数组的地址			4/8
	printf("(sizeof(ch1))=%d", sizeof(&ch1 + 1));		//传过去的是下一个数组的地址	4/8
	printf("(sizeof(ch1))=%d", sizeof(&ch1[0] + 1));		//传过去的是第二个元素的地址	4/8

	printf("strlen(ch1)=%d\n", strlen(ch1));				//传过去数组首元素地址		6
	printf("strlen(ch1+0)=%d\n", strlen(ch1 + 0));			//传过去数组首元素地址		6
	printf("strlen(*ch1)=%d\n", strlen(*ch1));				//传过去是数组首元素		err		传过去*ch-(a)是一个常量 a做为一个地址0x00097	不是一个合法的地址
	printf("strlen(ch1[1])=%d\n", strlen(ch1[1]));			//传过去是数组第二个元素	err		传过去*ch[1]-(b)是一个常量 b做为一个地址0x00097	不是一个合法的地址
	printf("strlen(&ch1)=%d\n", strlen(&ch1));				//传过去是数组地址			6		传过去还是首元素地址
	printf("strlen(&ch1+1)=%d\n", strlen(&ch1 + 1));			//传过去是下一个数组地址	随机值
	printf("strlen(&ch1[0]+1)=%d\n", strlen(&ch1[0] + 1));		//传过去是数组元素地址		5

	char* p = "abcdef";
	printf("%d\n", sizeof(p));			//传过去的是数组首元素元素的地址					4/8
	printf("%d\n", sizeof(p + 1));		//传过去的是数组第二个元素的地址			4/8
	printf("%d\n", sizeof(*p));			//传过去的的数组元素						1
	printf("%d\n", sizeof(p[0]));		//传过去的是数组元素						1
	printf("%d\n", sizeof(&p));			//传过去的是数组首元素地址					4/8
	printf("%d\n", sizeof(&p + 1));		//传过去的是下一个数组元素的第二个元素地址	4/8
	printf("%d\n", sizeof(&p[0] + 1));	//传过去的是数组第二个元素的地址			4/8

	printf("%d\n", strlen(p));			//传过去的是数组首元素地址									6			
	printf("%d\n", strlen(p + 1));		//传过去的是数组第二个元素的地址							5
	printf("%d\n", strlen(*p));			//传过去的是数组的第一个元素								err
	printf("%d\n", strlen(p[0]));		//传过去的是数组的第一个元素								err
	printf("%d\n", strlen(&p));			//传过去的是p的地址											随机值
	printf("%d\n", strlen(&p + 1));		//传过去的是跳过p后面的地址									随机值
	printf("%d\n", strlen(&p[0] + 1));	//传过去数组的第二个元素地址								5

	return 0;
}