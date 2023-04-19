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

	//初始化棋盘数组
	Init_Board(board, ROW,COL);

	//显示棋盘模型
	Dispaly_Board(board, ROW, COL);

	while(1){//玩家下棋
		Player_Move(board, ROW, COL);
		Dispaly_Board(board, ROW, COL);

		ret = Is_Win(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		Computer_Move(board, ROW, COL);
		Dispaly_Board(board, ROW, COL);

		ret = Is_Win(board, ROW, COL);
		if (ret != 'C')
			break;

		//判断输赢
			//-玩家赢   *
			//-电脑赢   #
			//-平局     Q
			//-游戏继续 C
		
	}
	if (ret == '*') {
		printf("你赢了!\n");
	}
	else if (ret == '#') {
		printf("你输了!\n");
	}
	else {
		printf("平局!\n");
	}
	Dispaly_Board(board, ROW, COL);
}

int main(void) {
	int input = 0;

	srand((unsigned int)time(NULL));
	Menu();
	printf("请选择:");
	do {
		scanf("%d", &input);
		switch(input) {
			case 1: printf("<开始-游戏> \n\n");
					Game();
				break;
			case 0: printf("<退出游戏>\n");
				break;
			default: printf("\n选择错误,请重新选择:");
		}

	} while (input);
	return 0;
}