#define _CRT_SECURE_NO_WARNINGS 1
#define SIZE ((int)(sizeof(arr)/sizeof(arr[0])))

#include<stdio.h>
#include<math.h>
#include<string.h>
//-----8/31��
//int main() {
//	char num1[20] = { 0 };
 //	char num2[20] = "I want you";
//	strcpy(num1, num2);//num2���ַ���������num1
//	printf("%s", num1);
//	if (strcmp(num1 , num2)==0)//�ַ���û�а취ֱ�ӱȽ���Ҫʹ��strcmp�������Ƚ�;����int "0"ֵ
//	{
//		printf("\n beautiful;");
//	}
//	return 0;
//}

//(0)----100-200 ֮�������
//int prime_number(int x) {
//
//	for (int j = 2; j < x; j++) {
//		if (x % j == 0)
//			return 0;
//	}
//	return 1;
//}
//int main() {
//	int num = 0;
//	for (num = 100; num <= 200; num++) {
//
//		if(prime_number(num)==1)
//			printf("%d ", num);
//	}
//	return 0;
//
//
//}


//----�Զ��庯��
//(1)--�Ƚϴ�С/-��ֵ����
//int get_max(int x, int y) {//
//	int z = 0;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//
//	return z;
//}
//int main()
//{
//	int a = 4;
//	int b = 9;
//
//	int max=get_max (a, b);//get max���Զ��庯������int���͸�ֵ��max;
//	printf("max=%d",max);
//
//	return 0;
//}

//(2)--������ֵ/-��ַ����
//void swap(int* pa, int* pb) {//
//	int z = 0;
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ:a=%d;b=%d\n", a, b);
//
//	swap(&a, &b);
//
//	printf("������:a=%d;b=%d\n",a,b);
//
//
//	return 0;
//}


//----9/1��

//int is_prime(int x) {
//	int y = 0;
//	for (y = 2; y < x/2; y++) {
//		if (x % y == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main() {
//	//100-200֮�������
//	int num = 0;
//	int count = 0;
//	for (num = 100; num <= 200; num++) {
//
//		if (is_prime(num) == 1){
//			printf("%d ", num);
//		count++;
//		}
//	}
//	printf("\ncount=%d", count);
//
//	return 0;
//}

//�������ò�����
//int is_leap_year(int year1) {
//
//	if (year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0)
//		return 1;
//	return 0;
//}
//int main()
//{
//
//
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++) {
//
//		if (is_leap_year(year) == 1){
//			printf("%d ", year);
//			count++;
//
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}
//----9/2��
// ���ַ����±�
//int binary_search(int arr1[], int num1, int zs1) {
//	int left = 0;//���±�
//	int right = zs1 - 1;//���±�;���鳤�ȼ�ȥ1�������±��ָ��
//
//	while (left <= right) {
//		int mid = (left + right) / 2;//���ֲ��ҿ�ʼ
//
//		if (arr1[mid] > num1) {
//			right = mid - 1;
//		}
//		else if (arr1[mid] < num1) {
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return  -1;
//
//}
//int main() {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = 0;
//	printf("��������Ҫ��ѯ��Ԫ��:");
//	scanf("%d", &num);
//	int zs = SIZE;
//
//	int key = binary_search(arr, num, zs);
//
//	if(key==-1){
//		printf("���Ԫ�ز�������������;");
//
//	}
//	else {
//		printf("���Ԫ�ص��±���%d\n", key);
//	}
//	return 0;
//}

//---
//void add(int* x) {
//
//	(*x)++;
//}
//int main() {
//	int num = 0;
//
//	add(&num);
//	printf("%d", num);
//	return 0;
//}


 
//----9/3�ź�����Ƕ�׵��ú���ʽ����

//(1)Ƕ�׵���---����Ƕ�׶���ֻ��Ƕ��ʹ��

//��ֵ����
//void printf_table(int num) {
//	int x = 0;//��
//		for (x = 1; x <= num; x++) {
//			int y = 0;//��
//			for (y = 1; y <= x; y++) {
//				printf("%d/%d=%d  ", x, y, x / y);
//			}
//			printf("\n");
//		}
//}
//int main() {
//	int a;
//	scanf("%d", &a);
//
//	printf_table(a);
//
//	return 0;
//}

//��ַ����
//void swap(int* pa, int* pb) {
//	int z = 0;
//
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//
//}
//int main() {
//	int a = 4;
//	int b = 10;
//
//	int x = 9;
//	int y = 12;
//
//	printf("����ǰ:a=%x,b=%x\n", &a, &b);
//	swap(&a, &b);
//	printf("������:a=%d,b=%d\n", a, b);
//
//	printf("����ǰ:x=%d,y=%d\n", x, y);
//	swap(&x, &y);
//	printf("������:x=%d,y=%d\n", x, y);
//	return 0;
//}


