#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void rotate_string_left(char* arr, size_t num_1, int* num,int *tmp_1,char*arr_1,int* numble) {//����ת�ַ�������
	for (int i = 0; i < *num; i++) {
		char tmp = *arr;
		for (int j = 0; j < num_1 - 1; j++) {
			arr[j] = arr[j + 1];
		}
		arr[num_1 - 1] = tmp;
		(*numble)++;
		*tmp_1 = strcmp(arr, arr_1);
	}
}

void rotate_string_right(char* arr, size_t num_1, int* num) {//����ת�ַ�������
	for (int i = 0; i < *num; i++) {
		char tmp = arr[num_1-1];
		for (int j = 0; j < num_1 - 1; j++) {
			arr[num_1 - 1 - j] = arr[num_1 - 2 - j];
		}
		*arr = tmp;
	}
}
void reverse(char* left, char *right) {						//��ת����
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
void rotate_string(char* arr, size_t num_1, int* num){//������ת��ת�ַ���
	
	reverse(arr,arr+*num-1);				//��Ҫ��ת������ǰ�漸��Ԫ�ط�ת
	reverse(arr + *num, arr + num_1 - 1);	//ʣ��Ԫ�ط�ת
	reverse(arr, arr + num_1 - 1);			//�������鷴ת
}
int is_rotate_string(arr, arr_1) {
	return strcmp(arr, arr_1);

}
int main() {

	int num = 0;			//��ת����
	char arr[10] = "ABCDEF";//��ת���ַ���	
	char arr_1[10] = "CDEFAB";//�Ƚϵ��ַ���
	int tmp = 0;//arr_1�Ƿ���arr����ת
	int numble = 0;
	scanf("%d", &num);

	int num_1 = strlen(arr);//�ַ�������
	rotate_string_left(arr,num_1,&num,&tmp,arr_1,&numble);	//����ת�ַ�������

	//rotate_string_right(arr,num_1,&num);	//����ת�ַ�������

	//rotate_string(arr, num_1, &num);		//������ת��=>��ת�ַ���

	if (tmp == 1)
		printf("arr_1��arr����ת\n��ת%d��\n",numble);
	else
		printf("arr_1����arr����ת\n");
	printf("%s\n", arr);
	return 0;
}