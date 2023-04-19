#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu() {
	printf("************************\n");
	printf("****    <1> Play    ****\n");
	printf("****    <0> Exit    ****\n");
	printf("************************\n");
}

void game() {
	char board[ROW][COL];

	char ret = { '0' };
	
	Init_board(board, ROW, COL);

	Dispaly_board(board, ROW, COL);

	while (1)
	{
		Player_move(board, ROW, COL);
		Dispaly_board(board, ROW, COL);

		ret = Is_win(board, ROW, COL);
		if (ret != 'C')
			break;

		Computer_move(board, ROW, COL);
		Dispaly_board(board, ROW, COL);
		ret = Is_win(board, ROW, COL);
		if (ret != 'C')
			break;

	}
	if (ret == '*')
		printf("\n��Ӯ��!!!\n");
	else if (ret == '#')
		printf("\n������!!!\n");
	else
		printf("\nƽ��\n");
	Dispaly_board(board, ROW, COL);

}	

int main() {
	int input = 0;

	srand ((unsigned int)time(NULL));

	menu();
	printf("��ѡ��(1/0):");
	
	do {
		scanf("%d", &input);
		switch (input)
		{
		case 1: game();
			break;
		case 0:printf("<�˳���Ϸ\n>");
			break;
		default:
			printf("\n�������!���ٴ�����:");
		}

	} while (input);


	return 0;
}