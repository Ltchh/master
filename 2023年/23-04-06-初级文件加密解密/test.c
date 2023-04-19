#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define CODE 10

int main() {

	FILE* ptr = fopen("beautiful.txt","r");	//打开文件 读
	if (NULL == ptr) {
		perror("ptr fopen failure!");
		return;
	}

	FILE* pta = fopen("beautiful-1.txt", "w");	//打开文件 写
	if (NULL==pta){
		perror("pta fopen failure");
		return;
	}

	char ch;

	
	while (ch = fgetc(ptr) != EOF) { //fgetc读取文件一个字符赋值给ch
		
		ch += CODE;				  //以哥字符加10后赋值给ch
		fputc(ch, pta);			  //fputc写入文件 ch中读取一个字符写入到pta;
	}

	fclose(ptr);	//关闭文件	
	fclose(pta);

	return 0;
}

//逆向操作解密