#pragma once
#include"contact.h"

#include"contact.h"

void num() {
	printf("\n***** < 界面 > ****\n");
	printf("***** 1.ADD    ****\n");
	printf("***** 2.MODIFY ****\n");
	printf("***** 3.DELE   ****\n");
	printf("***** 4.SEARCH ****\n");
	printf("***** 5.SORT   ****\n");
	printf("***** 6.PRINT  ****\n");
	printf("***** 0.EXIT   ****\n");
	printf("*******************\n");

}

//枚举类型
enum {
	EXIT,	//退出
	ADD,	//添加
	MODIFY,	//修改
	DELE,	//删除
	SEARCH,	//查找
	SORT,	//排序
	PRINT,	//打印
};

//版本2
//动态版本
//1.通讯录初始化后能存放3个人的信息
//2.当我们存放的空间不满的时候 自动添加4个信息空间


int main() {

	int input;

	contact con;

	initcontact(&con);//结构体初始化

	ifcontact_y_n(&con);//初始化在堆区创建动态内存

	fread_file(&con);//加载文件

	do
	{
		num();//菜单

		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD://通讯录添加

			addcontact(&con);
			break;
		case MODIFY://通讯录修改

		modifycontact(&con);
			break;
		case DELE://通讯录删除 

			delecontact(&con);
			break;
		case SEARCH://通讯录查找

			searchcontact(&con);
			break;
		case SORT://通讯录排序

			sortcontact(&con);
			break;
		case PRINT://通讯录打印

			printcontact(&con);
			break;
		case EXIT: //通讯录退出

			exit_save_file(&con);//退出保存文件

			exitcontact(&con);//销毁申请的动态内存

			printf("退出程序");
			break;
		default:
			printf("选择错误!\n");
		}
		printf("\n已存储:%d\n\n", con.num);
	} while (input);

	return 0;
}

