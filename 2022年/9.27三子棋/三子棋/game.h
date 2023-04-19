#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3   //ÁÐ
#define COL 3   //ÐÐ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Init_Board(char board[ROW][COL], int row, int col);

void Dispaly_Board(char board[ROW][COL], int row, int col);

void Player_Move(char board[ROW][COL], int row, int col);

void Computer_Move(char board[ROW][COL], int row, int col);

char Is_Win(char board[ROW][COL], int row, int col);