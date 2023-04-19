#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<easyx.h>//easyX图形库
#include<time.h>//时间库
#include<math.h>

#include<mmsystem.h>//多媒体库
#pragma comment(lib,"winmm.lib")//媒体库文件

void my_outtextxy() {//输出文本
	int x1 = 1020;
	int y1 =750;

	settextcolor(YELLOW);//设置字体颜色
	settextstyle(20,0,"楷体");//25->字号;"楷体"字体
	outtextxy(x1, y1, "时间:二零二三年");//打印文本
	outtextxy(x1, y1+20, "制作:崔海辉");//打印文本

}
void my_circle() {	//绘制圆
	setaspectratio(1, -1);//-1 y轴反向
	int x1 = 0,		//圆的x坐标
		y1 = 0,		//圆的y坐标
		radius = 50;//园的半径
	circle(x1, y1, radius);//绘制圆的函数
}

void my_circle_1() {//绘制同心圆
	setaspectratio(1, -1);//-1 y轴反向

	for (int r = 50; r <= 300; r += 50) {
		circle(0, 0, r);
	}
}

void my_putpixel() {//绘制5个带颜色的点
	setaspectratio(1, -1);//-1 y轴反向
	putpixel(0, 0, RED);		 //中心点为红色
	putpixel(200, 200, YELLOW);	 //东北处为黄色
	putpixel(200, -200, GREEN);	 //东南处为绿色
	putpixel(-200, 200, WHITE);	 //西北处为白色
	putpixel(-200, -200, CYAN);  //西南处为青色
}

void my_line() {
	setaspectratio(1, -1);//-1 y轴反向
	line(-200, 200, 200, -200);//前两个常量为一组坐标,后两个为一组坐标
	line(-200, -200, 200, 200); 
}

void my_rectangle() {//绘制矩形
	setaspectratio(1, -1);//-1 y轴反向
	int left=-200,		//矩形左上角x坐标
		top=100,		//矩形左上角y坐标
		right=200,		//矩形右下角x坐标
		bottom=-100;	//矩形右下角y坐标
	rectangle(left, top, right, bottom);//绘制矩形函数
}

void my_ellipse() {//椭圆函数
	setaspectratio(1, -1);//-1 y轴反向
	int left=-200,	//椭圆外切矩形左上角x坐标
		top=100,	//椭圆外切矩形左上角y坐标
		right=200,	//椭圆外切矩形右下角x坐标
		bottom=-100;//椭圆外切矩形右下角y坐标
	ellipse(left, top, right, bottom);//绘制椭圆函数
}

void my_roundrect() {//圆角矩形
	setaspectratio(1, -1);//-1 y轴反向
	int left = -200,	//椭圆外切矩形左上角x坐标
		top = 200,		//椭圆外切矩形左上角y坐标
		right = 200,	//椭圆外切矩形右下角x坐标
		bottom = -200,	//椭圆外切矩形右下角y坐标
		ellipsewidth=200,	//构成圆角矩形的圆角的宽度
		ellipseheight=200;	//构成圆角矩形的圆角的高度
	roundrect(left, top, right, bottom, ellipsewidth, ellipseheight);//圆角矩形函数
}

void my_pie() {//绘制扇形
	setaspectratio(1, -1);//-1 y轴反向
	int left = -200,	//椭圆外切矩形左上角x坐标
		top = 200,		//椭圆外切矩形左上角y坐标
		right = 200,	//椭圆外切矩形右下角x坐标
		bottom = -200;	//椭圆外切矩形右下角y坐标
	double stangle = 0,			//扇型起始角的弧度
		  endangle = 3.14 / 4;	//扇型结束角的弧度
	pie(left, top, right, bottom, stangle, endangle);
}

void my_arc() {//绘制圆弧
	setaspectratio(1, -1);//-1 y轴反向
	int left = -200,	//椭圆外切矩形左上角x坐标
		top = 200,		//椭圆外切矩形左上角y坐标
		right = 200,	//椭圆外切矩形右下角x坐标
		bottom = -200;	//椭圆外切矩形右下角y坐标
	double stangle = 0,			//扇型起始角的弧度
		endangle = 3.14 / 4;	//扇型结束角的弧度
	arc(left, top, right, bottom, stangle, endangle);//绘制圆弧

}

