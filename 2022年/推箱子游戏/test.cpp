#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<easyx.h>

int map[8][8];
void print(int(*p)[8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d \n",map[i][j]);
		}
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = 1;
		}
	}
	print(map);


	return 0;
}