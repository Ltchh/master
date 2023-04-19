#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//流概念-标准输出流
//stdin - 标准输入流 -键盘
//stdout - 标准输出流 -屏幕
//stderr - 标准错误流 -屏幕

//int main() {
//	char arr[] = "Oh my friend dont apos let me alone!";
//
//	//打开文件
//	FILE* pc_1 = fopen("alone.txt", "w");
//	//FILE* fopen(const char* filename,const char* made);
//
//	//"r"-> 打开为了读,如果这文件不存在或者没有找到的话会打开失败(打不开文件)
//	//"w"-> 打开一个空的文件为了写,如果这个文件已经给了,它的内容会被销毁;没有会创建文件
//	//"a"->	打开为了写,在文件的末尾追加
//						 
//	if (pc_1 == NULL) {
//		perror("pc_1");
//		return;
//	}
//
//	//关闭文件
//	fclose(pc_1);
//	pc_1 = NULL;
//
//	return 0;
//}


//写文件
//int main() {
//
//	char ch[] = "Oh my friend dont apos let me alone!";
//	//打开文件
//	FILE* pc_1 = fopen("friend.txt", "w");
//	if (pc_1 == NULL) {
//		perror("pc_1");
//		return 1;
//	}
//
//	//写入文件
//	//fputs(ch, pc_1);//给文件输入流
//	fputs(ch, stdout);//给屏幕输入流 == printf("%s",arr)
//
//
//	//关闭文件
//	fclose(pc_1);
//	pc_1 = NULL;
//
//	return 0;
//}
//
////读文件-fgtes从文件里读取流
//int main() {
//
//	char ch[] = "Oh my friend dont apos let me alone!";
//	//打开文件
//	FILE* pc_1 = fopen("friend.txt", "w");
//	if (pc_1 == NULL) {
//		perror("pc_1");
//		return 1;
//	}
//
//	//读文件
//	char* ret=fgetc(pc_1);
//	printf("%c", ret);
//	//fputs(ch, stdout);
//
//	//关闭文件
//	fclose(pc_1);
//	pc_1 = NULL;
//
//	return 0;
//}

//键盘上读取流
//
//int main() {
//
//	int ren = fgetc(stdin);
//	fputs(ren, stdout);
//	return 0;
//}

////写一行
//int main() {
//
//	char ch[] = "Oh my friend dont \napos let me alone!";
//
//	//打开文件
//	FILE* npc = fopen("alone.txt", "w");
//	if (npc == NULL) {
//		perror("npc");
//		return 1;
//	}
//
//	//写文件--按照行写
//
//	fputs(ch, npc);//给文件写入数据
//
//
//
//	//关闭文件
//	fclose(npc);
//	npc = NULL;
//	return 0;
//}

//读一行
//int main() {
//
//	char ch[80] = "Oh my friend dont \napos let me alone!";
//	char ch_1[50] = { 0 };
//	//打开文件
//	FILE* npc = fopen("alone.txt", "r");
//	if (npc == NULL) {
//		perror("npc");
//		return 1;
//	}
//
//	//读文件--按照行读
//
//	fgets(ch_1,5,npc);//给文件写入数据
//	//读取了5-1个字符5包含了\0
//
//
//
//	//关闭文件
//	fclose(npc);
//	npc = NULL;
//	return 0;
//}

typedef struct student {
	char name[15];
	int age;
	char tel[13];
}student;

//对格式化的数据写入
//int main() {
//
//	student s = { "王八蛋",15,"13851250489" };
//	//打开文件
//	FILE* pt = fopen("alone.txt", "w");
//	if (pt == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//对格式化的数据写入
//	fprintf(pt, "%s %d %s\n", s.name, s.age, s.tel);
//
//	//关闭文件
//	fclose(pt);
//	pt = NULL;
//
//	return 0;
//}

//对格式文件的数据读取
//int main() {
//
//	student s = {0};
//	//打开文件
//	FILE* pt = fopen("alone.txt", "r");
//	if (pt == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//对格式化的数据读取
//	fscanf(pt, "%s %d %s\n", s.name, &(s.age), s.tel);
//
//	//打印
//	printf("%s,%d,%s", s.name, s.age, s.tel);	//在屏幕上输出
//	fprintf(stdout,"%s,%d,%s", s.name, s.age, s.tel);//在屏幕上用屏幕流输出
//	//两行相等
//
//
//	//关闭文件
//	fclose(pt);
//	pt = NULL;
//
//	return 0;
//}


//对文件二进制写入和读
//int main() {
//	student s = { "王八蛋",19,"13861155644" };
//
//	//打开文件
//	FILE* pc_life = fopen("alone.txt", "w");
//	if (pc_life == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//二进制写入文件
//	fwrite(&s,sizeof(s),1,pc_life);
//	//size_t fwrite(const void* buffer, size_t size, size_t count, FILE * stream);
//
//	//关闭文件
//	fclose(pc_life);
//	pc_life = NULL;
//	return 0;
//}

int main() {
	student s = {0 };

	//打开文件
	FILE* pc_life = fopen("alone.txt", "r");
	if (pc_life == NULL) {
		perror("fopen");
		return 1;
	}

	//二进制读文件
	fread(&s, sizeof(s), 1, pc_life);
	//size_t fread(const void* buffer, size_t size, size_t count, FILE * stream);

	printf("%s %d %s", s.name, s.age, s.tel);

	//关闭文件
	fclose(pc_life);
	pc_life = NULL;
	return 0;
}