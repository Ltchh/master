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

 //法二：此方法可能复杂度会过大，如要进一步优化，则可以参考方法三使用两个数组，在输入的时候便和输出数组进行对比！
//int main() {
//	int n;		//存储数组数组有多少个元素
//	int arr[50];//这个数组课可存储的元素个数
//
//	scanf("%d", &n);				//输入元素个数
//	for (int i = 0; i < n; i++) {	//连续输入元素;
//		scanf("%d", &arr[i]);
//	}
//
//	for(int i=0;i<n;i++){			//基准数组下标
//		
//		for (int j = i + 1; j < n; j++) {		//i下标的元素和i下一个元素的下标比较(也就是j=i+1);
//			if (arr[i] == arr[j]) {				//判断 -->也就是这两个元素是否相等
//				for (int k = j; k < n ; k++) {	//arr[i]和arr[j]相等后把后面的元素覆盖给arr[j](也就是arr[k}=arr[k+1]);
//					arr[k] = arr[k + 1];
//				}
//				n--;							//覆盖掉一个元素后这个数组的个数就少了一位;
//				j--;							//出if循环后就j++就会跳过覆盖的那个元素这里--就不会跳过这个元素
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

