#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<graphics.h>//easyXͼ�ο�ͷ�ļ�
#include<mmsystem.h>//��ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")//���ؾ�̬��

void playBGM() {
	//1.������->���ý���豸�ӿڷ���һ���ַ���,����һ��ָ��
	mciSendString(L"open ./res/123456.wma alias BGM", 0, 0, 0);//alias(����) BGM->./res/123456.wma ������BGM
	//2.��������
	mciSendString(L"play ./res/123456.wma", 0, 0, 0);
	//3.�ر�����
	Sleep(14000);//��ʱ���� 1��=1000����
	mciSendString(L"close ./res/123456.wma",0,0,0);
}

int main() { 

	initgraph(640, 480);//��ʼ������

	IMAGE img; //����һ��ͼƬ����;�ʹ���int����һ��

	loadimage(&img, L"C:\\Users\\lifet\\source\\repos\\easyXͼ�ο����ͼƬ\\res\\YLI1R5O4~KMC7R)Z3ES0MBD.png");//ͼ�μ���   ---����д��C:/Users/lifet/.....(\���Ҫ��ӡ���ת�����Ҫ\\)
	//loadimage(&img, L"C:/Users/lifet/source/repos/easyXͼ�ο����ͼƬ/res/YLI1R5O4~KMC7R)Z3ES0MBD.png");//  /����д��C:\\Users\\lifet\\.....(Ҳ���Ի���)
	//���ﱨ�������3�ַ���1:""ǰ���ϴ�дL
	//					   2:_L("")  ��һ��������·����������
	//					   3:��Ŀ->easyX����->��������->����->�ַ���->��Ϊ���ַ���

	putimage(0,0,&img);//x0,y0ͼƬ����//ͼƬ��ַ

	//���ı�����ɫ
	//setbkcolor(YELLOW);//���ı�����ɫ
	//cleardevice();//���֮ǰ�ı���ɫ

	//��������
	playBGM();
	while (1) {

	}
	return 0;
}
