#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MALLOC(X,BUFF) ((BUFF*)malloc(X*sizeof(BUFF))) //���ݺ�

#define STU_M 20
#define TEN_M 15
#define	ADDR_M 30
#define WE_M 15
#define STU_S_M 3



#define SZ_MAX 5
#define CAP_MAX 4

typedef struct Student {
	char stu_num[STU_M];		//ѧ��
	char stu_name[TEN_M];		//����
	char stu_sex[STU_S_M];		//�Ա�
	char stu_spe[TEN_M];		//רҵ
	char stu_class[TEN_M];		//�༶
	char stu_dorm_num[TEN_M];	//�����
	char stu_addr[ADDR_M];		//����
	char tele[WE_M];			//�ֻ���
	char qq[TEN_M];			//QQ��
	char wechat[WE_M];		//΢�ź�
	char emil[ADDR_M];
}Student;

typedef struct Inform_a {
	Student* dete;
	int num;
	int cap;
}Inform_a;

enum {
	EXIT,	//�˳�	
	ADD,	//���
	QUERY,	//��ѯ
	DELE,	//ɾ��
	MODIFY,	//�޸�
	OUTPUT,	//���
	SORT	//����
};

void initialization(Inform_a* inform);//��ʼ��

void IF_Information(Inform_a* inform);//�ж�����Ķ����ڴ��Ƿ���->����

void File_R_initialization(Inform_a* inform);//�����ļ�

void Add_Information(Inform_a* inform);//�����ϵ��

int IF_Query(Inform_a* inform, char* stu_num);//��ѯ��֧

void Query_Information(Inform_a* inform);//��ѯ

void Dele_Information(Inform_a* inform);//ɾ��

void Modify_Information(Inform_a* inform);//�޸�

void Output_Information(Inform_a* inform);//�����ϵ��

void Sort_Information(Inform_a* inform);//����

void Exit_Information(Inform_a* inform);//�˳