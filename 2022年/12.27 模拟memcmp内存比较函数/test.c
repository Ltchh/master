#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>

//memcmp �ڴ�Ƚ�
//int memcmp(const void* ptrl,const void*ptr2,size_t num)

int main() {

	float arr1[10] = { 1.0,2.0,3.0 ,7.0,8.0};
	float arr2[5] = { 1.0,2.0,4.0,5.0,6.0 };

	size_t num = sizeof(float);
	int ret = memcmp(arr1, arr2, num * 4);//�Ƚ�arr1,arr2ǰ4��Ԫ�صĴ�С����ֵ��strcmpһ��
	printf("%d", ret);
 	return 0;
}
