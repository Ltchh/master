#define  _CRT_SECURE_NO_WARNINGS

#include"information.h"

void initialization(Inform_a* inform) {//初始化
	inform->dete = MALLOC(SZ_MAX, Student);
	if (inform->dete == NULL)
		perror("initalization");
	inform->num = 0;
	inform->cap = CAP_MAX;
}

void print(Inform_a* inform, int i) {//打印分支
	printf("序:(%d)\n 学  号:%-15s\n 姓  名:%-5s\n 性  别:%-4s\n 专  业:%-4s\n 班  级:%-4s\n 宿舍号:%-4s\n "
			"籍  贯:%-30s\n 电  话:%-12s\n QQ  :%-12s\n 微  信:%-12s\n Emil  :%-12s\n------------------------------\n",
		1+i,
		inform->dete[i].stu_num,
		inform->dete[i].stu_name,
		inform->dete[i].stu_sex,
		inform->dete[i].stu_spe,
		inform->dete[i].stu_class,
		inform->dete[i].stu_dorm_num,
		inform->dete[i].stu_addr,
		inform->dete[i].tele,
		inform->dete[i].qq,
		inform->dete[i].wechat,
		inform->dete[i].emil
		);
}

int IF_Query(Inform_a* inform, char* stu_num) {//查询分支
	for (int i = 0; i < inform->num; i++) {
		if (strcmp(inform->dete[i].stu_num, stu_num) == 0)
			return i;
	}
	return -1;
}

void IF_Information(Inform_a* inform) {//判断申请的堆区内存是否够用->扩容
	Student* pta;
	if (inform->cap == inform->num) {
		pta =(Student*)realloc(inform->dete,(inform->num + SZ_MAX)*sizeof(Student));
		if (pta != NULL) {
			inform->dete = pta;
			inform->cap += SZ_MAX;
			printf("\n<<已扩容>>\n");
		}
		else{
			perror("IF_Information");
			return;
		}	
	}	
}

void File_R_initialization(Inform_a* inform) {//加载文件
	FILE* tmp = fopen("initialization.txt", "r");//打开文件 只读
	if (tmp == NULL) {
		perror("File_R_initialization");
		return;
	}

	Student tmp_1;
	while (fread(&tmp_1, sizeof(Student), 1, tmp)) {//二进制读取文件
		IF_Information(inform);
		inform->dete[inform->num] = tmp_1;
		inform->num++;
	}	

	fclose(tmp);	//关闭文件
	tmp == NULL;
}

void Add_Information(Inform_a* inform) {//添加联系人
	
	IF_Information(inform);//判断申请的堆区内存是否够用->扩容
	
	//录入联系人
	printf("请输入  学号:"); scanf("%s", inform->dete[inform->num].stu_num);
	printf("请输入  姓名:"); scanf("%s", inform->dete[inform->num].stu_name);
	printf("请输入  性别:"); scanf("%s", inform->dete[inform->num].stu_sex);
	printf("请输入  专业:"); scanf("%s", inform->dete[inform->num].stu_spe);
	printf("请输入  班级:"); scanf("%s", inform->dete[inform->num].stu_class);
	printf("请输入宿舍号:"); scanf("%s", inform->dete[inform->num].stu_dorm_num);
	printf("请输入  籍贯:"); scanf("%s", inform->dete[inform->num].stu_addr);
	printf("请输入手机号:"); scanf("%s", inform->dete[inform->num].tele);
	printf("请输入  QQ号:"); scanf("%s", inform->dete[inform->num].qq);
	printf("请输入微信号:"); scanf("%s", inform->dete[inform->num].wechat);
	printf("请输入  emil:"); scanf("%s", inform->dete[inform->num].emil);
	inform->num++;
	
	system("pause");//暂停
	system("cls");//清屏
}

void Query_Information(Inform_a* inform) {//查询
	if (inform->num > 0) {
		char stu_num[STU_M];
		printf("请输入学号:");
		scanf("%s", stu_num);

		int i = IF_Query(inform, stu_num);//查询分支
	
		if (i >= 0) {//找到
			print(inform, i);
		}

		else{//未找到
			printf("(未添加)\n");

		}
		system("pause");//暂停
		system("cls");//清屏
	}

	else {
		printf("\n(空通讯录)\n");
		system("pause");//暂停
		system("cls");//清屏
	}
}

