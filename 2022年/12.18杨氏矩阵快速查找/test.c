#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int find_num(int(*arr)[5], int* row, int* column, int num) {
	int x = 0;			//��
	int y = *column-1;	//��

	while (x < *row && y >= 0) {
		if (arr[x][y] < num) {
			x++;
		}
		else if (arr[x][y] > num) {
			y--;
		}
		else{
			*row = x;
			*column = y;
			return 1;
		}

	}
	return 0;

}
int main() {
	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int row = 3;//��
	int column = 5;//��

	int num = 0;		//Ҫ���ҵ���
	scanf("%d", &num);
	int num_1 = find_num(arr, &row, &column, num);//���ҵĺ���

	if (num_1 == 1) {
		printf("�±�Ϊarr[%d][%d]\n",row,column);
	}
	else
		printf("���������Χ��\n");

	return 0;
}