//(2)��ʽ����
//int main() {
//	char arr[20] = { 0 };
//	char arr1[] = "Hellow word;";
//
//	printf("%s\n", strcpy(arr, arr1));//����Ǽ򵥵���ʱ����
//
//	printf("%d", printf("%d",  printf("%d", 43)));//4321
//	return 0;
//}
//----9/4�ź����Ķ���(P61)
//
//int main() {
//	int a = 3;
//	int b = 4;
//	
//	int add(int, int);    //--��������(��֪����)
//	int c = add(a, b);
//
//	printf("c=%d\n", c);
//
//	return 0;
//}
//
///*    һ�㺯��������ں�������,
//  �����Ҫ��������ȡҩ��������;
//  �������������·���ʹ��֮ǰ*/
//int add(int x, int y) {    //--�����Ķ���
//	return x + y;
//}

//void swcap(int* p, int* b) {
//	int arr5 = 0;
//	arr5 = *p;
//
//	*p = *b;
//	*b = arr5;
//}
//int main() {
//	int arr1 = 3;
//	int arr2 = 4;
//
//	printf("����ǰarr1:%d;arr2:%d\n", arr1, arr2);
//	
//	swcap(&arr1, &arr2);
//	printf("������arr1:%d;arr2:%d\n", arr1, arr2);
//
//	return 0;
//}
//----9/5��-9/6�ŵݹ�


//int print(int num_1) {
//	
//	if (num_1 > 9) {
//		
//		print(num_1 / 10);
//		int sum(num_1);
//		
//	}
//	printf("%d  ", num_1 % 10);
//	
//
//
//}
//int sum(int a) {
//
//	printf("%d", a);
//	return print;
//}
//
//int main() {
//
//	unsigned int num;
//	char arr[20] = { 0 };
//	scanf("%u", &num);
//
//	int print(num);
//
//	
//
//	return 0;
//}
//int fun_1(int num) {
//	
//	if (num == 8)
//		return num;
//	else
//		return 2 * fun_1( num+1);
//
//}
//int main() {
//	int num = 0;
//	scanf("%d", &num);
//
//	int fun_1(num);
//
//	printf("%d", fun_1(num));
//
//	return 0;
//}
//int digit_sum(int num_1) {
//	if (num_1 > 9)
//		return digit_sum(num_1 / 10)+num_1%10;
//	else{
//		
//	return num_1;
//	}
//
//
//}
//int main() {
//	int num = 0;
//
//	scanf("%d", &num);
//
//	int sum = digit_sum(num);
//
//	printf("%d", sum);
//
//	return 0;
//
//}

//9-14
////ð������
//void bubble_sort(int arr[], int sz) {
//
//	int i = 0;
//	for (i = 0; i < sz - 1; i++) {
//		for (int j = 0; j < sz - 1 - i; j++) {
//			if (arr[j] > arr[j+1]) {
//				int tmp = arr[j+1];
//				arr[j+1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//int main() {
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr,sz);
//
//	return 0;
//}


// ----9-16����
// ����������Ԫ�ص�ַ
//int main() {
//	char arr[10] = { 1,2,3,4,5,6, };
//	printf("%p\n", &arr[0]);//������Ԫ�ص�ַ
//	printf("%p\n", arr);    //������Ԫ�ص�ַ
//	printf("%p\n", &arr);   //���������ַ--&arr+1��������ַ�������һλ���(������*Ԫ�ص�����)
//
//
//	return 0;
//}
void bubble_sort(int arr[], int num) {
	int i = 0;								      //ð����Ҫ����
	int flag = 1;
	for (i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i;j++) {	  //Ԫ�ؽ�������
			if (arr[j] < arr[j+1]) {			  //�ͺ�һ��Ԫ�رȽ�
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
		
}


int main() {

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//������Ҫ���������


	int sz = sizeof(arr) / sizeof(arr[0]);//�������ĸ���

	bubble_sort(arr, sz);				  //ð��������

	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}


//�±���ʽ����
int main()
{
	int n = 0;
	int arr[5001] = { 0 };
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		//���������Ĵ洢
		int tmp = 0;		//���������������±�ı�Ԫ�ص�ֵ
		scanf("%d", &tmp);
		if (arr[tmp] == 0)	
			arr[tmp] = 1;
	}
	for (i = 0; i < 5001; i++)
	{
		if (arr[i] == 1)	//�øı��Ԫ�ش�ӡ���±�
			printf("%d ", i);
	}
	return 0;
}