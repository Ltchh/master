#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define MALLOC(X,BUFF) malloc(X*sizeof(BUFF))

int main(){
	int i = 5;
	int* pc = MALLOC(i, int);
	if (pc == NULL){
		perror("MALLOC");
		return 1;
	}

	free(pc);
	pc == NULL;

	FILE* pt = fopen("test.txt", "r");//打开文件
	if (pt == NULL) {
		perror("fopen");
		return 1;
	}

	FILE* pf = fopen("test2.txt", "w");//打开文件
	if (pf == NULL) {
		fclose(pt);
		pt == NULL;
		return 1;
	}

	//打开成功

	//fgetc函数在读取结束的时候,会返回EOF
	//正常读取的时候,返回的是读取到的是字符的ASCLL码值

	//fgets函数在读取结束的时候,会返回NULL
	//正常的书的时候返回存放字符传空间的起始地址

	//frend 函数在读取的时候,返回的是实际读取到的完整元素的个数
	//如果发现读取到的完整的元素的个数小于指定元素的个数,这就是最后一次读取

	int ch;
	while ((ch = fgetc(pt)) != EOF)
	{
		//读写文件
		fputc(ch, pf);
		//当读取失败的时候或者遇到文件结束的时候都会返回EOF
		
	}

	//判断什么原因结束的
	if (feof(pt))//ferror返回值为int 非0
		printf("遇到文件结束标准,文件正常结束");
	else if (ferror(pf)) //和eof比较
		printf("文件读取失败");

	//关闭文件
	fclose(pt, pf);
	pt = NULL;
	pf == NULL;
	return 0;
}