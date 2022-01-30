#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// 定义棋盘大小
#define ROW 9
#define COL 9

// 扩展棋盘大小，防止越界
#define ROWS ROW + 2
#define COLS COL + 2

// 定义难度
#define EASY_COUNT 10

// 初始化数组
void InitBoard(char board[ROWS][COLS], int row, int col, char set);

// 打印数组
void PrintBoard(char board[ROWS][COLS], int row, int col);

// 设置雷
void SetMine(char board[ROWS][COLS], int row, int col);

// 排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);