#define  _CRT_SECURE_NO_WARNINGS

#include"information.h"
void menu() {
	printf("\n");
	printf("***************************\n");
	printf("* ͨ  *********************\n");
	printf("*     **   1.�����ϵ��  **\n");
	printf("* Ѷ  **   2.��ѯ��ϵ��  **\n");
	printf("*     **   3.ɾ����ϵ��  **\n");
	printf("* ¼  **   4.�޸���ϵ��  **\n");
	printf("*  |  **   5.�����ϵ��  **\n");
	printf("*  |  **   6.ѧ��  ����  **\n");
	printf("* ��  **   0.�˳�  ����  **\n");
	printf("* ��  *********************\n");
	printf("***************************\n\n");

}

int main() {
	int input;

	

	Inform_a inform;//����һ��ָ��ṹ���ָ��
	
	initialization(&inform);//��ʼ��

	File_R_initialization(&inform);//�����ļ�

	do {

		menu();//�˵�

		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input){

			case ADD:	//���
				Add_Information(&inform);

				break;

			case QUERY:	//��ѯ
				Query_Information(&inform);
				break;

			case DELE:	//ɾ��
				Dele_Information(&inform);
				break;

			case MODIFY://�޸�
				Modify_Information(&inform);
				break;

			case OUTPUT://���
				Output_Information(&inform);
				break;

			case SORT:	//����
				Sort_Information(&inform);
				break;

			case EXIT:	//�˳�
				Exit_Information(&inform);
				break;
		default:
			printf("\n�������.\n");
		}

	} while (input);

	return;
}