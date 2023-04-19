#pragma once
#include"contact.h"

void initcontact(contact* con) {//初始化结构体
	con->date = (peoinfo*)(malloc(MAX_SZ * (sizeof(peoinfo))));
	if (con->date == NULL) {
		perror("initcontact_malloc");
		return;
	}
	con->num = 0;
	con->capacity = MAX_CAPA;
}


void ifcontact_y_n(contact* con) {//确认是否需要创建更多的堆区
	if (con->num == con->capacity) {
		peoinfo* ptr=realloc(con->date, (con->capacity + MAX_SZ) * sizeof(peoinfo));
		if (ptr != NULL) {
			con->date = ptr;
			con->capacity += MAX_SZ;
			printf("\n已经申请内存成功!~\n\n");
		}
		else{
			perror("realloc");
			return;
		}
	}	
}

void fread_file(contact * con){//加载文件
	FILE* ptr = fopen("contact.txt", "r");//打开文件只读
	if (ptr == NULL) {
		perror("fread_file");
		return;
	}
	peoinfo tmp;
	while (fread(&tmp, sizeof(peoinfo), 1, ptr)) {
		ifcontact_y_n(con);
		con->date[con->num] = tmp;
		con->num++;	
	}

	fclose(ptr);//关闭文件
	ptr = NULL;
}

void print_1(contact* con, int i) {//打印分支
	printf("%-4s\t", con->date[i].name);
	printf("%-4d\t", con->date[i].age);
	printf("%-4s\t", con->date[i].sex);
	printf("%-13s\t", con->date[i].tele);
	printf("%-50s\n", con->date[i].addr);
}

int search_1(contact* con) {//查找分支
	int n;
	char name_1[MAX_NAME];
	scanf("%s", name_1);

	for (n = 0; n < con->num; n++) {
		if ((strcmp(con->date[n].name, name_1)) == 0)
			return n;
	}
	return -1;
}



void addcontact(contact* con) {//添加联系人
	printf("请输入姓名:");scanf("%s", con->date[con->num].name);
	printf("请输入年龄:");scanf("%d", &(con->date[con->num].age));
	printf("请输入性别:");scanf("%s", con->date[con->num].sex);
	printf("请输入电话:");scanf("%s", con->date[con->num].tele);
	printf("请输入地址:");scanf("%s", con->date[con->num].addr);
	con->num++;
	printf("\n添加成功\n");
}

void modifycontact(contact* con) {//修改联系人
	printf("请输入修改的联系人的姓名:");
	
	int i=search_1(con);

	if (i < 0)
		printf("需要修改的人的信息不存在\n");
	else {
		printf("请输入姓名:"); scanf("%s", con->date[i].name);
		printf("请输入年龄:"); scanf("%d", &(con->date[i].age));
		printf("请输入性别:"); scanf("%s", con->date[i].sex);
		printf("请输入电话:"); scanf("%s", con->date[i].tele);
		printf("请输入地址:"); scanf("%s", con->date[i].addr);
		printf("\n修改成功\n");
	}
}

void delecontact(contact* con) {//删除联系人

	if (con->num != 0) {
		printf("请输入需要删除人的姓名:");
		int i = search_1(con);
		if (i < 0)
			printf("需要删除的人了的信息不存在!请添加联系人!");
		else
		{
			for (int n = i; n < con->num-1; n++) {
				con->date[i] = con->date[i + 1];
			}
			printf("\n删除成功\n");
			con->num--;
		}
	}
	else
		printf("\n存储空间未添加人员信息!请添加!\n");
	
}

void searchcontact(contact * con){//查找联系人

	printf("请输入需要查询的姓名:");
	int i = search_1(con);
	
	//未找到
	if (i < 0) {
		printf("需要查询的信息不存在!请添加信息!~\n");
	}
	//找到
	else
	{
		printf("%-4s\t%-4s\t%-4s\t%-13s\t%-15s\n", "姓名", "年龄", "性别", "电话", "地址");
		print_1(con, i);
	}
}

void sortcontact(contact* con) {//排序联系人
	
	for (int i = 0; i < con->num; i++) {
		for (int j = 0; j < con->num - 1 - i; j++) {
			if (strcmp(con->date[j].name, con->date[j + 1].name)> 0) {
				peoinfo ptr=con->date[j];
				con->date[j] = con->date[j + 1];
				con->date[j + 1] = ptr;
			}
		}	
	}
	
	printf("\n排序成功\n");
}

void printcontact(contact* con) {//打印联系人

	printf("%-4s\t%-4s\t%-4s\t%-13s\t%-15s\n", "姓名", "年龄", "性别", "电话", "地址");

	for (int i = 0; i < con->num; i++) {
		print_1(con, i);//打印分支
	}
	printf("\n打印完成\n");
}

void exit_save_file(contact* con) {//退出保存文件
	FILE* ptr = fopen("contact.txt", "w");//打开文件
	if (ptr == NULL) {
		perror("fopen");
		return;
	}
	
	for (int i = 0; i < con->num; i++) {
		fwrite(con->date + i, sizeof(peoinfo), 1, ptr);
		//解释:con->dete+i=>目标的起始位置
		//	  :sizeof(peoinfo)=>目标类型的大小空间
		//	  :1=>存放一个peoinfo大小的数据
		//	  :存放位置的变量	
	}

	fclose(ptr);//关闭文件
	ptr = NULL;

}


void exitcontact(contact* con) {//退出程序

	free(con->date);
	con->date= NULL;
	con->num = 0;
	con->capacity = 0;
}