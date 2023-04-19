#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//C语言程序默认打开的3个流 FILE*类型指针
//stdin - 标准输入流 - 键盘 (c语言默认打开了这输出流)
//stdout - 标准输出流 - 屏幕
//stderr - 标准错误流 - 屏幕


//文件路径+文件主干+文件后缀
//例如:e:Vsc\test.c
//void file_opening_and_closeing(){
//
//	//打开文件
//	FILE *pf=fopen("beautiful.txt", "w");	//相对路径
//	FILE *pf=fopen("E:\\Vsc\\23.02.07-文件操作\\beautiful.txt", "w");	//绝对路径
//
//			//返回一个FILE的指针(需要用这指针接收)
//			//返回的是一个指针如果是空指针就是以个错误(打开错误就会返回以个空指针)
//			//写代码的时候需要检验是否是空指针
//		
//			//	"r":只读 =>为了输出数据,打开一个已经存在的文件 =>如果不存在(出错/报错)
//			//  "w":只写 =>为了输出数据,打开一个文件		   =>文件不存在(新建一个)	以'W'形式打开会删除之前的文件里的内容做空白文件	
//			//  "a":追加 =>向本文件追尾部添加数据			   =>建立一个新文件
//			//	"rb":只读=>为了输入数据,打开一个二进制文件	   =>如果不存在(出错/报错)
//			//	"wb":只写=>为了输出数据,打开一个二进制文件	   =>建立一个新文件
//			//  "ab":向一个二进制文件尾部添加数据			   =>如果不存在(出错/报错)
// 
			//R(read)  以只读的方式打开;如果文件不存在.则报错;文件不可写
			//W(wrete)					如果文件不存在,则创建;如果文件存在,则清空;文件不可读
			//A(add-on)在文件后追加;    如果文件不存在,则创建;如果文件存在,追加写;文件不可读
			//r+		
			//w+
			//a+
// 
//	if (pf == NULL)
//	{
//		perror("fopen失败");
//		return 1;
//	}

//	//关闭文件
//	fclose(pf);
//			//int fclose(FILE* stream)  //stream 流
//	pf = NULL;
//}

//void input_file() {
// 
//	char arr[] = " oh my gril dont apos let me alone";
// //打开文件
//	FILE* pf=fopen("lifetime.txt", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//文件(硬盘)-->内存(程序)(输入/读取)
//	 //内存(程序)-->文件(硬盘)(输出/写入)
// //写入
// 
// 	fputc('a', pr);  //一次读入一个字符
//写入一个字符;写入成功返回一个int整形;写入不成功返回一个EOF;
//循环读取的时候结束以EOF结尾
//相当与字符串中的/0
// 
//	fputs(arr, pf);//写入一个char类型字符
//			//int fputc(int c,FILE*stream);

//	//fputs(arr, stdout);
//
// //关闭文件
//	fclose(pf);
//	pf = NULL;
//}

//void read_file() {
//	//打开文件
//	FILE* pf_1=fopen("lifetime.txt", "r");
//	if (pf_1 == NULL) {
//		perror("pf_1open");
//		return 1;
//	}
//
//	//读文件
//	int ret=fgetc(pf_1);
//	//printf("%c\n", ret);
//	fputc(ret, stdout);//在屏幕上写入ret stdout屏幕流
//	/*ret = fgetc(pf_1);
//	printf("%c\n", ret);
//	ret = fgetc(pf_1);
//	printf("%c\n", ret);
//	ret = fgetc(pf_1);*/
//	//fgetc读取一个字符后指针偏移一位读取下一位
//
//	//关闭文件
//	fclose(pf_1);
//	pf_1 = NULL;
//}

void input_multiline_file() {
	char arr[] = "Oh my girl dont apos let me alone";
	//打开文件
	FILE* ps=fopen("lifetime.txt", "r");
	if (ps == NULL) {
		perror("ps_fopen");
		return 1;
	}

	//多行写入
	fgets(arr, 15, ps);
	//char *fgets(char* string,int n,FILE* atream);

	//fputs(arr, stdout);


	//关闭文件
	fclose(ps);
	ps = NULL;
}
int main() {

	//file_opening_and_closeing();//打开and关闭文件

	//input_file();//写入文件

	//read_file();//读取文件

	input_multiline_file();

	return 0;
}