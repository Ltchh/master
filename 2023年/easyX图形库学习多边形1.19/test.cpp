#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<easyx.h>

struct num {
	int a;
	int b;
	char c;
}s;

void my_polygon() {//���ƶ����

	POINT points[] = { {-200,100},{200,100},{200,-100},{-200,-100} };//(struct�ṹ��) �������㺯��������

	int num = sizeof(points) / sizeof(points[0]);//������ٸ��������ɶ����

	polygon(points, num);//����κ���
}

void my_polyline() {//���ƶ�߲����ͼ��

	POINT points[] = { {-200,100},{200,100},{200,-100},{-200,-100} };//(struct)

	int num = sizeof(points) / sizeof(points[0]);

	polyline(points, num);
}

int main() {
	int width = 800,
		height = 600;

	initgraph(width, height);//��ʼ���滭����

	setorigin(width / 2, height / 2);//�л��߼������

	setaspectratio(1, -1);//-1->Y�᷽��

	//my_polygon();//���ƶ����

	my_polyline();//���Ʋ���յ�ͼ��


	getchar();//��������,���밴���ڹر�

	closegraph();//�رջ�ͼ����

	return 0;
}