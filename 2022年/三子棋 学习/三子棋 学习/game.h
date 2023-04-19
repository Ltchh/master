#pragma once

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Init_board(char board[ROW][COL], int row, int col);

void Dispaly_board(char board[ROW][COL], int row, int col);

void Player_move(char boar[ROW][COL], int row, int col);

void Computer_move(char board[ROW][COL], int row, int col);

char Is_win(char board[ROW][COL], int row, int col);
