#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<easyx.h>//easyXͼ�ο�
#include<time.h>//ʱ���
#include<math.h>

#include<mmsystem.h>//��ý���
#pragma comment(lib,"winmm.lib")//ý����ļ�

void my_outtextxy() {//����ı�
	int x1 = 1020;
	int y1 =750;

	settextcolor(YELLOW);//����������ɫ
	settextstyle(20,0,"����");//25->�ֺ�;"����"����
	outtextxy(x1, y1, "ʱ��:���������");//��ӡ�ı�
	outtextxy(x1, y1+20, "����:�޺���");//��ӡ�ı�

}
void my_circle() {	//����Բ
	setaspectratio(1, -1);//-1 y�ᷴ��
	int x1 = 0,		//Բ��x����
		y1 = 0,		//Բ��y����
		radius = 50;//԰�İ뾶
	circle(x1, y1, radius);//����Բ�ĺ���
}

void my_circle_1() {//����ͬ��Բ
	setaspectratio(1, -1);//-1 y�ᷴ��

	for (int r = 50; r <= 300; r += 50) {
		circle(0, 0, r);
	}
}

void my_putpixel() {//����5������ɫ�ĵ�
	setaspectratio(1, -1);//-1 y�ᷴ��
	putpixel(0, 0, RED);		 //���ĵ�Ϊ��ɫ
	putpixel(200, 200, YELLOW);	 //������Ϊ��ɫ
	putpixel(200, -200, GREEN);	 //���ϴ�Ϊ��ɫ
	putpixel(-200, 200, WHITE);	 //������Ϊ��ɫ
	putpixel(-200, -200, CYAN);  //���ϴ�Ϊ��ɫ
}

void my_line() {
	setaspectratio(1, -1);//-1 y�ᷴ��
	line(-200, 200, 200, -200);//ǰ��������Ϊһ������,������Ϊһ������
	line(-200, -200, 200, 200); 
}

void my_rectangle() {//���ƾ���
	setaspectratio(1, -1);//-1 y�ᷴ��
	int left=-200,		//�������Ͻ�x����
		top=100,		//�������Ͻ�y����
		right=200,		//�������½�x����
		bottom=-100;	//�������½�y����
	rectangle(left, top, right, bottom);//���ƾ��κ���
}

void my_ellipse() {//��Բ����
	setaspectratio(1, -1);//-1 y�ᷴ��
	int left=-200,	//��Բ���о������Ͻ�x����
		top=100,	//��Բ���о������Ͻ�y����
		right=200,	//��Բ���о������½�x����
		bottom=-100;//��Բ���о������½�y����
	ellipse(left, top, right, bottom);//������Բ����
}

void my_roundrect() {//Բ�Ǿ���
	setaspectratio(1, -1);//-1 y�ᷴ��
	int left = -200,	//��Բ���о������Ͻ�x����
		top = 200,		//��Բ���о������Ͻ�y����
		right = 200,	//��Բ���о������½�x����
		bottom = -200,	//��Բ���о������½�y����
		ellipsewidth=200,	//����Բ�Ǿ��ε�Բ�ǵĿ��
		ellipseheight=200;	//����Բ�Ǿ��ε�Բ�ǵĸ߶�
	roundrect(left, top, right, bottom, ellipsewidth, ellipseheight);//Բ�Ǿ��κ���
}

void my_pie() {//��������
	setaspectratio(1, -1);//-1 y�ᷴ��
	int left = -200,	//��Բ���о������Ͻ�x����
		top = 200,		//��Բ���о������Ͻ�y����
		right = 200,	//��Բ���о������½�x����
		bottom = -200;	//��Բ���о������½�y����
	double stangle = 0,			//������ʼ�ǵĻ���
		  endangle = 3.14 / 4;	//���ͽ����ǵĻ���
	pie(left, top, right, bottom, stangle, endangle);
}

void my_arc() {//����Բ��
	setaspectratio(1, -1);//-1 y�ᷴ��
	int left = -200,	//��Բ���о������Ͻ�x����
		top = 200,		//��Բ���о������Ͻ�y����
		right = 200,	//��Բ���о������½�x����
		bottom = -200;	//��Բ���о������½�y����
	double stangle = 0,			//������ʼ�ǵĻ���
		endangle = 3.14 / 4;	//���ͽ����ǵĻ���
	arc(left, top, right, bottom, stangle, endangle);//����Բ��

}

void my_mcisendstring() {//���Ŷ�ý��
	mciSendString("open 123456.wma",0,0,0);//�򿪶�ý���ļ�
	mciSendString("play 123456.wma",0,0,0);//���Ŷ�ý���ļ�
	//mciSendString("pause 123456.wma",0,0,0);//��ͣ��ý���ļ�
	//mciSendString("close 123456.wma",0,0,0);//�رն�ý���ļ�
}

//�̻���
struct jet {
	int x1, y1;//��ǰ����
	int xh, yh;//��ߵ�����
	unsigned long t1, t2, dt;//ʱ���������ٶ�
	IMAGE img;//����ͼƬ����
	bool isshoot;//�ж�ʯ��������״̬
}jet;

