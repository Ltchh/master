#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//void reverse(char* left, char* right) {
//	while (left < right) {
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main() {
//	char arr[100] = { 0 };
//	gets(arr);
//	int len = strlen(arr);
//
//	reverse(arr, arr + len - 1);
//
//	char* start = arr;
//	while (*start) {
//		char* end = start;
//		while (*end != ' '&& *end!='\0') {
//			end++;
//		}
//		reverse(start, end - 1);
//		if (*start == ' ')
//			start = end + 1;
//		else
//			start = end;
//	}
//	printf("%s\n", arr);
//	return 0;
//}

//int main() {
//    int a;
//    char arr[] = "* ";
//    char arr1 = '  ';
//    while (scanf("%d", &a) != EOF) {
//        int i, j;
//
//        for (i = 0; i < a; i++) {   //��
//            for (j = 0; j < a - i; j++) {//��
//                printf("%s", arr);
//               
//                   
//            }
//            printf("\n");
//            if ((a-i) < 1)
//                break;
//            for (j = 0; j <=  i; j++) {
//                printf("%c", arr1);
//                
//            }
//        }
//    }
//    return 0;
//}

//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF) {
//        int i, j;
//        for (i = 0; i <= a; i++) {
//            for (j = 0; j <= a-i; j++) {
//                printf("* ");
//            }
//            printf("\n");
//            if (j == 2)
//                break;
//        }
//        for (i = 0; i <= a; i++) {
//            for (j = 0; j <= i; j++) {
//                printf("* ");
//            }
//            printf("\n");
//        }
//        
//    }
//    return 0;
//}

//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF) { 
//        int i, j;
//        for (i = 0; i <= a; i++) {      //�ϲ�  //��
//            for (j = i; j <a; j++) {            //��
//                printf("  ");
//            }
//            for (j = 0; j <= i; j++) {          //��
//                  
//                       printf("*");
//            }
//            printf("\n");
//        }
//        for (i = 0; i < a; i++) {       //�²�    //��
//            for (j = 0; j <= i; j++) {            //��
//                printf("  ");
//            }
//            for (j = i; j < a; j++) {             //��
//                printf("*");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main() {
//	int a;
//	while (scanf("%d", &a) != EOF) {
//		int i, j;
//		for (i = 0; i < a; i++) {	//��
//			for (j = 0; j < i; j++) {
//				printf(" ");
//			}
//			printf("*\n");
//
//		}
//	}
//	return 0;
//}

//int main() {
//	int a;
//	while (scanf("%d", &a) != EOF) {
//		int i, j;
//		for (i = 0; i < a; i++) {	//��
//			for (j = 0; j < a - i; j++) {
//				printf(" ");
//			}
//			printf("*\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//    int n = 0;
//    //��������
//    while (~scanf(" %d", &n))
//    {
//        int i,j;
//        for (i = 0; i <n; i++) {       //��
//            for (j = 0; j < n; j++) {
//                
//                if (j>0&&j<n-1&&i>0&&i<n-1)
//                    printf("  ");
//                else
//                    printf("* ");
//                    
//            }
//            printf("\n");
//        }   
//    }
//    return 0;
//}
//
//int main() {
//    int n = 0;
//    int arr[50];
//    scanf("%d", &n);
//
//
//    for (int i = 0; i < n; i++) {
//        scanf("%d", arr + i);
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - 1 - i; j++) {
//            if (arr[j] < arr[j + 1]) {
//                int tamp = arr[j + 1];
//                arr[j + 1] = arr[j];
//                arr[j] = tamp;
//            }
//        }
//    }
//
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//int main() {
//    int n;
//    int arr[50];
//
//    int count = 0;
//    int count_1 = 0;
//
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//  
//        for (int j = 0; j < n - 1; j++) {
//            if (arr[j] <= arr[j + 1])
//                count++;
//            if (arr[j] >= arr[j + 1])
//                count_1++;
//        }
//    
//
//    if (count == 4 || count_1 == 4)
//        printf("sorted\n");
//    else
//        printf("unsorted\n");
//    return 0;
//}


//int main()
//{
//    int n = 0;
//    int arr[51] = { 0 };
//    int i = 0;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        //���������Ĵ洢
//        int tmp = 0;
//        scanf("%d", &tmp);
//        if (arr[tmp] == 0)
//            arr[tmp] = 1;
//    }
//    for (i = 0; i < 51; i++)
//    {
//        if (arr[i] == 1)
//            printf("%d ", i);
//    }
//    return 0;
//}

//int main() {//Ͱ��
//    int arr[100] = { 0 };//100��Ͱ��ʼ��Ϊ0
//    int n = 0;
//    int temp = 0;//Ͱ�ı��
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &temp);//���Ͱ���
//        arr[temp]++;//temp��Ӧ����Ͱ����־���������Ϊ���ִ���
//    }
//    int index = 0;
//    scanf("%d", &index);
//    printf("%d", arr[index]);
//    return 0;
//}

