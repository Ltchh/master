#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//新单词
//stream	流
//offset	抵消(偏移量)
//origin	起源(起始位置)


void my_fseek(FILE* pf) {
	

	//读取文件
	int ch = fgetc(pf);
	printf("%c", ch);
	fseek(pf, 5, SEEK_CUR); //-1向前移一位 1是向后移一位->读取pf文件起始位置偏移量为5的字符
	//解释:pf文件指针,-1是偏移量,SEEK_CUR偏移方向
	//int fseek(FILE* stream,long offset,int origin);

	//调整文件指针
	//SEEK_CUR		当前文件指针的位置
	//SEEK_END		文件末尾
	//SEEK_SET		文件起始位置

	ch = fgetc(pf);
	printf("%c", ch);

	ch = fgetc(pf);
	printf("%c", ch);
}

int my_ftell(FILE* pf) {//返回值为int类型->读取文件fseek函数的偏移量
	int num=ftell(pf);
	return num;
}

void my_rewind() {
	//fgetc函数在读取结束的时候,会返回EOF
	//正常读取的时候,返回的是读取到的是字符的ASCLL码值

	//fgets函数在读取结束的时候,会返回NULL
	//正常的书的时候返回存放字符传空间的起始地址

	//frend 函数在读取的时候,返回的是实际读取到的完整元素的个数
	//如果发现读取到的完整的元素的个数小于指定元素的个数,这就是最后一次读取

}

int main() {
	FILE* pf = fopen("fseek_file.dat", "r");//打开-只读
	if (pf == NULL) {
		perror("fopen");
		return;
	}

	my_fseek(pf);//文件随机读取定位->根据文本偏移量读取

	int num = my_ftell(pf);//返回值为int类型->读取文件fseek函数的偏移量
	printf("\n%d\n", num);

	void my_rewind(pf);//判断文件结束返回值
	//跳转teat.txt拷贝一份生成一份test2.txt文件

	fclose(pf);//关闭
	pf = NULL;

	return 0;
}

