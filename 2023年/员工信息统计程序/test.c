#define  _CRT_SECURE_NO_WARNINGS

#include"information.h"
void num() {
	printf("************************************\n"); 
	printf("**         ��ҵԱ���������       **\n");
	printf("************************************\n");
	printf("***            1.¼��            ***\n");
	printf("***            2.ɾ��            ***\n");
	printf("***            3.�޸�            ***\n");
	printf("***            4.��ʾ            ***\n");
	printf("***            5.��ѯ            ***\n");
	printf("***            0.�˳�            ***\n");
	printf("************************************\n");
}

int main() {


	

	Information empl_er;//����Ա����Ϣ

	InitEmpl_er(&empl_er);//��ʼ��Ա����Ϣ

	fread_file(&empl_er);//�����ļ�

	int input;

	do{
		
		num();	//��Ŀ

		printf("\t��ѡ��:>");
		scanf("%d", &input);

		switch (input){

			case ADD://¼��
				Add_Information(&empl_er);
				break;

			case DELE://ɾ��
				Dele__Information(&empl_er);
				break;

			case MODIFY://�޸�
				Modify_Information(&empl_er);
				break;

			case DISPLAY://��ʾ
				Display_information(&empl_er);
				break;

			case SEARCH://��ѯ
				Search_information(&empl_er);
				break;

			case EXIT:
				Exit_system(&empl_er);
				break; 

			default:
				printf("\nѡ�����\n");
			
		}

	} while (input);

	return 0;
}