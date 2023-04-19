#pragma once
#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

int i = 0;
int j = 0;

void Init_Board(char board[ROW][COL], int row, int col) {
	
	for (i = 0; i < row; i++) {         //列
		for (int j = 0; j < col; j++) { //行
			board[i][j] = ' ';
		}
	}
}

void Dispaly_Board(char board[ROW][COL], int row, int col) {
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
				
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
}

void Player_Move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("\n玩家走=>\n");
	while (1) {
		printf("请输入坐标:");
		scanf("%d %d", &x, &y);
		if(x>=1&&x<=ROW&&y<=1&&y>=COL){
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用!\n");
			}
		}
		else {
			printf("坐标非法");
		}
	}
}

void Computer_Move(char board[ROW][COL], int row, int col) {
	int x = rand() % row;
	int y = rand() % col;

	printf("电脑走=>\n");
	while (1)
	{
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

int Is_Full(char board[ROW][COL], int row, int col) {
	for (i = 0; i< row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
			
		}
	}
	return 1;
}

char Is_Win(char board[ROW][COL], int row, int col) {
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}

	for (j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			return board[1][j];
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}

	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}


	//棋盘满了返回1; 不满返回0;
	int ret = Is_Full(board, row, col);
	if (ret == 1)
		return 'Q';
	return 'C';
}