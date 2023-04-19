#define  _CRT_SECURE_NO_WARNINGS

#include"information.h"
void menu() {
	printf("\n");
	printf("***************************\n");
	printf("* 通  *********************\n");
	printf("*     **   1.添加联系人  **\n");
	printf("* 讯  **   2.查询联系人  **\n");
	printf("*     **   3.删除联系人  **\n");
	printf("* 录  **   4.修改联系人  **\n");
	printf("*  |  **   5.输出联系人  **\n");
	printf("*  |  **   6.学号  排序  **\n");
	printf("* 管  **   0.退出  程序  **\n");
	printf("* 理  *********************\n");
	printf("***************************\n\n");

}

int main() {
	int input;

	

	Inform_a inform;//创建一个指向结构体的指针
	
	initialization(&inform);//初始化

	File_R_initialization(&inform);//加载文件

	do {

		menu();//菜单

		printf("请选择:>");
		scanf("%d", &input);

		switch (input){

			case ADD:	//添加
				Add_Information(&inform);

				break;

			case QUERY:	//查询
				Query_Information(&inform);
				break;

			case DELE:	//删除
				Dele_Information(&inform);
				break;

			case MODIFY://修改
				Modify_Information(&inform);
				break;

			case OUTPUT://输出
				Output_Information(&inform);
				break;

			case SORT:	//排序
				Sort_Information(&inform);
				break;

			case EXIT:	//退出
				Exit_Information(&inform);
				break;
		default:
			printf("\n输入错误.\n");
		}

	} while (input);

	return;
}