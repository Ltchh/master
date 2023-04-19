#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//新单词
//move	移动,改变,前进,进步

void print(int arr[], int sz) {

	for (int i = 0; i < sz; i++) {
		printf("%d ", *(arr + i));
	}

}

void move(int(*p)[], int sz) {
	int	*left = *p;
	int *right = *p + sz - 1;

	while (left < right) {

		while (*left % 2 == 1) {
			left++;
		}
			
		while (*right % 2 == 0) {
			right--;
		}
			

		if (left < right) {
			int tmp = *left;
			*left = *right;
			*right = tmp;

		}
	}

}

int main() {

	int arr[9] = { 1,2,3,4,5,6,7,8,9 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	move(arr, sz);

	print(arr, sz);


	return 0;
}