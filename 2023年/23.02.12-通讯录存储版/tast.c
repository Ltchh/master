#pragma once
#include"contact.h"

#include"contact.h"

void num() {
	printf("\n***** < ���� > ****\n");
	printf("***** 1.ADD    ****\n");
	printf("***** 2.MODIFY ****\n");
	printf("***** 3.DELE   ****\n");
	printf("***** 4.SEARCH ****\n");
	printf("***** 5.SORT   ****\n");
	printf("***** 6.PRINT  ****\n");
	printf("***** 0.EXIT   ****\n");
	printf("*******************\n");

}

//ö������
enum {
	EXIT,	//�˳�
	ADD,	//���
	MODIFY,	//�޸�
	DELE,	//ɾ��
	SEARCH,	//����
	SORT,	//����
	PRINT,	//��ӡ
};

//�汾2
//��̬�汾
//1.ͨѶ¼��ʼ�����ܴ��3���˵���Ϣ
//2.�����Ǵ�ŵĿռ䲻����ʱ�� �Զ����4����Ϣ�ռ�


int main() {

	int input;

	contact con;

	initcontact(&con);//�ṹ���ʼ��

	ifcontact_y_n(&con);//��ʼ���ڶ���������̬�ڴ�

	fread_file(&con);//�����ļ�

	do
	{
		num();//�˵�

		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD://ͨѶ¼���

			addcontact(&con);
			break;
		case MODIFY://ͨѶ¼�޸�

		modifycontact(&con);
			break;
		case DELE://ͨѶ¼ɾ�� 

			delecontact(&con);
			break;
		case SEARCH://ͨѶ¼����

			searchcontact(&con);
			break;
		case SORT://ͨѶ¼����

			sortcontact(&con);
			break;
		case PRINT://ͨѶ¼��ӡ

			printcontact(&con);
			break;
		case EXIT: //ͨѶ¼�˳�

			exit_save_file(&con);//�˳������ļ�

			exitcontact(&con);//��������Ķ�̬�ڴ�

			printf("�˳�����");
			break;
		default:
			printf("ѡ�����!\n");
		}
		printf("\n�Ѵ洢:%d\n\n", con.num);
	} while (input);

	return 0;
}

