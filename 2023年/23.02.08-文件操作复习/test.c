#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//������-��׼�����
//stdin - ��׼������ -����
//stdout - ��׼����� -��Ļ
//stderr - ��׼������ -��Ļ

//int main() {
//	char arr[] = "Oh my friend dont apos let me alone!";
//
//	//���ļ�
//	FILE* pc_1 = fopen("alone.txt", "w");
//	//FILE* fopen(const char* filename,const char* made);
//
//	//"r"-> ��Ϊ�˶�,������ļ������ڻ���û���ҵ��Ļ����ʧ��(�򲻿��ļ�)
//	//"w"-> ��һ���յ��ļ�Ϊ��д,�������ļ��Ѿ�����,�������ݻᱻ����;û�лᴴ���ļ�
//	//"a"->	��Ϊ��д,���ļ���ĩβ׷��
//						 
//	if (pc_1 == NULL) {
//		perror("pc_1");
//		return;
//	}
//
//	//�ر��ļ�
//	fclose(pc_1);
//	pc_1 = NULL;
//
//	return 0;
//}


//д�ļ�
//int main() {
//
//	char ch[] = "Oh my friend dont apos let me alone!";
//	//���ļ�
//	FILE* pc_1 = fopen("friend.txt", "w");
//	if (pc_1 == NULL) {
//		perror("pc_1");
//		return 1;
//	}
//
//	//д���ļ�
//	//fputs(ch, pc_1);//���ļ�������
//	fputs(ch, stdout);//����Ļ������ == printf("%s",arr)
//
//
//	//�ر��ļ�
//	fclose(pc_1);
//	pc_1 = NULL;
//
//	return 0;
//}
//
////���ļ�-fgtes���ļ����ȡ��
//int main() {
//
//	char ch[] = "Oh my friend dont apos let me alone!";
//	//���ļ�
//	FILE* pc_1 = fopen("friend.txt", "w");
//	if (pc_1 == NULL) {
//		perror("pc_1");
//		return 1;
//	}
//
//	//���ļ�
//	char* ret=fgetc(pc_1);
//	printf("%c", ret);
//	//fputs(ch, stdout);
//
//	//�ر��ļ�
//	fclose(pc_1);
//	pc_1 = NULL;
//
//	return 0;
//}

//�����϶�ȡ��
//
//int main() {
//
//	int ren = fgetc(stdin);
//	fputs(ren, stdout);
//	return 0;
//}

////дһ��
//int main() {
//
//	char ch[] = "Oh my friend dont \napos let me alone!";
//
//	//���ļ�
//	FILE* npc = fopen("alone.txt", "w");
//	if (npc == NULL) {
//		perror("npc");
//		return 1;
//	}
//
//	//д�ļ�--������д
//
//	fputs(ch, npc);//���ļ�д������
//
//
//
//	//�ر��ļ�
//	fclose(npc);
//	npc = NULL;
//	return 0;
//}

//��һ��
//int main() {
//
//	char ch[80] = "Oh my friend dont \napos let me alone!";
//	char ch_1[50] = { 0 };
//	//���ļ�
//	FILE* npc = fopen("alone.txt", "r");
//	if (npc == NULL) {
//		perror("npc");
//		return 1;
//	}
//
//	//���ļ�--�����ж�
//
//	fgets(ch_1,5,npc);//���ļ�д������
//	//��ȡ��5-1���ַ�5������\0
//
//
//
//	//�ر��ļ�
//	fclose(npc);
//	npc = NULL;
//	return 0;
//}

typedef struct student {
	char name[15];
	int age;
	char tel[13];
}student;

//�Ը�ʽ��������д��
//int main() {
//
//	student s = { "���˵�",15,"13851250489" };
//	//���ļ�
//	FILE* pt = fopen("alone.txt", "w");
//	if (pt == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//�Ը�ʽ��������д��
//	fprintf(pt, "%s %d %s\n", s.name, s.age, s.tel);
//
//	//�ر��ļ�
//	fclose(pt);
//	pt = NULL;
//
//	return 0;
//}

//�Ը�ʽ�ļ������ݶ�ȡ
//int main() {
//
//	student s = {0};
//	//���ļ�
//	FILE* pt = fopen("alone.txt", "r");
//	if (pt == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//�Ը�ʽ�������ݶ�ȡ
//	fscanf(pt, "%s %d %s\n", s.name, &(s.age), s.tel);
//
//	//��ӡ
//	printf("%s,%d,%s", s.name, s.age, s.tel);	//����Ļ�����
//	fprintf(stdout,"%s,%d,%s", s.name, s.age, s.tel);//����Ļ������Ļ�����
//	//�������
//
//
//	//�ر��ļ�
//	fclose(pt);
//	pt = NULL;
//
//	return 0;
//}


//���ļ�������д��Ͷ�
//int main() {
//	student s = { "���˵�",19,"13861155644" };
//
//	//���ļ�
//	FILE* pc_life = fopen("alone.txt", "w");
//	if (pc_life == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//������д���ļ�
//	fwrite(&s,sizeof(s),1,pc_life);
//	//size_t fwrite(const void* buffer, size_t size, size_t count, FILE * stream);
//
//	//�ر��ļ�
//	fclose(pc_life);
//	pc_life = NULL;
//	return 0;
//}

int main() {
	student s = {0 };

	//���ļ�
	FILE* pc_life = fopen("alone.txt", "r");
	if (pc_life == NULL) {
		perror("fopen");
		return 1;
	}

	//�����ƶ��ļ�
	fread(&s, sizeof(s), 1, pc_life);
	//size_t fread(const void* buffer, size_t size, size_t count, FILE * stream);

	printf("%s %d %s", s.name, s.age, s.tel);

	//�ر��ļ�
	fclose(pc_life);
	pc_life = NULL;
	return 0;
}