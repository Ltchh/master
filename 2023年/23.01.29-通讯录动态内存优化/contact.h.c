#define  _CRT_SECURE_NO_WARNINGS

#include"contact.h"

//��ʼ��
//��̬��
//void initcontact(contact* con) {
//	memset(con->date, 0, sizeof(con->date));
//	con->sz = 0;
//	}

//��̬��
void initcontact(contact* con) {

	con->date = (peoinfo*)malloc(DEEFAULT_SZ * sizeof(peoinfo));
	//������̬�ڴ�ռ�;�Ѵ�ŵĿռ䷵�صĵ�ַǿ��ת���ɴ����Ľṹ��ָ���ָ������date��

	if (con->date == NULL) {
		perror("initcontact");
		return;
	}

	con->sz = 0;//��ʼ����Ĭ��Ϊ0

	con->capacity = DEEFAULT_SZ;

	}


//��ӡ_1
void print_1(contact* con2, int* i) {
	printf("%-4s", con2->date[*i].name);
	printf("\t%-4d", con2->date[*i].age);
	printf("\t%-4s", con2->date[*i].sex);
	printf("\t%-13s", con2->date[*i].tele);
	printf("\t%-20s\n", con2->date[*i].addr);
}

//����_1
int search(contact* con, char* name_1) {
	for (int i = 0; i < con->sz; i++) {
		if ((strcmp(con->date[i].name, name_1)) == 0)
			return i;
	}
	return -1;
}

//��Ӿ�̬
//void addcontact(contact* con) {
//
//	if (con->sz == MAX) {
//		printf("ͨѶ¼����!\n");
//		return;
//	}
//	printf("����������:>");
//	scanf("%s", con->date[con->sz].name);
//	printf("����������:>");
//	scanf("%d", &(con->date[con->sz].age));
//	printf("�������Ա�:>");
//	scanf("%s", con->date[con->sz].sex);
//	printf("������绰:>");
//	scanf("%s", con->date[con->sz].tele);
//	printf("�������ַ:>");
//	scanf("%s", con->date[con->sz].addr);
//	con->sz++;
//	printf("((��ӳɹ�))\n");
//}

// ��� ��̬�ڴ�
void addcontact(contact* con) {

	if (con->sz == con->capacity) {
		//����������������
		peoinfo* ptr=realloc(con->date, (con->capacity + INC_SZ) * sizeof(peoinfo));
		if (ptr != NULL) {
			con->date = ptr;
			con->capacity += INC_SZ;
			printf("���������ɹ�\n");
		}
		else
			perror("addcontact");//������ʾ
			return;
	}
	printf("����������:>");
	scanf("%s", con->date[con->sz].name);
	printf("����������:>");
	scanf("%d", &(con->date[con->sz].age));
	printf("�������Ա�:>");
	scanf("%s", con->date[con->sz].sex);
	printf("������绰:>");
	scanf("%s", con->date[con->sz].tele);
	printf("�������ַ:>");
	scanf("%s", con->date[con->sz].addr);
	con->sz++;
	printf("((��ӳɹ�))\n");
}

//�޸�
void modifycontact(contact* con) {
	char name_1[MAX_NAME];
	printf("��������Ҫ�޸ĵ�����:>");
	scanf("%s", name_1);
	int pos = search(con, name_1);

	if (pos < 0) {
		printf("���������������!\n");
		return;
	}
	printf("����������:>");
	scanf("%s", con->date[pos].name);
	printf("����������:>");
	scanf("%d", &(con->date[pos].age));
	printf("�������Ա�:>");
	scanf("%s", con->date[pos].sex);
	printf("������绰:>");
	scanf("%s", con->date[pos].tele);
	printf("�������ַ:>");
	scanf("%s", con->date[pos].addr);
	printf("((�޸ĳɹ�))\n");
}

//ɾ��
void delecontact(contact* con) {
	char name_1[MAX_NAME];
	printf("������ɾ��������:>");
	scanf("%s", name_1);
	int pos = search(con, name_1);
	if (pos < 0) {
		printf("(δ��ѯ��)");
		return;
	}
	for (int i = pos; i < con->sz - 1; i++) {
		con->date[i] = con->date[i + 1];
	}
	con->sz--;
	printf("ɾ���ɹ�\n");
}

//����
void searchcontact(contact* con) {
	char name_1[MAX_NAME];
	printf("����������:>");
	scanf("%s", name_1);
	int pos = search(con, name_1);
	if (pos < 0) {
		printf("δ���������Ϣ!\n");
		return;
	}

	
	printf("%-4s\t%-4s\t%-4s\t%-13s\t%-20s\n",
		"����", "����", "�Ա�", "�绰", "��ַ");
	print_1(con, &pos);

}

//��ӡ
void printcontact(contact* con1) {
	printf("%-4s\t%-4s\t%-4s\t%-13s\t%-20s\n", 
		"����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < con1->sz; i++) {
		print_1(con1, &i);
	}
}

//����
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
	printcontact(con);//������ӡһ��
}

//��������Ķ�̬�ڴ�
void deletecontact(contact* con) {
	free(con->date);
	con->date = (NULL);
	con->capacity = 0;
}