//�̻�
struct Fire {
	int r;//��ǰ�뾶
	int max;//���뾶
	int x, y;//���ĵ�����(���ڵ�����)
	int cx, cy;//���ĵ�����(ͼƬ����)
	int xy[564][550];
	bool isboom;//�Ƿ�ʼ��ը
	bool isdraw;//�Ƿ�����ʾ
	unsigned long t1, t2, dt;//��ը���ٶ�
}fire;



int main() {

	srand(time(0));

	int width = 1200;	//���ڿ��
	int height = 800;	//���ڸ߶�

	initgraph(width, height);//��ʼ����ͼ����

	//setorigin(width/2, height/2);//�л��߼��������ĵ�

	my_outtextxy();//�ı����

	//my_circle();	//����Բ��

	//my_circle_1();//����ͬ��Բ

	//my_putpixel();//����5������ɫ�ĵ�

	//my_line();	//����һ��ֱ��

	//my_rectangle();//����һ������

	//my_ellipse();//����һ����Բ

	//my_roundrect();//����Բ�Ǿ���

	//my_pie();//��������

	//my_arc();//����Բ��

	my_mcisendstring();//����ý���ļ�

	//�ݻ�����ʼ��
	jet.x1 = rand() % (1200 - 20);
	jet.y1 = 750;
	jet.xh = width;
	jet.yh = rand() % 750;
	jet.t1 = GetTickCount();//��ȡϵͳʱ�亯��
	jet.dt = 10;//10����
	jet.isshoot = true;//�Ƿ�������״̬
	loadimage(&jet.img, "����.png", 20, 50);//��ʼ��ͼƬ����,�ļ���,�ļ�����
	putimage(jet.x1, jet.y1,&jet.img,SRCINVERT);
	
	//��ʼ���̻�
	fire.r=0;//��ǰ�뾶
	fire.max=275;//���뾶
	//fire.x, fire.y;//�̻�������ߵ�//���ĵ�����(���ڵ�����)
	fire.cx=275, fire.cy=275;//���ĵ�����(ͼƬ����)
	
	fire.isboom=false;//�Ƿ�ʼ��ը
	fire.isdraw=false;//�Ƿ�����ʾ
	fire.t1=GetTickCount();
	//fire.t2;
	fire.dt = 5;//��ը���ٶ�

	fire.xy[565][550];
	IMAGE fimg;
	loadimage(&fimg, "1532.jpg", 565, 550);
	SetWorkingImage(&fimg);
	for (int i = 0; i < 275; i++) {
		for (int j = 0; j < 275; j++) {

			fire.xy[i][j] = getpixel(i, j);
			SetWorkingImage(&fimg);
		}
	}
	
	while (1) {
		jet.t2 = GetTickCount();
		if (jet.t2 - jet.t1 > jet.dt && jet.isshoot == true) {
			putimage(jet.x1, jet.y1, &jet.img, SRCINVERT);
			if (jet.y1 > jet.yh) 
				jet.y1 -= 5;
			putimage(jet.x1, jet.y1, &jet.img, SRCINVERT);
			if (jet.y1 <= jet.yh) {
				//�����̻���
				putimage(jet.x1, jet.y1, &jet.img, SRCINVERT);
				//�����̻���
				jet.isshoot = false;
			}
			if (jet.isshoot == false /*&&�̻��������*/) {
				jet.x1 = rand() % (800 - 20);
				jet.y1 = 550;
				jet.xh = width;
				jet.yh = rand() % 350;
				jet.t1 = GetTickCount();//��ȡϵͳʱ�亯��
				jet.dt = 10;//10����
				jet.isshoot = true;//�Ƿ�������״̬
				loadimage(&jet.img, "����.png", 20, 50);//��ʼ��ͼƬ����,�ļ���,�ļ�����

				putimage(jet.x1, jet.y1, &jet.img, SRCINVERT);
			}

			
			jet.t1 = jet.t2;
		}
		//dt
		int drt[27] = { 5,5,5,8,8,8,15,15,15,20,20,20,40,40,40,50,50,50,60,60,60,70,70,70,80,80,80 };
		fire.t2 = GetTickCount();
		if (fire.t2 - fire.t1 > fire.dt && fire.isboom == true) {
			if (fire.r < fire.max) {
				fire.r++;
				fire.dt = drt[fire.r / 10];
				fire.isdraw = true;
			}
			if (fire.r >= fire.max - 1) {
				fire.isdraw = false;
				fire.isboom = false;
				fire.dt = 5;
				fire.t1 = GetTickCount();
				fire.r = 0;
			}
			fire.t1 = fire.t2;
		}
		//ѭ������628 2PI
		if (fire.isdraw == true) {
			for (double i = 0; i <= 6.28; i += 0.01) {
				int x11 = fire.cx + fire.r * cos(i);
				int y11 = fire.cy - fire.r * sin(i);
				fire.xy[x11][y11];
			}
		}
	}

	getchar();				//��ʱ��������,�ȴ��û������ٹر�

	closegraph();			//void closegraph();	�رջ�ͼ���ں���

	return 0;
}