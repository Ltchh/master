#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main() {
//	int n;
//	int arr[100]={0};
//
//	scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        int tmp = 0;
//        scanf("%d", &tmp);
//        if (arr[tmp] == 0) {
//            arr[tmp] = 1;
//        }
//    }
//
//	for (int i = 0; i < n; i++) {
//			if (arr[i] == 1)
//				printf("%d", i);
//	}
//
//	return 0;
//}

 //�������˷������ܸ��ӶȻ������Ҫ��һ���Ż�������Բο�������ʹ���������飬�������ʱ�������������жԱȣ�
//int main() {
//	int n;		//�洢���������ж��ٸ�Ԫ��
//	int arr[50];//�������οɴ洢��Ԫ�ظ���
//
//	scanf("%d", &n);				//����Ԫ�ظ���
//	for (int i = 0; i < n; i++) {	//��������Ԫ��;
//		scanf("%d", &arr[i]);
//	}
//
//	for(int i=0;i<n;i++){			//��׼�����±�
//		
//		for (int j = i + 1; j < n; j++) {		//i�±��Ԫ�غ�i��һ��Ԫ�ص��±�Ƚ�(Ҳ����j=i+1);
//			if (arr[i] == arr[j]) {				//�ж� -->Ҳ����������Ԫ���Ƿ����
//				for (int k = j; k < n ; k++) {	//arr[i]��arr[j]��Ⱥ�Ѻ����Ԫ�ظ��Ǹ�arr[j](Ҳ����arr[k}=arr[k+1]);
//					arr[k] = arr[k + 1];
//				}
//				n--;							//���ǵ�һ��Ԫ�غ��������ĸ���������һλ;
//				j--;							//��ifѭ�����j++�ͻ��������ǵ��Ǹ�Ԫ������--�Ͳ����������Ԫ��
//				
//			}
//		}
//	}
//
//
//
//	return 0;
//}

//int main() {
//    int n;
//    int arr[1000];
//
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (arr[i] == arr[j]) {
//                int k = 0;
//                for (int k = j; k < n; k++) {
//                    arr[k] = arr[k + 1];
//                }
//                n--;
//                j--;
//            }
//            
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

int main() {
    int n, m;
    int x, y;
    int arr[10][10] = { 0 };

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d ", &arr[i][j]);
        }
    }
    scanf("%d %d", &x, &y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == arr[x-1][y-1]) {
                printf("%d ", arr[i][j]);
                break;
            }

        }
    }

    return 0;
}

