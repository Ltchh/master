#define  _CRT_SECURE_NO_WARNINGS

#include"information.h"

void initialization(Inform_a* inform) {//��ʼ��
	inform->dete = MALLOC(SZ_MAX, Student);
	if (inform->dete == NULL)
		perror("initalization");
	inform->num = 0;
	inform->cap = CAP_MAX;
}

void print(Inform_a* inform, int i) {//��ӡ��֧
	printf("��:(%d)\n ѧ  ��:%-15s\n ��  ��:%-5s\n ��  ��:%-4s\n ר  ҵ:%-4s\n ��  ��:%-4s\n �����:%-4s\n "
			"��  ��:%-30s\n ��  ��:%-12s\n QQ  :%-12s\n ΢  ��:%-12s\n Emil  :%-12s\n------------------------------\n",
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

int IF_Query(Inform_a* inform, char* stu_num) {//��ѯ��֧
	for (int i = 0; i < inform->num; i++) {
		if (strcmp(inform->dete[i].stu_num, stu_num) == 0)
			return i;
	}
	return -1;
}

void IF_Information(Inform_a* inform) {//�ж�����Ķ����ڴ��Ƿ���->����
	Student* pta;
	if (inform->cap == inform->num) {
		pta =(Student*)realloc(inform->dete,(inform->num + SZ_MAX)*sizeof(Student));
		if (pta != NULL) {
			inform->dete = pta;
			inform->cap += SZ_MAX;
			printf("\n<<������>>\n");
		}
		else{
			perror("IF_Information");
			return;
		}	
	}	
}

void File_R_initialization(Inform_a* inform) {//�����ļ�
	FILE* tmp = fopen("initialization.txt", "r");//���ļ� ֻ��
	if (tmp == NULL) {
		perror("File_R_initialization");
		return;
	}

	Student tmp_1;
	while (fread(&tmp_1, sizeof(Student), 1, tmp)) {//�����ƶ�ȡ�ļ�
		IF_Information(inform);
		inform->dete[inform->num] = tmp_1;
		inform->num++;
	}	

	fclose(tmp);	//�ر��ļ�
	tmp == NULL;
}

void Add_Information(Inform_a* inform) {//�����ϵ��
	
	IF_Information(inform);//�ж�����Ķ����ڴ��Ƿ���->����
	
	//¼����ϵ��
	printf("������  ѧ��:"); scanf("%s", inform->dete[inform->num].stu_num);
	printf("������  ����:"); scanf("%s", inform->dete[inform->num].stu_name);
	printf("������  �Ա�:"); scanf("%s", inform->dete[inform->num].stu_sex);
	printf("������  רҵ:"); scanf("%s", inform->dete[inform->num].stu_spe);
	printf("������  �༶:"); scanf("%s", inform->dete[inform->num].stu_class);
	printf("�����������:"); scanf("%s", inform->dete[inform->num].stu_dorm_num);
	printf("������  ����:"); scanf("%s", inform->dete[inform->num].stu_addr);
	printf("�������ֻ���:"); scanf("%s", inform->dete[inform->num].tele);
	printf("������  QQ��:"); scanf("%s", inform->dete[inform->num].qq);
	printf("������΢�ź�:"); scanf("%s", inform->dete[inform->num].wechat);
	printf("������  emil:"); scanf("%s", inform->dete[inform->num].emil);
	inform->num++;
	
	system("pause");//��ͣ
	system("cls");//����
}

void Query_Information(Inform_a* inform) {//��ѯ
	if (inform->num > 0) {
		char stu_num[STU_M];
		printf("������ѧ��:");
		scanf("%s", stu_num);

		int i = IF_Query(inform, stu_num);//��ѯ��֧
	
		if (i >= 0) {//�ҵ�
			print(inform, i);
		}

		else{//δ�ҵ�
			printf("(δ���)\n");

		}
		system("pause");//��ͣ
		system("cls");//����
	}

	else {
		printf("\n(��ͨѶ¼)\n");
		system("pause");//��ͣ
		system("cls");//����
	}
}

void Dele_Information(Inform_a* inform) {//ɾ��
	if (inform->num > 0) {
		char stu_num[STU_M];
		printf("������ѧ��:");
		scanf("%s", stu_num);

		int i = IF_Query(inform, stu_num);//��ѯ��֧

		if (i >= 0) {//�ҵ�
			for (int num = i; num < inform->num; num++) {
				inform->dete[num] = inform->dete[num + 1];
				inform->num--;
			}
			printf("(ɾ���ɹ�)");
		}

		else {//δ�ҵ�
			printf("(δ���)\n");
		}
		system("pause");//��ͣ
		system("cls");//����
	}

	else {
		printf("\n(��ͨѶ¼)\n");
		system("pause");//��ͣ
		system("cls");//����
	}
}

void Modify_Information(Inform_a* inform){//�޸�
	if (inform->num > 0) {
		char stu_num[STU_M];
		printf("������ѧ��:");
		scanf("%s", stu_num);

		int i = IF_Query(inform, stu_num);//��ѯ��֧

		if (i >= 0) {//�ҵ�
			printf("�޸�->\n");
			printf("������  ѧ��:"); scanf("%s", inform->dete[i].stu_num);
			printf("������  ����:"); scanf("%s", inform->dete[i].stu_name);
			printf("������  �Ա�:"); scanf("%s", inform->dete[i].stu_sex);
			printf("������  רҵ:"); scanf("%s", inform->dete[i].stu_spe);
			printf("������  �༶:"); scanf("%s", inform->dete[i].stu_class);
			printf("�����������:"); scanf("%s", inform->dete[i].stu_dorm_num);
			printf("������  ����:"); scanf("%s", inform->dete[i].stu_addr);
			printf("�������ֻ���:"); scanf("%s", inform->dete[i].tele);
			printf("������  QQ��:"); scanf("%s", inform->dete[i].qq);
			printf("������΢�ź�:"); scanf("%s", inform->dete[i].wechat);
			printf("������  emil:"); scanf("%s", inform->dete[i].emil);
			printf("(�޸ĳɹ�)");
		}

		else {//δ�ҵ�
			printf("(δ���)\n");
		}
		system("pause");//��ͣ
		system("cls");//����
	}

	else {
		printf("\n(��ͨѶ¼)\n");
		system("pause");//��ͣ
		system("cls");//����
	}
}


void Output_Information(Inform_a* inform) {//���
	if (inform->num > 0) {
		if (inform->num != 0) {
			for (int i = 0; i < inform->num; i++) {

				print(inform, i);//��ӡ��֧
			}
			system("pause");//��ͣ
			system("cls");//����
		}
		else {
			printf("\n<<δ�����ϵ��>>\n");
			system("pause");//��ͣ
			system("cls");//����
			return;
		}
		system("pause");//��ͣ
		system("cls");//����
	}
	else {
		printf("\n(��ͨѶ¼)\n");
		system("pause");//��ͣ
		system("cls");//����
	}
	
}

void Sort_Information(Inform_a* inform) {//����
	if (inform->num > 0) {
		printf("[��ѧ������]");
		for (int i = 0; i < inform->num; i++) {
			for (int j = 0; j < inform->num - i-1; j++) {
				if (strcmp(inform->dete[j].stu_name, inform->dete[j + 1].stu_num) > 0) {
				Student tmp = inform->dete[j];
				inform->dete[j] = inform->dete[j + 1];
				inform->dete[j + 1] = tmp;
				}
			}		
		}
			printf("\n(����ɹ�)\n");

	}

	else {
		printf("\n(��ͨѶ¼)\n");
		system("pause");//��ͣ
		system("cls");//����
	}
}

void Exit_Information(Inform_a* inform) {//�˳�

	FILE* tmp = fopen("initialization.txt", "w");//���ļ� д��
	if (tmp == NULL) {
		perror("Exit_Information_fopen");
		return;
	}
	for (int i = 0; i <inform->num; i++)
	{
		fwrite(inform->dete+i, sizeof(Student), 1, tmp);
	}	//д���ļ�

		
		
	fclose(tmp);//�ر��ļ�
	tmp = NULL;

	free(inform->dete);
	inform->dete = NULL;
	inform->num = 0;
	inform->cap = 0;
}
