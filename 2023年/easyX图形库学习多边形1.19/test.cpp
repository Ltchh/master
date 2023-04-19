#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<easyx.h>

struct num {
	int a;
	int b;
	char c;
}s;

void my_polygon() {//绘制多边形

	POINT points[] = { {-200,100},{200,100},{200,-100},{-200,-100} };//(struct结构体) 各个顶点函数的坐标

	int num = sizeof(points) / sizeof(points[0]);//计算多少个顶点连成多边形

	polygon(points, num);//多边形函数
}

void my_polyline() {//绘制多边不封闭图形

	POINT points[] = { {-200,100},{200,100},{200,-100},{-200,-100} };//(struct)

	int num = sizeof(points) / sizeof(points[0]);

	polyline(points, num);
}

int main() {
	int width = 800,
		height = 600;

	initgraph(width, height);//初始化绘画窗口

	setorigin(width / 2, height / 2);//切换逻辑坐标点

	setaspectratio(1, -1);//-1->Y轴方向

	//my_polygon();//绘制多边形

	my_polyline();//绘制不封闭的图形


	getchar();//阻塞程序,输入按键在关闭

	closegraph();//关闭绘图窗口

	return 0;
}