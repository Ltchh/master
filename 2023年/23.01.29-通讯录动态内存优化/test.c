#define  _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void num() {
	printf("*********************\n");
	printf("***     1.add     ***\n");
	printf("***     2.modify  ***\n");
	printf("***     3.dele    ***\n");
	printf("***     4.search  ***\n");
	printf("***     5.sort    ***\n");
	printf("***     6.print   ***\n");
	printf("***     0.exit    ***\n");
	printf("*********************\n\n");

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

	initcontact(&con);

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
			//��������Ķ�̬�ڴ�

			deletecontact(&con);

			printf("�˳�����");
			break;
		default:
			printf("ѡ�����!\n");
		}
		printf("\n�ɴ洢:%d\n�Ѵ洢:%d\n\n", MAX - con.sz, con.sz);
	} while (input);

	return 0;
}
