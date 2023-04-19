#define  _CRT_SECURE_NO_WARNINGS
#include"information.h"

void InitEmpl_er(Information* empl_er) {//��ʼ���ṹ��
	empl_er->date = MALLOC(E_SZ ,Employee);//���붯̬�ڴ�
	if (empl_er->date==NULL){
		perror("InitEml_er");
		return;
	}
	empl_er->number = 0;
	empl_er->pa = E_PA;
}

void Full_pace(Information* empl_er) {//�жϿռ��ǹ��洢
	Employee* pta = NULL;
	if (empl_er->number == empl_er->pa) {
		pta = (Employee*)realloc(empl_er->date,(empl_er->number + empl_er->pa) * SIZEOF(Employee));
		if (pta != NULL){
			empl_er->date = pta;
			empl_er->pa += E_PA;
			printf("<<������>>");
		}
		else
		{
			perror("Fill_pace");
			return;
		}
	}

}

void print(Information* empl_er,int* i) {//��ʾ��֧
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

void Add_Information(Information* empl_er) {//¼��
	
	Full_pace(empl_er);//�жϿռ��ǹ��洢

	printf("<<¼����Ϣ>>\n");
	printf("������Ա�����:"); scanf("%s", empl_er->date[empl_er->number].emp_num);
	printf("������Ա������:"); scanf("%s", empl_er->date[empl_er->number].emp_name);
	printf("������Ա���Ա�:"); scanf("%s", empl_er->date[empl_er->number].emp_sex);
	printf("������Ա������:"); scanf("%d", &(empl_er->date[empl_er->number].emp_age));
	printf("������Ա������:"); scanf("%d", &(empl_er->date[empl_er->number].emp_sen));
	printf("������Ա��ְ��:"); scanf("%s", empl_er->date[empl_er->number].emp_pos);
	printf("������Ա������:"); scanf("%s", empl_er->date[empl_er->number].emp_depart);
	printf("������Ա��סַ:"); scanf("%s", empl_er->date[empl_er->number].emp_addr);
	empl_er->number++;
	system("cls");//����
}

void fread_file(Information* empl_er) {//�����ļ�
	FILE* pt = fopen("Information.txt", "r");//���ļ�ֻ��
	if (pt == NULL) {
		perror("fopen");
		return;
	}

	Employee ptr;//����һ���ṹ��洢��д��Ľṹ����Ϣ

	while (fread(&ptr, sizeof(Employee), 1, pt)) {//д��ṹ��洢
		Full_pace(empl_er);
		empl_er->date[empl_er->number] = ptr;
		empl_er->number++;
	}

	fclose(pt);//�ر��ļ�
	pt = NULL;
}

void num_1() {//����Ŀ
	system("cls");//����
	printf("************************************\n");
	printf("**         ��ҵԱ���������       **\n");
	printf("************************************\n");
	printf("***        1.����                ***\n");
	printf("***        2.����-�Ա�           ***\n");
	printf("***        3.���䷶Χ-�Ա�       ***\n");
	printf("***        4.����-����           ***\n");
	printf("***                              ***\n");
	printf("***        0.�˳�                ***\n");
	printf("************************************\n");

}


int Search_1(Information* empl_er, char* emp_n) {//���ҷ�֧
	for (int i = 0; i < empl_er->number; i++) {
		if (strcmp(empl_er->date[i].emp_num, emp_n) == 0) {
			return i;
		}
	}
	return -1;
}

void Dele__Information(Information* empl_er) {//ɾ��
	int i;
	char emp_n[E_NUM];
	printf("������ɾ��Ա����Ϣ�ı��:");
	scanf("%s", emp_n);
	i = Search_1(empl_er, emp_n);
	if (i >= 0)//�ҵ�
	{
		for (int j = i; j < empl_er->number - 1; j++) {
			empl_er->date[i] = empl_er->date[i + 1];
		}
		printf("\nɾ���ɹ�\n");
		empl_er->number--;
	}
	else//δ�ҵ�
	{
		printf("\nδ��ѯ����Ϣ\n");
	}
}

void Search_information(Information* empl_er) {//����
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

	num_1();//����Ŀ
	printf("������:");
	scanf("%d", &input);
	switch (input) {
	case 1://��������
		printf("������Ҫ��ѯ������:");//******************************
		scanf("%s", emp_n);
		for (int i = 0; i < empl_er->number; i++) {
			if (strcmp(empl_er->date->emp_name, emp_n) == 0) {
				j = i;
				break;
			}
		}
		//�ҵ� 
		if (j >= 0) {
			print(empl_er, &j);
		}

		//δ�ҵ�
		else {
			printf("δ��ѯ��\n");
			return;
		}
		break;

	case 2://���� �Ա�
		printf("������Ա������:"); scanf("%s", emp_pos);
		printf("������Ա���Ա�:"); scanf("%s", emp_sex);
		for (i = 0; i < empl_er->number; i++) {
			if ((strcmp(empl_er->date[i].emp_pos, emp_pos) == 0) && (strcmp(empl_er->date[i].emp_sex, emp_sex) == 0)) {
				print(empl_er, &i);
			}
		}
		break;
	case 3://�䷶Χ-�Ա�
		printf("������Ա�����䷶Χ(�ÿո�ֿ�;��:(0 10)):"); scanf("%d %d", &emp_age_1, &emp_age_2);
		printf("������Ա���Ա�:"); scanf("%s", emp_sex);
		for (i = 0; i < empl_er->number; i++){
			if ((strcmp(empl_er->date[i].emp_sex, emp_sex) == 0) && (empl_er->date[i].emp_age > emp_age_1) && (empl_er->date[i].emp_age < emp_age_2)) 
				print(empl_er, &i);
			
		}
			break;
		case 4://����-����
			printf("������Ա������:"); scanf("%d", &emp_sen);
			printf("������Ա������:"); scanf("%s", emp_depart);
			for (i = 0; i < empl_er->number; i++) {
				if ((strcmp(empl_er->date[i].emp_depart, emp_depart) == 0) && (empl_er->date[i].emp_sen = emp_sen))
					print(empl_er, &i);
			}
			break;
		case 0:
			break;
	
		default:
		printf("\nѡ�����\n");
	}
}

void Modify_Information(Information* empl_er) {//�޸�
	char emp_num[E_NUM];
	printf("\n�������޸�Ա���ı��:");
	scanf("%s", emp_num);
	int i = Search_1(empl_er, emp_num);
	if (i < 0) {
		printf("\n��Ҫ�޸ĵ�Ա����Ϣ������!�������Ϣ!\n");
	}
	else {
		printf("������Ա�����:"); scanf("%s", empl_er->date[empl_er->number].emp_num);
		printf("������Ա������:"); scanf("%s", empl_er->date[empl_er->number].emp_name);
		printf("������Ա���Ա�:"); scanf("%s", empl_er->date[empl_er->number].emp_sex);
		printf("������Ա������:"); scanf("%d", &(empl_er->date[empl_er->number].emp_age));
		printf("������Ա������:"); scanf("%d", &(empl_er->date[empl_er->number].emp_sen));
		printf("������Ա��ְ��:"); scanf("%s", empl_er->date[empl_er->number].emp_pos);
		printf("������Ա������:"); scanf("%s", empl_er->date[empl_er->number].emp_depart);
		printf("������Ա��סַ:"); scanf("%s", empl_er->date[empl_er->number].emp_addr);

	}
}

void Display_information(Information* empl_er) {//��ʾ
	int i;
	system("cls");//����
	printf("<<��ʾȫ��Ա����Ϣ>>\n");
	printf("%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n", "���", "����", "�Ա�", "����", "����", "ְ��", "����", "��ͥ");
	for (i = 0; i < empl_er->number; i++) {
		print(empl_er, &i);
	}
	printf("\n");
}

void Exit_system(Information* empl_er) {//�˳�ϵͳ

	FILE* pt = fopen("Information.txt", "w");//���ļ�
	if (pt == NULL) {
		perror("Exit_system");
		return;
	}

	for (int i = 0; i < empl_er->number; i++) {
		fwrite(empl_er->date + i, sizeof(Employee), 1, pt);
	}

	fclose(pt);//�ر��ļ�
	pt = NULL;
	
	free(empl_er->date);
	empl_er->number = 0;
	empl_er->pa = 0;
	printf("\n�˳��ɹ�\n");
}