void Dele_Information(Inform_a* inform) {//删除
	if (inform->num > 0) {
		char stu_num[STU_M];
		printf("请输入学号:");
		scanf("%s", stu_num);

		int i = IF_Query(inform, stu_num);//查询分支

		if (i >= 0) {//找到
			for (int num = i; num < inform->num; num++) {
				inform->dete[num] = inform->dete[num + 1];
				inform->num--;
			}
			printf("(删除成功)");
		}

		else {//未找到
			printf("(未添加)\n");
		}
		system("pause");//暂停
		system("cls");//清屏
	}

	else {
		printf("\n(空通讯录)\n");
		system("pause");//暂停
		system("cls");//清屏
	}
}

void Modify_Information(Inform_a* inform){//修改
	if (inform->num > 0) {
		char stu_num[STU_M];
		printf("请输入学号:");
		scanf("%s", stu_num);

		int i = IF_Query(inform, stu_num);//查询分支

		if (i >= 0) {//找到
			printf("修改->\n");
			printf("请输入  学号:"); scanf("%s", inform->dete[i].stu_num);
			printf("请输入  姓名:"); scanf("%s", inform->dete[i].stu_name);
			printf("请输入  性别:"); scanf("%s", inform->dete[i].stu_sex);
			printf("请输入  专业:"); scanf("%s", inform->dete[i].stu_spe);
			printf("请输入  班级:"); scanf("%s", inform->dete[i].stu_class);
			printf("请输入宿舍号:"); scanf("%s", inform->dete[i].stu_dorm_num);
			printf("请输入  籍贯:"); scanf("%s", inform->dete[i].stu_addr);
			printf("请输入手机号:"); scanf("%s", inform->dete[i].tele);
			printf("请输入  QQ号:"); scanf("%s", inform->dete[i].qq);
			printf("请输入微信号:"); scanf("%s", inform->dete[i].wechat);
			printf("请输入  emil:"); scanf("%s", inform->dete[i].emil);
			printf("(修改成功)");
		}

		else {//未找到
			printf("(未添加)\n");
		}
		system("pause");//暂停
		system("cls");//清屏
	}

	else {
		printf("\n(空通讯录)\n");
		system("pause");//暂停
		system("cls");//清屏
	}
}


void Output_Information(Inform_a* inform) {//输出
	if (inform->num > 0) {
		if (inform->num != 0) {
			for (int i = 0; i < inform->num; i++) {

				print(inform, i);//打印分支
			}
			system("pause");//暂停
			system("cls");//清屏
		}
		else {
			printf("\n<<未添加联系人>>\n");
			system("pause");//暂停
			system("cls");//清屏
			return;
		}
		system("pause");//暂停
		system("cls");//清屏
	}
	else {
		printf("\n(空通讯录)\n");
		system("pause");//暂停
		system("cls");//清屏
	}
	
}

void Sort_Information(Inform_a* inform) {//排序
	if (inform->num > 0) {
		printf("[以学号排序]");
		for (int i = 0; i < inform->num; i++) {
			for (int j = 0; j < inform->num - i-1; j++) {
				if (strcmp(inform->dete[j].stu_name, inform->dete[j + 1].stu_num) > 0) {
				Student tmp = inform->dete[j];
				inform->dete[j] = inform->dete[j + 1];
				inform->dete[j + 1] = tmp;
				}
			}		
		}
			printf("\n(排序成功)\n");

	}

	else {
		printf("\n(空通讯录)\n");
		system("pause");//暂停
		system("cls");//清屏
	}
}

void Exit_Information(Inform_a* inform) {//退出

	FILE* tmp = fopen("initialization.txt", "w");//打开文件 写入
	if (tmp == NULL) {
		perror("Exit_Information_fopen");
		return;
	}
	for (int i = 0; i <inform->num; i++)
	{
		fwrite(inform->dete+i, sizeof(Student), 1, tmp);
	}	//写入文件

		
		
	fclose(tmp);//关闭文件
	tmp = NULL;

	free(inform->dete);
	inform->dete = NULL;
	inform->num = 0;
	inform->cap = 0;
}
