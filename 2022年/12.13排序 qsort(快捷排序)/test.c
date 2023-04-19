#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����
//Structure  �ṹ��

//������������(����)

void print(int* pe, int* sz) {
	for (int i = 0; i < *sz; i++) {
		printf("%d ", pe[i]);
	}
	printf("\n");
}

int compare(const void* e1, const void* e2) {

	return *(int*)e1 - *(int*)e2;//����*(int*)e2 - *(int*)e1
}

int main() {
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]), compare);

	print(arr, &sz);
	return 0;
}

//�ṹ����������(����)

//�ṹ��->��������(1)
struct student {	//�ṹ��
	char arr[10];	//����
	int age;		//����

};

int sort_age(const void* e1, const void* e2) {	//qsort����ָ������		(!1)

	return ((struct student *)e1)->age - ((struct student*)e2)->age;//����ֵ  //����((struct student *)e2)->age - ((struct student*)e1)->age
}
void test() {
	
	struct student stu[3] = { {"wangfang",25} ,{"zhangqiang",26}, {"liying",31}};//�ṹ���ʼ��
	
	int sz = sizeof(stu) / sizeof(stu);	//��������Ԫ�ظ���
	
	//��������
	qsort(stu, sz, sizeof(stu[0]), sort_age);//���� ��Ԫ�ص�ַ,Ԫ�ظ���,Ԫ�����ʹ�С,�ȽϺ���ָ��=>(!1)
}

int main() {

	test();
	
	return 0;
}

//�ṹ��->��������(2)
struct student {
	char name[20];
	int age;
};

int sort_by_name(const void* e1, const void* e2) {

	return   strcmp(((struct student*)e1)->name, ((struct student*)e2)->name); //����((struct student *)e2)->age - ((struct student*)e1)->age
}

test() {
	
	struct student sort[3] = { { "wangfangfang",31 }, { "lidaying",26 }, { "xiaolizhi",29 } };
	
	int sz = sizeof(sort) / sizeof(sort[0]);
		
	qsort(sort, sz, sizeof(sort[0]), sort_by_name);
}

int main() {
	test();

	return 0;
}