#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//C���Գ���Ĭ�ϴ򿪵�3���� FILE*����ָ��
//stdin - ��׼������ - ���� (c����Ĭ�ϴ����������)
//stdout - ��׼����� - ��Ļ
//stderr - ��׼������ - ��Ļ


//�ļ�·��+�ļ�����+�ļ���׺
//����:e:Vsc\test.c
//void file_opening_and_closeing(){
//
//	//���ļ�
//	FILE *pf=fopen("beautiful.txt", "w");	//���·��
//	FILE *pf=fopen("E:\\Vsc\\23.02.07-�ļ�����\\beautiful.txt", "w");	//����·��
//
//			//����һ��FILE��ָ��(��Ҫ����ָ�����)
//			//���ص���һ��ָ������ǿ�ָ������Ը�����(�򿪴���ͻ᷵���Ը���ָ��)
//			//д�����ʱ����Ҫ�����Ƿ��ǿ�ָ��
//		
//			//	"r":ֻ�� =>Ϊ���������,��һ���Ѿ����ڵ��ļ� =>���������(����/����)
//			//  "w":ֻд =>Ϊ���������,��һ���ļ�		   =>�ļ�������(�½�һ��)	��'W'��ʽ�򿪻�ɾ��֮ǰ���ļ�����������հ��ļ�	
//			//  "a":׷�� =>���ļ�׷β���������			   =>����һ�����ļ�
//			//	"rb":ֻ��=>Ϊ����������,��һ���������ļ�	   =>���������(����/����)
//			//	"wb":ֻд=>Ϊ���������,��һ���������ļ�	   =>����һ�����ļ�
//			//  "ab":��һ���������ļ�β���������			   =>���������(����/����)
// 
			//R(read)  ��ֻ���ķ�ʽ��;����ļ�������.�򱨴�;�ļ�����д
			//W(wrete)					����ļ�������,�򴴽�;����ļ�����,�����;�ļ����ɶ�
			//A(add-on)���ļ���׷��;    ����ļ�������,�򴴽�;����ļ�����,׷��д;�ļ����ɶ�
			//r+		
			//w+
			//a+
// 
//	if (pf == NULL)
//	{
//		perror("fopenʧ��");
//		return 1;
//	}

//	//�ر��ļ�
//	fclose(pf);
//			//int fclose(FILE* stream)  //stream ��
//	pf = NULL;
//}

//void input_file() {
// 
//	char arr[] = " oh my gril dont apos let me alone";
// //���ļ�
//	FILE* pf=fopen("lifetime.txt", "w");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	//�ļ�(Ӳ��)-->�ڴ�(����)(����/��ȡ)
//	 //�ڴ�(����)-->�ļ�(Ӳ��)(���/д��)
// //д��
// 
// 	fputc('a', pr);  //һ�ζ���һ���ַ�
//д��һ���ַ�;д��ɹ�����һ��int����;д�벻�ɹ�����һ��EOF;
//ѭ����ȡ��ʱ�������EOF��β
//�൱���ַ����е�/0
// 
//	fputs(arr, pf);//д��һ��char�����ַ�
//			//int fputc(int c,FILE*stream);

//	//fputs(arr, stdout);
//
// //�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//}

//void read_file() {
//	//���ļ�
//	FILE* pf_1=fopen("lifetime.txt", "r");
//	if (pf_1 == NULL) {
//		perror("pf_1open");
//		return 1;
//	}
//
//	//���ļ�
//	int ret=fgetc(pf_1);
//	//printf("%c\n", ret);
//	fputc(ret, stdout);//����Ļ��д��ret stdout��Ļ��
//	/*ret = fgetc(pf_1);
//	printf("%c\n", ret);
//	ret = fgetc(pf_1);
//	printf("%c\n", ret);
//	ret = fgetc(pf_1);*/
//	//fgetc��ȡһ���ַ���ָ��ƫ��һλ��ȡ��һλ
//
//	//�ر��ļ�
//	fclose(pf_1);
//	pf_1 = NULL;
//}

void input_multiline_file() {
	char arr[] = "Oh my girl dont apos let me alone";
	//���ļ�
	FILE* ps=fopen("lifetime.txt", "r");
	if (ps == NULL) {
		perror("ps_fopen");
		return 1;
	}

	//����д��
	fgets(arr, 15, ps);
	//char *fgets(char* string,int n,FILE* atream);

	//fputs(arr, stdout);


	//�ر��ļ�
	fclose(ps);
	ps = NULL;
}
int main() {

	//file_opening_and_closeing();//��and�ر��ļ�

	//input_file();//д���ļ�

	//read_file();//��ȡ�ļ�

	input_multiline_file();

	return 0;
}