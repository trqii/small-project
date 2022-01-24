#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROW 3 // 定义棋盘行数
#define COL 3 // 定义棋盘列数

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

// 打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

// 判断胜负
char IsWin(char board[ROW][COL], int row, int col);

