#pragma once
#include"contact.h"

void initcontact(contact* con) {//��ʼ���ṹ��
	con->date = (peoinfo*)(malloc(MAX_SZ * (sizeof(peoinfo))));
	if (con->date == NULL) {
		perror("initcontact_malloc");
		return;
	}
	con->num = 0;
	con->capacity = MAX_CAPA;
}


void ifcontact_y_n(contact* con) {//ȷ���Ƿ���Ҫ��������Ķ���
	if (con->num == con->capacity) {
		peoinfo* ptr=realloc(con->date, (con->capacity + MAX_SZ) * sizeof(peoinfo));
		if (ptr != NULL) {
			con->date = ptr;
			con->capacity += MAX_SZ;
			printf("\n�Ѿ������ڴ�ɹ�!~\n\n");
		}
		else{
			perror("realloc");
			return;
		}
	}	
}

void fread_file(contact * con){//�����ļ�
	FILE* ptr = fopen("contact.txt", "r");//���ļ�ֻ��
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

	fclose(ptr);//�ر��ļ�
	ptr = NULL;
}

void print_1(contact* con, int i) {//��ӡ��֧
	printf("%-4s\t", con->date[i].name);
	printf("%-4d\t", con->date[i].age);
	printf("%-4s\t", con->date[i].sex);
	printf("%-13s\t", con->date[i].tele);
	printf("%-50s\n", con->date[i].addr);
}

int search_1(contact* con) {//���ҷ�֧
	int n;
	char name_1[MAX_NAME];
	scanf("%s", name_1);

	for (n = 0; n < con->num; n++) {
		if ((strcmp(con->date[n].name, name_1)) == 0)
			return n;
	}
	return -1;
}



void addcontact(contact* con) {//�����ϵ��
	printf("����������:");scanf("%s", con->date[con->num].name);
	printf("����������:");scanf("%d", &(con->date[con->num].age));
	printf("�������Ա�:");scanf("%s", con->date[con->num].sex);
	printf("������绰:");scanf("%s", con->date[con->num].tele);
	printf("�������ַ:");scanf("%s", con->date[con->num].addr);
	con->num++;
	printf("\n��ӳɹ�\n");
}

void modifycontact(contact* con) {//�޸���ϵ��
	printf("�������޸ĵ���ϵ�˵�����:");
	
	int i=search_1(con);

	if (i < 0)
		printf("��Ҫ�޸ĵ��˵���Ϣ������\n");
	else {
		printf("����������:"); scanf("%s", con->date[i].name);
		printf("����������:"); scanf("%d", &(con->date[i].age));
		printf("�������Ա�:"); scanf("%s", con->date[i].sex);
		printf("������绰:"); scanf("%s", con->date[i].tele);
		printf("�������ַ:"); scanf("%s", con->date[i].addr);
		printf("\n�޸ĳɹ�\n");
	}
}

void delecontact(contact* con) {//ɾ����ϵ��

	if (con->num != 0) {
		printf("��������Ҫɾ���˵�����:");
		int i = search_1(con);
		if (i < 0)
			printf("��Ҫɾ�������˵���Ϣ������!�������ϵ��!");
		else
		{
			for (int n = i; n < con->num-1; n++) {
				con->date[i] = con->date[i + 1];
			}
			printf("\nɾ���ɹ�\n");
			con->num--;
		}
	}
	else
		printf("\n�洢�ռ�δ�����Ա��Ϣ!�����!\n");
	
}

void searchcontact(contact * con){//������ϵ��

	printf("��������Ҫ��ѯ������:");
	int i = search_1(con);
	
	//δ�ҵ�
	if (i < 0) {
		printf("��Ҫ��ѯ����Ϣ������!�������Ϣ!~\n");
	}
	//�ҵ�
	else
	{
		printf("%-4s\t%-4s\t%-4s\t%-13s\t%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		print_1(con, i);
	}
}

void sortcontact(contact* con) {//������ϵ��
	
	for (int i = 0; i < con->num; i++) {
		for (int j = 0; j < con->num - 1 - i; j++) {
			if (strcmp(con->date[j].name, con->date[j + 1].name)> 0) {
				peoinfo ptr=con->date[j];
				con->date[j] = con->date[j + 1];
				con->date[j + 1] = ptr;
			}
		}	
	}
	
	printf("\n����ɹ�\n");
}

void printcontact(contact* con) {//��ӡ��ϵ��

	printf("%-4s\t%-4s\t%-4s\t%-13s\t%-15s\n", "����", "����", "�Ա�", "�绰", "��ַ");

	for (int i = 0; i < con->num; i++) {
		print_1(con, i);//��ӡ��֧
	}
	printf("\n��ӡ���\n");
}

void exit_save_file(contact* con) {//�˳������ļ�
	FILE* ptr = fopen("contact.txt", "w");//���ļ�
	if (ptr == NULL) {
		perror("fopen");
		return;
	}
	
	for (int i = 0; i < con->num; i++) {
		fwrite(con->date + i, sizeof(peoinfo), 1, ptr);
		//����:con->dete+i=>Ŀ�����ʼλ��
		//	  :sizeof(peoinfo)=>Ŀ�����͵Ĵ�С�ռ�
		//	  :1=>���һ��peoinfo��С������
		//	  :���λ�õı���	
	}

	fclose(ptr);//�ر��ļ�
	ptr = NULL;

}


void exitcontact(contact* con) {//�˳�����

	free(con->date);
	con->date= NULL;
	con->num = 0;
	con->capacity = 0;
}