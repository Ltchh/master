#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


//strtok �ָ��ַ�������
//�� strtok(arr,p1)//arr�ַ��� p1�ָ��������ı�Ǽ��ϵ�ַ
//1.��һ������ָ��һ���ַ���,��������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı��
//2.strtok�����ҵ�str�е���һ�����,��������\0��β,����һ��ָ�������ǵ�ָ��(�ú�����ı䱻�������ַ���,
//����ʹ��strtok�����и��ַ�������ʹ����ʱ�����������޸�(strcpy����))
//3.strtok�����ĵ�һ��������ΪNULL,�������ҵ�str�е�һ�����,strtok���������������ַ�����λ��
//4.����ַ����в����ڸ����Ƿ���һ��NULLָ��
int main() {
	char arr[50] = "lifetime_chhui@163.com";
	char* p1 = "_@.";
	char arr2[50] = {0};

	strcpy(arr2, arr);
	//char* ret = NULL;

	//ret=strtok(arr2, p1);
	//printf("%s\n", ret);

	//ret=strtok(NULL, p1);
	//printf("%s\n", ret);

	//ret=strtok(NULL, p1);
	//printf("%s\n", ret);

	//����򻯰�
	for (char* tmp = strtok(arr2, p1); tmp != NULL; tmp = strtok(NULL, p1)) {
		printf("%s\n", tmp);
	}

	return 0;
}