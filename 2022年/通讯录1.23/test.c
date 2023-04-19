#define  _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<string.h>

#define MAX_NAME 20	//����
#define MAX_SEX 10	//�Ա�
#define MAX_TELE 12	//�绰
#define MAX_ADDR 50//��ַ
#define MAX 1000


//���Ͷ���

typedef struct Peoinfo {
	char name[MAX_NAME];	//����
	char sex[MAX_SEX];		//�Ա�
	int age;				//���
	char tele[MAX_TELE];	//�绰
	char addr[MAX_ADDR];	//��ַ
}Peoinfo;


//ͨѶ¼
typedef struct contact {
	Peoinfo data[MAX];	//�����ӽ������˵���Ϣ	
	int sz;			//��¼��ǰͨѶ¼��Ч��Ϣ  
}contact;

//��ʼ��ͨѶ¼
void initcontact(contact* con);

//�����ϵ��
void addcontact(contact* con);

//ɾ����ϵ��
void delcontact(contact* con);

//��ӡ��ϵ����Ϣ
void printcontact(const contact* con);

//������ϵ��
void searchconcat(contact* con);

//�޸���ϵ��
void modfiycontact(contact* con);

//������ϵ��
void sortcontact(contact* con);

//ͨѶ¼
//1.�ܹ��洢1000���˵���Ϣ
//	ÿ���˵���Ϣ
//	����,����,�Ա�,�绰,��ַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.�޸�ָ���˵���Ϣ
//5.����ָ���˵���Ϣ
//6.����ͨѶ¼
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
	EXIT,	//�˳�
	ADD,	//����
	DEL,	//ɾ��
	SEARCH,	//����
	MODIFY,	//�޸�
	SORT,	//����
	PRINT,	//��ӡ
};

int main() {
	int input=0;

	//����ͨѶ¼
	contact con;

	//��ʼ��ͨѶ¼
	initcontact(&con);

	do {
		//�˵�
		menu();
		printf("��ѡ��=>");
		scanf("%d", &input);
		
		switch (input)
		{
		case ADD:	//����
			addcontact(&con);
			break;
		case DEL:	//ɾ��
			delcontact(&con);
			break;
		case SEARCH://����
			searchconcat(&con);
			break;
		case MODIFY://�޸�
			modfiycontact(&con);
			break;
		case SORT:	//����
			sortcontact(&con);
			break;
		case PRINT:	//��ӡ
			printcontact(&con);
			break;
		case EXIT:
			printf("�˳�;");
			break;
		default:
			printf("ѡ�����!");
		}
		printf("\n�洢:%d��\n\n",con.sz);
	} while (input);

	return 0;
}


//��ʼ��ͨѶ¼
void initcontact(contact* con) {
	con->sz = 0;
	//memset->�����ڴ溯��
	memset(con->data, 0, sizeof(con->data));//con->data��ʼ��ַ,���õ�����,���ٸ��ֽ�
}

//������Ա��Ϣ
void addcontact(contact* con) {
	if (con->sz == MAX) {
		printf("ͨѶ¼����!\n");
		return;
	}
	printf("����������:>");
	scanf("%s", con->data[con->sz].name);
	printf("�������Ա�:>");
	scanf("%s", con->data[con->sz].sex);
	printf("����������:>");
	scanf("%d", &(con->data[con->sz].age));
	printf("������绰:>");
	scanf("%s", con->data[con->sz].tele);
	printf("�������ַ:>");
	scanf("%s", con->data[con->sz].addr);
	con->sz++;
	printf("((���ӳɹ�))\n");
}

static int finbyname(contact* con2, char* name) {
	for (int i = 0; i <= con2->sz; i++) {
		if (strcmp(con2->data[i].name, name) == 0)
			return i;
	}
	return -1;
}

//ɾ����ϵ��
void delcontact(contact* con1) {
	char name[MAX_NAME];
	if (con1 == 0) {
		printf("ͨѶ¼Ϊ��,����ɾ��;\n");
		return;
	}
	printf("������ɾ���˵�����:>");
	scanf("%s", name);
	//����
	int pos = finbyname(con1, name);
	//û��--��
	if (pos < 0) {
		printf("���ҵ��˲�����!\n");
		return;
	}
	//ɾ��

	for (int i = pos; i < con1->sz - 1; i++) {
		con1->data[i] = con1->data[i + 1];
	}
	con1->sz--;
	printf("ɾ���ɹ�;\n");
}

//��ӡ��ϵ��
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
		"����", "�Ա�", "����", "�绰", "��ַ");
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

//������ϵ��
void searchconcat(contact* con) {
	char name[MAX_NAME];
	printf("�������������;>");
	scanf("%s", name);

	int pos = finbyname(con, name);
	if (pos < 0) {
		printf("���ҵ��˲�����;\n");
		return;
	}
	printf("%-4s\t%-4s\t%-4s\t%-12s\t%-20s\n",
		"����", "�Ա�", "����", "�绰", "��ַ");
	print(&pos, con);
}

//�޸���ϵ��
void modfiycontact(contact* con) {
	char name[MAX_NAME];
	printf("��������Ҫ�޸ĵ�����;>");
	scanf("%s", name);
	int pos = finbyname(con, name);
	if (pos < 0) {
		printf("��Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", con->data[pos].name);
	printf("�������Ա�:>");
	scanf("%s", con->data[pos].sex);
	printf("����������:>");
	scanf("%d", &(con->data[pos].age));
	printf("������绰:>");
	scanf("%s", con->data[pos].tele);
	printf("�������ַ:>");
	scanf("%s", con->data[pos].addr);
	printf("((�޸ĳɹ�))");

}

//������ϵ��
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