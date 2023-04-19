#define  _CRT_SECURE_NO_WARNINGS
#include"information.h"

void InitEmpl_er(Information* empl_er) {//初始化结构体
	empl_er->date = MALLOC(E_SZ ,Employee);//申请动态内存
	if (empl_er->date==NULL){
		perror("InitEml_er");
		return;
	}
	empl_er->number = 0;
	empl_er->pa = E_PA;
}

void Full_pace(Information* empl_er) {//判断空间是够存储
	Employee* pta = NULL;
	if (empl_er->number == empl_er->pa) {
		pta = (Employee*)realloc(empl_er->date,(empl_er->number + empl_er->pa) * SIZEOF(Employee));
		if (pta != NULL){
			empl_er->date = pta;
			empl_er->pa += E_PA;
			printf("<<已扩容>>");
		}
		else
		{
			perror("Fill_pace");
			return;
		}
	}

}

void print(Information* empl_er,int* i) {//显示分支
	printf("%s\t %s\t %s\t %d\t %d\t %s\t %s\t %s\n",
		empl_er->date[*i].emp_num,
		empl_er->date[*i].emp_name,
		empl_er->date[*i].emp_sex,
		empl_er->date[*i].emp_age,
		empl_er->date[*i].emp_sen,
		empl_er->date[*i].emp_pos,
		empl_er->date[*i].emp_depart,
		empl_er->date[*i].emp_addr
	);
}

void Add_Information(Information* empl_er) {//录入
	
	Full_pace(empl_er);//判断空间是够存储

	printf("<<录入信息>>\n");
	printf("请输入员工编号:"); scanf("%s", empl_er->date[empl_er->number].emp_num);
	printf("请输入员工姓名:"); scanf("%s", empl_er->date[empl_er->number].emp_name);
	printf("请输入员工性别:"); scanf("%s", empl_er->date[empl_er->number].emp_sex);
	printf("请输入员工年龄:"); scanf("%d", &(empl_er->date[empl_er->number].emp_age));
	printf("请输入员工工龄:"); scanf("%d", &(empl_er->date[empl_er->number].emp_sen));
	printf("请输入员工职务:"); scanf("%s", empl_er->date[empl_er->number].emp_pos);
	printf("请输入员工部门:"); scanf("%s", empl_er->date[empl_er->number].emp_depart);
	printf("请输入员工住址:"); scanf("%s", empl_er->date[empl_er->number].emp_addr);
	empl_er->number++;
	system("cls");//清屏
}

void fread_file(Information* empl_er) {//加载文件
	FILE* pt = fopen("Information.txt", "r");//打开文件只读
	if (pt == NULL) {
		perror("fopen");
		return;
	}

	Employee ptr;//创建一个结构体存储肝写入的结构体信息

	while (fread(&ptr, sizeof(Employee), 1, pt)) {//写入结构体存储
		Full_pace(empl_er);
		empl_er->date[empl_er->number] = ptr;
		empl_er->number++;
	}

	fclose(pt);//关闭文件
	pt = NULL;
}

void num_1() {//子栏目
	system("cls");//清屏
	printf("************************************\n");
	printf("**         企业员工管理程序       **\n");
	printf("************************************\n");
	printf("***        1.姓名                ***\n");
	printf("***        2.部门-性别           ***\n");
	printf("***        3.年龄范围-性别       ***\n");
	printf("***        4.部门-工龄           ***\n");
	printf("***                              ***\n");
	printf("***        0.退出                ***\n");
	printf("************************************\n");

}


int Search_1(Information* empl_er, char* emp_n) {//查找分支
	for (int i = 0; i < empl_er->number; i++) {
		if (strcmp(empl_er->date[i].emp_num, emp_n) == 0) {
			return i;
		}
	}
	return -1;
}

void Dele__Information(Information* empl_er) {//删除
	int i;
	char emp_n[E_NUM];
	printf("请输入删除员工信息的编号:");
	scanf("%s", emp_n);
	i = Search_1(empl_er, emp_n);
	if (i >= 0)//找到
	{
		for (int j = i; j < empl_er->number - 1; j++) {
			empl_er->date[i] = empl_er->date[i + 1];
		}
		printf("\n删除成功\n");
		empl_er->number--;
	}
	else//未找到
	{
		printf("\n未查询到信息\n");
	}
}

