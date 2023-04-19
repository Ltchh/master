#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//******新单词**********
//reverse	反向
//left		左
//right		右
//start		开始
//end		结束

void reverse(char* left, char* right) {

	assert(left != NULL);

	while (left < right) {
		char tmp = 0;
		tmp=*left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}

int main() {
	char arr[100] = {0};
	
	gets(arr);

	int len = strlen(arr);

	reverse(arr, arr + len - 1);

	char* start = arr;

	//单词反转
	while (*start) {
		char* end = start;
		while (*end != ' '&& *end !='\0') {
			end++;
		}

		reverse(start, end - 1);

		if (*end == ' ') {
			start = end + 1;
		}
		else {
			start = end;
		}
	}
	printf("%s\n", arr);


	return 0;
}

//int main() {
//    int n;
//    int arr[10000] = { 0 };
//    int max, min;
//
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", arr + i);
//    }
//
//    max = arr[0];
//    min = arr[0];
//    for (int i = 0; i < n; i++) {
//        if (max < arr[i])
//            max = arr[i];
//        if (min > arr[i])
//            min = arr[i];
//    }
//
//    int diff = max - min;
//    printf("%d", diff);
//
//    return 0;
//}
//
//int main() {
//
//	int i;
//	int t = 1;
//	for (i = 2; i <= 50; i++) {
//		t = i * t;
//		printf("%d\n", t);
//	}
//
//	return 0;
//}