//int main() {
//    int n, m;
//    int arr_1[10][10];
//    int arr_2[10][10];
//
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            scanf("%d", arr_1[i][j]);
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            scanf("%d", arr_2[i][j]);
//            if (arr_1[i][j] != arr_2[i][j]) {
//                printf("No\n");
//                return 0;
//            }
//
//        }
//    }
//
//    printf("Yes\n");
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main() {
//    int n;
//
//    scanf("%d", &n);
//
//    int arr[20][20] = { 0 };
//
//    int i = 0, j = 0;
//
//    int count = 0;
//
//    int sum = 1;
//
//    while (count <= 2 * n - 2) {
//        for (i = 0; i < n; i++) {
//            for (j = 0; j < n; j++) {
//
//                if (i + j == count) {
//
//                    if (count % 2 == 0) {
//                        arr[j][i] = sum++;
//                    }
//
//                    else {
//                        arr[i][j] = sum++;
//                    }
//                }
//            }
//        }
//        count++;
//    }
//
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//void reverse(char* left, char* right) {
//	while (left < right) {
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//
//}
//
//int main() {
//	char arr[100] = { 0 };
//
//	gets(arr);
//
//	int len = strlen(arr);
//
//	reverse(arr, arr + len - 1);
//
//	char* start = arr;
//	while (*start) {
//		char *end = start;
//		while (*end != ' ' && *end != '\0') {
//			end++;
//		}
//		reverse(start, end - 1);
//		if (*end == ' ') {
//			start = end + 1;	
//		}
//			
//		else
//			start = end;
//	}
//
//		printf("%s\n", arr);
//	
//	return 0;
//}

//void reverst(char *left, char* right) {
//
//	while (left < right) {
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//
//
//}
//
//int main() {
//	char arr[100]={0};
//
//	gets(arr);
//
//	int len = strlen(arr);
//
//	//������䷴ת;
//	reverst(arr, arr + len - 1);
//
//	//���ʷ�ת;
//	char* left_1 = arr;
//	while (*left_1) {
//		char* lend = left_1;
//		while (*lend != ' ' && *lend != '\0') {
//			lend++;
//		}
//		reverst(left_1, lend-1);
//		if (*lend == ' ') {
//			left_1 = lend + 1;
//		}
//		else {
//			left_1 = lend;
//		}
//	}
//	printf("%s\n", arr);
//	return 0;
//
//}

//void reverst(char* left, char* right) {
//
//	char tmp = 0;
//
//	while (left < right) {
//		
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//
//}
//
//int main() {
//	char arr[100];
//
//	gets(arr);
//
//	int len = strlen(arr);
//
//	//��䷴ת
//	reverst(arr, arr + len - 1);
//
//	//���ʷ�ת
//	char *left_1 = arr;
//	while (*left_1) {
//		char *lend = left_1;
//		while (*lend != ' ' && *lend != '\0') {
//			lend++;
//		}
//		reverst(left_1, lend-1);
//		if (*lend == ' ') {
//			left_1 = lend + 1;
//		}
//		else
//			left_1 = lend;
//
//	}
//
//
//
//
//	printf("%s\n", arr);
//	return 0;
//}

//int my_strlen(char* arr,int lend) {
//	int count = 0;
//	for (int i = 0; i < lend; i++) {
//		if (arr[i] != '\0') {
//			count++;
//		}
//	}
//	return count;
//}

//int main() {
//	char arr[100]={0};
//	gets(arr);
//	int lend = sizeof(arr) / sizeof(arr[0]);
//	int len=my_strlen(arr,lend);
//
//	printf("%d\n", len);
//
//	return 0;
//
//}

//int my_strlen(char* arr) {
//	int count = 0;
//	while (*arr) {
//		count++;
//		arr++;
//		
//	}
//	return count;
//}
//
//int main() {
//	char arr[100] = { 0 };
//
//	gets(arr);
//
//	int len=my_strlen(arr);
//
//	p
//}

//void reverst(char* left, char* right) {
//
//	while (left < right) {
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main() {
//	char arr[100] = { 0 };
//
//	gets(arr);
//
//	int len = strlen(arr);
//	
//	//��䷴ת
//	reverst(arr, arr + len - 1);
//
//	//���ʷ�ת
//	char* left_1 = arr;
//	while (*left_1) {
//		char* right_1 = left_1;
//		while (*right_1 != ' ' && *right_1 != '\0') {
//			right_1++;
//		}
//		reverst(left_1, right_1-1);
//		
//		if (*right_1 == ' ') {
//			left_1 = right_1 + 1;
//		}
//		else {
//			left_1 = right_1;
//		}
//	}
//
//
//	printf("%s\n", arr);
//
//	return 0;
//}

//int main() {
//	int arr[10] = { 0 };
//
//	int *p = arr;//����д��=>int (*p)[10]=arr;
//	int(*p1)[10] = &arr;
//
//	printf("%p\n", arr);//��Ԫ�ص�ַ
//	printf("%p\n", &arr);//�����ַ
//
//	printf("%p\n", p);//�����ַ
//	printf("%p\n", p1);//�����ַ
//
//
//	printf("%p\n", arr + 1);//��Ԫ�ص���һ��Ԫ�ص�ַ
//	printf("%p\n", &arr + 1);//�������һ�������ַ
//	printf("%p\n", p + 1);//�������һ�������ַ
//	printf("%p\n", p1 + 1); //�������һ�������ַ
//
//
//	return 0;
//}
//void print(int* p, int sz) {
//	for (int i = 0; i < sz; i++) {
//		p[i] = printf("%d ", *p + i);
//	}
//}
//
//int main() {
//	int arr[10] = { 0 };
//	print(arr, 10);
//	printf("\n");
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//
//}
void init(int(*arr)[5], int* li_1, int* col_1) {
	int num = 0;
	for (int i = 0; i < *li_1; i++) {
		for (int j = 0; j < *col_1; j++) {
			arr[i][j] = num++;
		}
	}
}

int find_num(int(*arr)[5],  int*  li_1, int* column_1, const int* num_1) {
	int x = 0, y = *column_1 - 1;

	while (x < *li_1&& y >= 0) {
		if (arr[x][y] < *num_1) {
			x++;
		}
		else if (arr[x][y] > *num_1) {
			y--;
		}
		else {
			*li_1 = x;
			*column_1 = y;
			return 1;
		}

	}
	return 0;
}
int main() {
	
	int arr[4][5] = { 0 };
	int line = 4;
	int column = 5;

	int num = 0;
	init(arr, &line, &column);//��ά�����ʼ��
	scanf("%d", &num);
	int tmp = find_num(arr, &line, &column,&num);//����
	
	if (tmp == 1) {//�ж�
		printf("�������±���arr[%d][%d]\n", line, column);
	}
	else
		printf("�����������\n");

	return 0;
}