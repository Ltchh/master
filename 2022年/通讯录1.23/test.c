#define  _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<string.h>

#define MAX_NAME 20	//姓名
#define MAX_SEX 10	//性别
#define MAX_TELE 12	//电话
#define MAX_ADDR 50//地址
#define MAX 1000


//类型定义

typedef struct Peoinfo {
	char name[MAX_NAME];	//姓名
	char sex[MAX_SEX];		//性别
	int age;				//年纪
	char tele[MAX_TELE];	//电话
	char addr[MAX_ADDR];	//地址
}Peoinfo;


//通讯录
typedef struct contact {
	Peoinfo data[MAX];	//存放添加进来的人的信息	
	int sz;			//记录当前通讯录有效信息  
}contact;

//初始化通讯录
void initcontact(contact* con);

//添加联系人
void addcontact(contact* con);

//删除联系人
void delcontact(contact* con);

//打印联系人信息
void printcontact(const contact* con);

//查找联系人
void searchconcat(contact* con);

//修改联系人
void modfiycontact(contact* con);

//排序联系人
void sortcontact(contact* con);

//通讯录
//1.能够存储1000个人的信息
//	每个人的信息
//	姓名,年龄,性别,电话,地址
//2.增加人的信息
//3.删除指定人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.排序通讯录
void menu() {
	printf("** * * * * * * * * **\n");
	printf("**  1.add          **\n");
	printf("**  2.del          **\n");
	printf("**  3.search       **\n");
	printf("**  4.modify       **\n");
	printf("**  5.sort         **\n");
	printf("**  6.print        **\n");
	printf("**  0.exit         **\n");
	printf("** * * * * * * * * **\n\n");
}


enum Option {
	EXIT,	//退出
	ADD,	//增加
	DEL,	//删除
	SEARCH,	//搜索
	MODIFY,	//修改
	SORT,	//排序
	PRINT,	//打印
};

int main() {
	int input=0;

	//创建通讯录
	contact con;

	//初始化通讯录
	initcontact(&con);

	do {
		//菜单
		menu();
		printf("请选择=>");
		scanf("%d", &input);
		
		switch (input)
		{
		case ADD:	//增加
			addcontact(&con);
			break;
		case DEL:	//删除
			delcontact(&con);
			break;
		case SEARCH://查找
			searchconcat(&con);
			break;
		case MODIFY://修改
			modfiycontact(&con);
			break;
		case SORT:	//排序
			sortcontact(&con);
			break;
		case PRINT:	//打印
			printcontact(&con);
			break;
		case EXIT:
			printf("退出;");
			break;
		default:
			printf("选择错误!");
		}
		printf("\n存储:%d条\n\n",con.sz);
	} while (input);

	return 0;
}


//初始化通讯录
void initcontact(contact* con) {
	con->sz = 0;
	//memset->设置内存函数
	memset(con->data, 0, sizeof(con->data));//con->data初始地址,设置的内容,多少个字节
}

//增加人员信息
void addcontact(contact* con) {
	if (con->sz == MAX) {
		printf("通讯录已满!\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", con->data[con->sz].name);
	printf("请输入性别:>");
	scanf("%s", con->data[con->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &(con->data[con->sz].age));
	printf("请输入电话:>");
	scanf("%s", con->data[con->sz].tele);
	printf("请输入地址:>");
	scanf("%s", con->data[con->sz].addr);
	con->sz++;
	printf("((增加成功))\n");
}

static int finbyname(contact* con2, char* name) {
	for (int i = 0; i <= con2->sz; i++) {
		if (strcmp(con2->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

//删除联系人
void delcontact(contact* con1) {
	char name[MAX_NAME];
	if (con1 == 0) {
		printf("通讯录为空,无需删除;\n");
		return;
	}
	printf("请输入删除人的名字:>");
	scanf("%s", name);
	//查找
	int pos = finbyname(con1, name);
	//没有--有
	if (pos < 0) {
		printf("查找的人不存在!\n");
		return;
	}
	//删除

	for (int i = pos; i < con1->sz - 1; i++) {
		con1->data[i] = con1->data[i + 1];
	}
	con1->sz--;
	printf("删除成功;\n");
}

//打印联系人
void print(int* i, contact* con2) {

	printf("%-4s\t%-4s\t%-4d\t%-12s\t%-20s\n",
		con2->data[*i].name,
		con2->data[*i].sex,
		con2->data[*i].age,
		con2->data[*i].tele,
		con2->data[*i].addr);
}
void printcontact(const contact* con1) {

	printf("%-4s\t%-4s\t%-4s\t%-12s\t%-20s\n",
		"名字", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con1->sz; i++) {
		print(&i, con1);
		/*printf("%-4s\t%-4s\t%-4d\t%-12s\t%-20s\n",
			con->data[i].name,
			con->data[i].sex,
			con->data[i].age,
			con->data[i].tele,
			con->data[i].addr);*/
	}
}

//查找联系人
void searchconcat(contact* con) {
	char name[MAX_NAME];
	printf("请输入查找姓名;>");
	scanf("%s", name);

	int pos = finbyname(con, name);
	if (pos < 0) {
		printf("查找的人不存在;\n");
		return;
	}
	printf("%-4s\t%-4s\t%-4s\t%-12s\t%-20s\n",
		"名字", "性别", "年龄", "电话", "地址");
	print(&pos, con);
}

//修改联系人
void modfiycontact(contact* con) {
	char name[MAX_NAME];
	printf("请输入需要修改的姓名;>");
	scanf("%s", name);
	int pos = finbyname(con, name);
	if (pos < 0) {
		printf("需要修改的人不存在\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", con->data[pos].name);
	printf("请输入性别:>");
	scanf("%s", con->data[pos].sex);
	printf("请输入年龄:>");
	scanf("%d", &(con->data[pos].age));
	printf("请输入电话:>");
	scanf("%s", con->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", con->data[pos].addr);
	printf("((修改成功))");

}

//排序联系人
void sortcontact(contact* con) {
	for (int i = 0; i < con->sz; i++) {
		for (int j = 0; j < con->sz - 1 - i; j++) {
			if (strcmp(con->data[j].name, con->data[j + 1].name) > 0) {
				Peoinfo tmp = con->data[j];
				con->data[j] = con->data[j + 1];
				con->data[j + 1] = tmp;
			}

		}
	}
	printcontact(con);
}