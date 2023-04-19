#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<graphics.h>//easyX图形库头文件
#include<mmsystem.h>//多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")//加载静态库

void playBGM() {
	//1.打开音乐->向多媒体设备接口发送一个字符串,代表一个指令
	mciSendString(L"open ./res/123456.wma alias BGM", 0, 0, 0);//alias(别名) BGM->./res/123456.wma 更换成BGM
	//2.播放音乐
	mciSendString(L"play ./res/123456.wma", 0, 0, 0);
	//3.关闭音乐
	Sleep(14000);//延时函数 1秒=1000毫秒
	mciSendString(L"close ./res/123456.wma",0,0,0);
}

int main() { 

	initgraph(640, 480);//初始化窗口

	IMAGE img; //定义一个图片变量;和储存int类型一样

	loadimage(&img, L"C:\\Users\\lifet\\source\\repos\\easyX图形库加载图片\\res\\YLI1R5O4~KMC7R)Z3ES0MBD.png");//图形加载   ---可以写成C:/Users/lifet/.....(\如果要打印这个转义符需要\\)
	//loadimage(&img, L"C:/Users/lifet/source/repos/easyX图形库加载图片/res/YLI1R5O4~KMC7R)Z3ES0MBD.png");//  /可以写成C:\\Users\\lifet\\.....(也可以混用)
	//这里报错可以有3种方法1:""前加上大写L
	//					   2:_L("")  用一个函数把路径包含起来
	//					   3:项目->easyX属性->配置属性->常规->字符集->改为多字符集

	putimage(0,0,&img);//x0,y0图片坐标//图片地址

	//更改背景颜色
	//setbkcolor(YELLOW);//更改背景颜色
	//cleardevice();//清除之前的背景色

	//加载音乐
	playBGM();
	while (1) {

	}
	return 0;
}
