#define  _CRT_SECURE_NO_WARNINGS

#include"information.h"
void num() {
	printf("************************************\n"); 
	printf("**         企业员工管理程序       **\n");
	printf("************************************\n");
	printf("***            1.录入            ***\n");
	printf("***            2.删除            ***\n");
	printf("***            3.修改            ***\n");
	printf("***            4.显示            ***\n");
	printf("***            5.查询            ***\n");
	printf("***            0.退出            ***\n");
	printf("************************************\n");
}

int main() {


	

	Information empl_er;//创建员工信息

	InitEmpl_er(&empl_er);//初始化员工信息

	fread_file(&empl_er);//加载文件

	int input;

	do{
		
		num();	//栏目

		printf("\t请选择:>");
		scanf("%d", &input);

		switch (input){

			case ADD://录入
				Add_Information(&empl_er);
				break;

			case DELE://删除
				Dele__Information(&empl_er);
				break;

			case MODIFY://修改
				Modify_Information(&empl_er);
				break;

			case DISPLAY://显示
				Display_information(&empl_er);
				break;

			case SEARCH://查询
				Search_information(&empl_er);
				break;

			case EXIT:
				Exit_system(&empl_er);
				break; 

			default:
				printf("\n选择错误\n");
			
		}

	} while (input);

	return 0;
}