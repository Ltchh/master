#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<graphics.h>
//initgraph(int width,int height,int flag=NULL); ���ڳ�ʼ����ͼ����
// width ָ�����ڵĿ��
// height ָ�����ڵĸ߶�
// flag   ���ڵ���ʽ,Ĭ��NULL

//closegraph �رջ�ͼ����
//cleardevice ��ջ�ͼ�豸
int main() {

	
		initgraph(480, 560);//��ʼ�����ڴ�С �������������Բ�д
		//SHOWCONSOLE 1	����ͼ�񴰿�ʱ��������̨
		//NOCLOSE	  2	û�йرչ���
		//NOMINIMIZE  4 û����С������

		setfillcolor(BLUE);//��Ҫ����Բ�����ɫ
		fillcircle(30, 240, 10);//Բ��λ���������С
		getchar();

	closegraph();//�رջ�ͼ����

	return 0;
}