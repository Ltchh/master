#define _CRT_SECURE_NO_WARNINGS 1
#define MZ ((int)(sizeof(arr)/sizeof(arr[0])))//�����ַ����ĸ���
#include<stdio.h>
int main()
{
	int k = 0;//����������±�
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//k�����ַ����е�λ��
	scanf("%d", &k);//����ֵȥK
	int left = 0;//left-1���±�
	int right = MZ - 1;//right-10���±�

	while (left <= right)//whileѭ��
	{
		int mid = (right + left) / 2;//�����ַ������м�ֵ(���ַ��ų����ַ�)
		if (arr[mid] < k)//���arr[mid]С������ֵ���k����mid����
		{
			left = mid + 1;//�±������һλ
		}
		else if (arr[mid] > k)//���arr[mid]��������ֵ���k����midǰ��
		{
			right = mid - 1;//�±���ǰ��һλ������±��λ��
		}
		else
		{
			printf("%d��������±���%d\n", k, mid);
			break;
		}
	}
	if (left > right)
		printf("%d�������������������鷶Χ��", k);
	return 0;
}
