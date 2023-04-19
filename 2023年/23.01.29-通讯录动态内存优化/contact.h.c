#define  _CRT_SECURE_NO_WARNINGS

#include"contact.h"

//初始化
//静态版
//void initcontact(contact* con) {
//	memset(con->date, 0, sizeof(con->date));
//	con->sz = 0;
//	}

//动态版
void initcontact(contact* con) {

	con->date = (peoinfo*)malloc(DEEFAULT_SZ * sizeof(peoinfo));
	//创建动态内存空间;把存放的空间返回的地址强制转换成创建的结构体指针把指针存放在date里

	if (con->date == NULL) {
		perror("initcontact");
		return;
	}

	con->sz = 0;//初始化后默认为0

	con->capacity = DEEFAULT_SZ;

	}


//打印_1
void print_1(contact* con2, int* i) {
	printf("%-4s", con2->date[*i].name);
	printf("\t%-4d", con2->date[*i].age);
	printf("\t%-4s", con2->date[*i].sex);
	printf("\t%-13s", con2->date[*i].tele);
	printf("\t%-20s\n", con2->date[*i].addr);
}

//查找_1
int search(contact* con, char* name_1) {
	for (int i = 0; i < con->sz; i++) {
		if ((strcmp(con->date[i].name, name_1)) == 0)
			return i;
	}
	return -1;
}

//添加静态
//void addcontact(contact* con) {
//
//	if (con->sz == MAX) {
//		printf("通讯录已满!\n");
//		return;
//	}
//	printf("请输入姓名:>");
//	scanf("%s", con->date[con->sz].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(con->date[con->sz].age));
//	printf("请输入性别:>");
//	scanf("%s", con->date[con->sz].sex);
//	printf("请输入电话:>");
//	scanf("%s", con->date[con->sz].tele);
//	printf("请输入地址:>");
//	scanf("%s", con->date[con->sz].addr);
//	con->sz++;
//	printf("((添加成功))\n");
//}

// 添加 动态内存
void addcontact(contact* con) {

	if (con->sz == con->capacity) {
		//考虑增加它的容量
		peoinfo* ptr=realloc(con->date, (con->capacity + INC_SZ) * sizeof(peoinfo));
		if (ptr != NULL) {
			con->date = ptr;
			con->capacity += INC_SZ;
			printf("增加容量成功\n");
		}
		else
			perror("addcontact");//报错提示
			return;
	}
	printf("请输入姓名:>");
	scanf("%s", con->date[con->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(con->date[con->sz].age));
	printf("请输入性别:>");
	scanf("%s", con->date[con->sz].sex);
	printf("请输入电话:>");
	scanf("%s", con->date[con->sz].tele);
	printf("请输入地址:>");
	scanf("%s", con->date[con->sz].addr);
	con->sz++;
	printf("((添加成功))\n");
}

//修改
void modifycontact(contact* con) {
	char name_1[MAX_NAME];
	printf("请输入需要修改的姓名:>");
	scanf("%s", name_1);
	int pos = search(con, name_1);

	if (pos < 0) {
		printf("输入的姓名不存在!\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", con->date[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &(con->date[pos].age));
	printf("请输入性别:>");
	scanf("%s", con->date[pos].sex);
	printf("请输入电话:>");
	scanf("%s", con->date[pos].tele);
	printf("请输入地址:>");
	scanf("%s", con->date[pos].addr);
	printf("((修改成功))\n");
}

//删除
void delecontact(contact* con) {
	char name_1[MAX_NAME];
	printf("请输入删除人姓名:>");
	scanf("%s", name_1);
	int pos = search(con, name_1);
	if (pos < 0) {
		printf("(未查询到)");
		return;
	}
	for (int i = pos; i < con->sz - 1; i++) {
		con->date[i] = con->date[i + 1];
	}
	con->sz--;
	printf("删除成功\n");
}

//查找
void searchcontact(contact* con) {
	char name_1[MAX_NAME];
	printf("请输入姓名:>");
	scanf("%s", name_1);
	int pos = search(con, name_1);
	if (pos < 0) {
		printf("未储存此人信息!\n");
		return;
	}

	
	printf("%-4s\t%-4s\t%-4s\t%-13s\t%-20s\n",
		"姓名", "年龄", "性别", "电话", "地址");
	print_1(con, &pos);

}

//打印
void printcontact(contact* con1) {
	printf("%-4s\t%-4s\t%-4s\t%-13s\t%-20s\n", 
		"姓名", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < con1->sz; i++) {
		print_1(con1, &i);
	}
}

//排序
void sortcontact(contact* con) {
	for (int i = 0; i < con->sz - 1; i++) {
		for (int j = 0; j < con->sz - i - 1; j++) {
			if (strcmp(con->date[j].name, con->date[j + 1].name) > 0) {
				peoinfo tmp = con->date[j];
				con->date[j] = con->date[j + 1];
				con->date[j + 1] = tmp;
			}
		}
	}
	printcontact(con);//排序后打印一下
}

//销毁申请的动态内存
void deletecontact(contact* con) {
	free(con->date);
	con->date = (NULL);
	con->capacity = 0;
}