void my_mcisendstring() {//播放多媒体
	mciSendString("open 123456.wma",0,0,0);//打开多媒体文件
	mciSendString("play 123456.wma",0,0,0);//播放多媒体文件
	//mciSendString("pause 123456.wma",0,0,0);//暂停多媒体文件
	//mciSendString("close 123456.wma",0,0,0);//关闭多媒体文件
}

//烟花弹
struct jet {
	int x1, y1;//当前坐标
	int xh, yh;//最高点坐标
	unsigned long t1, t2, dt;//时间来控制速度
	IMAGE img;//保存图片变量
	bool isshoot;//判断石否在上升状态
}jet;

//烟花
struct Fire {
	int r;//当前半径
	int max;//最大半径
	int x, y;//中心点坐标(窗口的坐标)
	int cx, cy;//中心点坐标(图片坐标)
	int xy[564][550];
	bool isboom;//是否开始爆炸
	bool isdraw;//是否是显示
	unsigned long t1, t2, dt;//爆炸的速度
}fire;



int main() {

	srand(time(0));

	int width = 1200;	//窗口宽度
	int height = 800;	//窗口高度

	initgraph(width, height);//初始化绘图窗口

	//setorigin(width/2, height/2);//切换逻辑坐标中心点

	my_outtextxy();//文本输出

	//my_circle();	//绘制圆形

	//my_circle_1();//绘制同心圆

	//my_putpixel();//绘制5个带颜色的点

	//my_line();	//绘制一条直线

	//my_rectangle();//绘制一个矩形

	//my_ellipse();//绘制一个椭圆

	//my_roundrect();//绘制圆角矩形

	//my_pie();//绘制扇形

	//my_arc();//绘制圆弧

	my_mcisendstring();//播放媒体文件

	//演化弹初始化
	jet.x1 = rand() % (1200 - 20);
	jet.y1 = 750;
	jet.xh = width;
	jet.yh = rand() % 750;
	jet.t1 = GetTickCount();//获取系统时间函数
	jet.dt = 10;//10毫秒
	jet.isshoot = true;//是否是上升状态
	loadimage(&jet.img, "发射.png", 20, 50);//初始化图片变量,文件名,文件像素
	putimage(jet.x1, jet.y1,&jet.img,SRCINVERT);
	
	//初始化烟花
	fire.r=0;//当前半径
	fire.max=275;//最大半径
	//fire.x, fire.y;//烟花弹的最高点//中心点坐标(窗口的坐标)
	fire.cx=275, fire.cy=275;//中心点坐标(图片坐标)
	
	fire.isboom=false;//是否开始爆炸
	fire.isdraw=false;//是否是显示
	fire.t1=GetTickCount();
	//fire.t2;
	fire.dt = 5;//爆炸的速度

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
				//擦除烟花弹
				putimage(jet.x1, jet.y1, &jet.img, SRCINVERT);
				//重置烟花弹
				jet.isshoot = false;
			}
			if (jet.isshoot == false /*&&烟花抱在完毕*/) {
				jet.x1 = rand() % (800 - 20);
				jet.y1 = 550;
				jet.xh = width;
				jet.yh = rand() % 350;
				jet.t1 = GetTickCount();//获取系统时间函数
				jet.dt = 10;//10毫秒
				jet.isshoot = true;//是否是上升状态
				loadimage(&jet.img, "发射.png", 20, 50);//初始化图片变量,文件名,文件像素

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
		//循环的是628 2PI
		if (fire.isdraw == true) {
			for (double i = 0; i <= 6.28; i += 0.01) {
				int x11 = fire.cx + fire.r * cos(i);
				int y11 = fire.cy - fire.r * sin(i);
				fire.xy[x11][y11];
			}
		}
	}

	getchar();				//暂时阻塞程序,等待用户按键再关闭

	closegraph();			//void closegraph();	关闭绘图窗口函数

	return 0;
}