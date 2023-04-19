#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stru {
	char name[20];
	int age;
	char tele[12];
	char addr[50];
}stru;

typedef struct class {
	stru* st_1;
	int sz;
}class;

//void print(class* classer) {
//	for (int i = 0; i <= 1; i++) {
//		printf("%s ", classer->date->name);
//		printf("%d ", classer->date->age);
//		printf("%s ", classer->date->tele);
//		printf("%s ", classer->date->addr);
//	}
//}

void structer(class* classer) {

	classer->st_1 = (stru*)malloc(3 * (sizeof(stru)));
	if (classer->st_1 == NULL) {
		perror("structer");
		return;
	}
	classer->sz = 0;
}

int main(){

	class classer;
	//结构初始化
	structer(&classer);

	//扩容
	stru* prt = (stru*)realloc(classer.st_1, 5 * sizeof(stru));
		if (prt != NULL) {
			classer.st_1 = prt;
		}
		else {
			perror("structer");
			return;
		}

		free(classer.st_1);
		classer.st_1 = NULL;
	//print(&classer);



	return 0;
}