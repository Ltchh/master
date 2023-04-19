#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main() {
//	int a, b;
//
//	scanf("%d %d", &a, &b);
//
//	int max = a > b ? a : b;
//
//	while (1) {
//		
//		if (max % a == 0 && max % b == 0) {
//			printf("%d\n", max);
//			break;
//		}
//		max++;
//	}
//	return 0;
//}

int main() {

	int a, b;
	
	scanf("%d %d", &a, &b);

	for (int i = 1;; i++) {

		if (a * i % b == 0) {
			printf("%d\n", a * i);
			break;
		}
	}
	return 0;
}