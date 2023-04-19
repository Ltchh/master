#define _CRT_SECURE_NO_WARNINGS 1
#define MZ ((int)(sizeof(arr)/sizeof(arr[0])))//整个字符串的个数
#include<stdio.h>
int main()
{
	int k = 0;//求这个数的下标
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//k在这字符串中的位置
	scanf("%d", &k);//输入值去K
	int left = 0;//left-1的下标
	int right = MZ - 1;//right-10的下标

	while (left <= right)//while循环
	{
		int mid = (right + left) / 2;//整个字符串的中间值(二分法排除找字符)
		if (arr[mid] < k)//如果arr[mid]小于输入值这个k就在mid后面
		{
			left = mid + 1;//下标向后移一位
		}
		else if (arr[mid] > k)//如果arr[mid]大于输入值这个k就在mid前面
		{
			right = mid - 1;//下标向前移一位求出右下标的位置
		}
		else
		{
			printf("%d这个数的下标是%d\n", k, mid);
			break;
		}
	}
	if (left > right)
		printf("%d这个整数不存在这个数组范围内", k);
	return 0;
}
