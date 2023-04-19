#include "game.h"

void Menu() {
	printf("**************************\n");
	printf("****      1.Play      ****\n");
	printf("****      0.Exit      ****\n");
	printf("**************************\n");
}

void Game() {
	char board[ROW][COL];

	char ret={'0'};

	//��ʼ����������
	Init_Board(board, ROW,COL);

	//��ʾ����ģ��
	Dispaly_Board(board, ROW, COL);

	while(1){//�������
		Player_Move(board, ROW, COL);
		Dispaly_Board(board, ROW, COL);

		ret = Is_Win(board, ROW, COL);
		if (ret != 'C')
			break;

		//��������
		Computer_Move(board, ROW, COL);
		Dispaly_Board(board, ROW, COL);

		ret = Is_Win(board, ROW, COL);
		if (ret != 'C')
			break;

		//�ж���Ӯ
			//-���Ӯ   *
			//-����Ӯ   #
			//-ƽ��     Q
			//-��Ϸ���� C
		
	}
	if (ret == '*') {
		printf("��Ӯ��!\n");
	}
	else if (ret == '#') {
		printf("������!\n");
	}
	else {
		printf("ƽ��!\n");
	}
	Dispaly_Board(board, ROW, COL);
}

int main(void) {
	int input = 0;

	srand((unsigned int)time(NULL));
	Menu();
	printf("��ѡ��:");
	do {
		scanf("%d", &input);
		switch(input) {
			case 1: printf("<��ʼ-��Ϸ> \n\n");
					Game();
				break;
			case 0: printf("<�˳���Ϸ>\n");
				break;
			default: printf("\nѡ�����,������ѡ��:");
		}

	} while (input);
	return 0;
}