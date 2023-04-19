#include<stdio.h>

int main() {
	FILE* pr = fopen("fopen.txt", "r");
	//R(read)  以只读的方式打开;如果文件不存在.则报错;文件不可写
	//W(wrete)					如果文件不存在,则创建;如果文件存在,则清空;文件不可读
	//A(add-on)在文件后追加;    如果文件不存在,则创建;如果文件存在,追加写;文件不可读
	// 
	//r+		
	//w+
	//a+

	fputc('a', pr);
	//写入一个字符;写入成功返回一个int整形;写入不成功返回一个EOF;
	//循环读取的时候结束以EOF结尾
	//相当与字符串中的/0

	fputs("abcd\n", pr);//整行文本写入
	if (NULL==pr){
		perror("fopen failure!");
		return;
	}

	fclose(pr);

	return 0;
}