void Search_information(Information* empl_er) {//查找
	int input;

	int i = 0;
	int j = -1;

	char emp_n[E_NAME];

	char emp_pos[E_POS];
	char emp_sex[E_SEX];

	int emp_age_1;
	int emp_age_2;

	char emp_depart[E_DEPART];
	int emp_sen;

	num_1();//子栏目
	printf("请输入:");
	scanf("%d", &input);
	switch (input) {
	case 1://姓名查找
		printf("请输入要查询的姓名:");//******************************
		scanf("%s", emp_n);
		for (int i = 0; i < empl_er->number; i++) {
			if (strcmp(empl_er->date->emp_name, emp_n) == 0) {
				j = i;
				break;
			}
		}
		//找到 
		if (j >= 0) {
			print(empl_er, &j);
		}

		//未找到
		else {
			printf("未查询到\n");
			return;
		}
		break;

	case 2://部门 性别
		printf("请输入员工部门:"); scanf("%s", emp_pos);
		printf("请输入员工性别:"); scanf("%s", emp_sex);
		for (i = 0; i < empl_er->number; i++) {
			if ((strcmp(empl_er->date[i].emp_pos, emp_pos) == 0) && (strcmp(empl_er->date[i].emp_sex, emp_sex) == 0)) {
				print(empl_er, &i);
			}
		}
		break;
	case 3://龄范围-性别
		printf("请输入员工年龄范围(用空格分开;例:(0 10)):"); scanf("%d %d", &emp_age_1, &emp_age_2);
		printf("请输入员工性别:"); scanf("%s", emp_sex);
		for (i = 0; i < empl_er->number; i++){
			if ((strcmp(empl_er->date[i].emp_sex, emp_sex) == 0) && (empl_er->date[i].emp_age > emp_age_1) && (empl_er->date[i].emp_age < emp_age_2)) 
				print(empl_er, &i);
			
		}
			break;
		case 4://部门-工龄
			printf("请输入员工工龄:"); scanf("%d", &emp_sen);
			printf("请输入员工部门:"); scanf("%s", emp_depart);
			for (i = 0; i < empl_er->number; i++) {
				if ((strcmp(empl_er->date[i].emp_depart, emp_depart) == 0) && (empl_er->date[i].emp_sen = emp_sen))
					print(empl_er, &i);
			}
			break;
		case 0:
			break;
	
		default:
		printf("\n选择错误\n");
	}
}

void Modify_Information(Information* empl_er) {//修改
	char emp_num[E_NUM];
	printf("\n请输入修改员工的编号:");
	scanf("%s", emp_num);
	int i = Search_1(empl_er, emp_num);
	if (i < 0) {
		printf("\n需要修改的员工信息不存在!请添加信息!\n");
	}
	else {
		printf("请输入员工编号:"); scanf("%s", empl_er->date[empl_er->number].emp_num);
		printf("请输入员工姓名:"); scanf("%s", empl_er->date[empl_er->number].emp_name);
		printf("请输入员工性别:"); scanf("%s", empl_er->date[empl_er->number].emp_sex);
		printf("请输入员工年龄:"); scanf("%d", &(empl_er->date[empl_er->number].emp_age));
		printf("请输入员工工龄:"); scanf("%d", &(empl_er->date[empl_er->number].emp_sen));
		printf("请输入员工职务:"); scanf("%s", empl_er->date[empl_er->number].emp_pos);
		printf("请输入员工部门:"); scanf("%s", empl_er->date[empl_er->number].emp_depart);
		printf("请输入员工住址:"); scanf("%s", empl_er->date[empl_er->number].emp_addr);

	}
}

void Display_information(Information* empl_er) {//显示
	int i;
	system("cls");//清屏
	printf("<<显示全部员工信息>>\n");
	printf("%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", "编号", "姓名", "性别", "年龄", "工龄", "职务", "部门", "家庭");
	for (i = 0; i < empl_er->number; i++) {
		print(empl_er, &i);
	}
	printf("\n");
}

void Exit_system(Information* empl_er) {//退出系统

	FILE* pt = fopen("Information.txt", "w");//打开文件
	if (pt == NULL) {
		perror("Exit_system");
		return;
	}

	for (int i = 0; i < empl_er->number; i++) {
		fwrite(empl_er->date + i, sizeof(Employee), 1, pt);
	}

	fclose(pt);//关闭文件
	pt = NULL;
	
	free(empl_er->date);
	empl_er->number = 0;
	empl_er->pa = 0;
	printf("\n退出成功\n");
}
