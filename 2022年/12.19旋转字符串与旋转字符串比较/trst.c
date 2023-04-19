#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void rotate_string_left(char* arr, size_t num_1, int* num,int *tmp_1,char*arr_1,int* numble) {//左旋转字符串函数
	for (int i = 0; i < *num; i++) {
		char tmp = *arr;
		for (int j = 0; j < num_1 - 1; j++) {
			arr[j] = arr[j + 1];
		}
		arr[num_1 - 1] = tmp;
		(*numble)++;
		*tmp_1 = strcmp(arr, arr_1);
	}
}

void rotate_string_right(char* arr, size_t num_1, int* num) {//右旋转字符串函数
	for (int i = 0; i < *num; i++) {
		char tmp = arr[num_1-1];
		for (int j = 0; j < num_1 - 1; j++) {
			arr[num_1 - 1 - j] = arr[num_1 - 2 - j];
		}
		*arr = tmp;
	}
}
void reverse(char* left, char *right) {						//反转函数
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
void rotate_string(char* arr, size_t num_1, int* num){//三步反转旋转字符串
	
	reverse(arr,arr+*num-1);				//需要旋转次数的前面几个元素反转
	reverse(arr + *num, arr + num_1 - 1);	//剩余元素反转
	reverse(arr, arr + num_1 - 1);			//整个数组反转
}
int is_rotate_string(arr, arr_1) {
	return strcmp(arr, arr_1);

}
int main() {

	int num = 0;			//旋转次数
	char arr[10] = "ABCDEF";//旋转的字符串	
	char arr_1[10] = "CDEFAB";//比较的字符串
	int tmp = 0;//arr_1是否是arr的旋转
	int numble = 0;
	scanf("%d", &num);

	int num_1 = strlen(arr);//字符传长度
	rotate_string_left(arr,num_1,&num,&tmp,arr_1,&numble);	//左旋转字符串函数

	//rotate_string_right(arr,num_1,&num);	//右旋转字符串函数

	//rotate_string(arr, num_1, &num);		//三步反转法=>旋转字符串

	if (tmp == 1)
		printf("arr_1是arr的旋转\n旋转%d次\n",numble);
	else
		printf("arr_1不是arr的旋转\n");
	printf("%s\n", arr);
	return 0;
}