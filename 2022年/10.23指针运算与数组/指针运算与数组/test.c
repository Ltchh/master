#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//数组名是数组首元素的地址


//int main() {  
//	int arr[5] = { 0 };
//
//	int* p = arr;
//
//	printf("%p<==>%p\n", arr, p);
//	printf("%p<==>%p\n", &arr[0], p);
//
//	return 0;
//}


//int main() {
//	int arr[3]={0};
//	int* p;
//	int i = 0;
//	for (p = arr; p < &arr[3];) {
//		*++p = i++;
//		printf("%p value:%d \n", p,*p);
//		
//	}
//	return 0;
//}
//
//int main() {
//	int arr[6] = { 0 };
//	int* p = arr;
//	int i = 5;
//	for (p = &arr[6]; p > &arr[0];){
//		
//		*--p= 0;
//		printf("%p<==>%p\n", p,&arr[i--]);
//	}
//	for (int i = 0; i < 6; i++) {
//		printf("%d\n\n", *(p+i));//p(2)-->*(p+2)
//	}

	//arr[2]-->2[arr]-->*(arr+2)-->*(2+arr) -------<解引用>
	
	//arr[2] <= => 2[arr] <= => *(arr + 2) <= => *(2 + arr) <= => *(p + 2) <= => *(2 + p)--解引用
		
	
		
//	return 0;
//}
//int main() {
//	int arr[5] = { 0 };
//	int* p = &arr;
//
//	printf("  %p \n", p);
//	printf("  %d \n", *p);
//	
//	printf(" %p  \n", p[2]);
//	printf(" %p  \n", &arr[2]);
//
//
//	return 0;
//}

//int main() {
//	int arr[10];
//	int* p = arr;
//
//	for (int i = 0; i < 10; ) {
//		printf("arr[%d]: %p<==>p+%d:%p \n", i, &arr[i], i, p + i );
//		*p++ = i++;
//	}
//	printf("********************************\n");
//	
//	for (int i = 0; i < 10; i++) {
//		p = arr;
//		printf("arr[%d] value:%d %d %d %d %d %d\n", i, arr[i], i[arr], *(arr+i),*(i+arr),*(p+i),*(i+p) );
//
//		//arr[i] <= => i[arr] <= => *(arr + i) <= => *(i + arr) <= => *(p + i) <= => *(i + p)--解引用
//	}
//
//	return 0;
//}

//int main() {
//	int arr[5] = { 0 };
//	for (int i = 0; i < 5; i++) {
//		printf("arr[%d]<==>%p<==>%p\n",i,arr+i ,&arr[i]);
//	}
//	return 0;
//}

//int main() {
//	int arr[5] = { 0 };
//
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr[0]);
//	printf("--------------------------\n");
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr + 1); ///&arr + 1是跳过这个数组下一个数组的地址
//	printf("%p\n", &arr[0] + 1);
//	return 0;
//
//}

//int main() {
//	int arr[5] = { 0 };
//	int* p = arr;
//	//地址
//	printf("arr[1]:%p\n", &arr[1]);//地址
//	printf("arr[1]:%p\n", p+1);	//地址
//	printf("arr[1]:%p\n", arr+1);	//地址

//	
//	//解引用
//	printf("arr[1]values:%d\n", *(p + 2) );
//	printf("arr[1]values:%d\n", *(2 + p));
//	printf("arr[1]values:%d\n", arr[1]);
//	printf("arr[1]values:%d\n", 1[arr]);
//	printf("arr[1]values:%d\n", *(arr + 1));
//	printf("arr[1]values:%d\n", *(1 + arr));
//	
//	
//	return 0;
//}


//一级指针and二级指针

int main() {
	int a = 0;
	int* p = &a;	//一级指针

	int** pa = &p;	//二级指针
	int* pa = p;
	

	return 0;
}
