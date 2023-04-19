#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MALLOC(X,BUFF) ((BUFF*)malloc(X*sizeof(BUFF))) //扩容宏

#define STU_M 20
#define TEN_M 15
#define	ADDR_M 30
#define WE_M 15
#define STU_S_M 3



#define SZ_MAX 5
#define CAP_MAX 4

typedef struct Student {
	char stu_num[STU_M];		//学号
	char stu_name[TEN_M];		//姓名
	char stu_sex[STU_S_M];		//性别
	char stu_spe[TEN_M];		//专业
	char stu_class[TEN_M];		//班级
	char stu_dorm_num[TEN_M];	//宿舍号
	char stu_addr[ADDR_M];		//籍贯
	char tele[WE_M];			//手机号
	char qq[TEN_M];			//QQ号
	char wechat[WE_M];		//微信号
	char emil[ADDR_M];
}Student;

typedef struct Inform_a {
	Student* dete;
	int num;
	int cap;
}Inform_a;

enum {
	EXIT,	//退出	
	ADD,	//添加
	QUERY,	//查询
	DELE,	//删除
	MODIFY,	//修改
	OUTPUT,	//输出
	SORT	//排序
};

void initialization(Inform_a* inform);//初始化

void IF_Information(Inform_a* inform);//判断申请的堆区内存是否够用->扩容

void File_R_initialization(Inform_a* inform);//加载文件

void Add_Information(Inform_a* inform);//添加联系人

int IF_Query(Inform_a* inform, char* stu_num);//查询分支

void Query_Information(Inform_a* inform);//查询

void Dele_Information(Inform_a* inform);//删除

void Modify_Information(Inform_a* inform);//修改

void Output_Information(Inform_a* inform);//输出联系人

void Sort_Information(Inform_a* inform);//排序

void Exit_Information(Inform_a* inform);//退出