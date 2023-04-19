#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//define->是替换
//typedef->类型重定义


//柔性数组:
//	结构中的最后一个元素是未知大小的数组,叫做柔性数组
//特点:结构中的柔性数组成员前面必须至少一个其他成员
//	   sizeif返回的这种结构大小不包含柔性数组的内存
//	   高喊柔性数组成员的结构用malloc()函数进行内存的动态分配
//并且分配的内存应该大于结构的大小,以适应柔性数组的预期大小


//例:
typedef struct st_def {//=>柔性数组
	char ch;
	int a;
	int arr[];//柔性数组成员 - 未知大小
	//也可以写int arr[0];
}st_def;


int main() {
	st_def* ptr = (st_def*)malloc(sizeof(st_def) + 10 * sizeof(st_def));

	if (ptr == NULL){
		perror("prt");
		return;
	}

	ptr->ch = 'a';
	ptr->a = 10;

	for (int i = 0; i < 10; i++) {
		ptr->arr[i] = i;
	}

	st_def* ps = (st_def*)realloc(ps, sizeof(ptr) + 20 * sizeof(st_def));
	if (ps != NULL)
		ptr = ps;
	free(ps);
	ps = NULL;
	return 0;
}