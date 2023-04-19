#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<graphics.h>
//initgraph(int width,int height,int flag=NULL); 用于初始化绘图窗口
// width 指定窗口的宽度
// height 指定窗口的高度
// flag   窗口的样式,默认NULL

//closegraph 关闭绘图窗口
//cleardevice 清空绘图设备
int main() {

	
		initgraph(480, 560);//初始化窗口大小 第三个参数可以不写
		//SHOWCONSOLE 1	创建图像窗口时保留操作台
		//NOCLOSE	  2	没有关闭功能
		//NOMINIMIZE  4 没有最小化功能

		setfillcolor(BLUE);//将要绘制圆的填充色
		fillcircle(30, 240, 10);//圆的位置坐标与大小
		getchar();

	closegraph();//关闭绘图窗口

	return 0;
}