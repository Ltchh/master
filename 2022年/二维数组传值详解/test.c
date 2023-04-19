#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void print(int(*p)[6]) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", *((*p + i) + j));

			//printf("%d ", (*p + i)[j]);

			//printf("%d ", *(p[i] + j));//在二维数组中p[i]是一个地址;
		
			//printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
int main() {

	int arr[5][6];

	memset(arr, 0, sizeof(arr));

	print(arr);

	return 0;
}