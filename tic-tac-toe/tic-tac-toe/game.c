#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' '; // 全部初始化为空
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}		
	}
}

//    |   |   
// ---|---|---
//    |   |   
// ---|---|---
//    |   |

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家下棋:>\n");
	while (1)
	{
		printf("请输入您要下的地方: ");
		scanf("%d %d", &x, &y);

		// 以正常人的思维坐标应该从1开始，而不是0
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// 判断该坐标是否已落子
			if (' ' == board[x - 1][y - 1])
			{
				system("cls");
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已落子，请重输\n");
			}
		}
		else
		{
			printf("输入坐标不合法，请重输\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	Sleep(1000);
	system("cls");
	while (1)
	{
		// 电脑随机生成坐标
		int x = rand() % row;
		int y = rand() % col;		
		
		// 判断是否已落子
		if (' ' == board[x][y])
		{
			board[x][y] = '#';
			break;
		}		
	}	
}

// 返回0，表示棋盘未满
// 返回1，表示棋盘已满
static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (' ' == board[i][j])
				return 0;
		}
	}
	return 1;
}

// 玩家赢，返回 '*'
// 电脑赢，返回 '#'
// 平局，  返回 'Q'
// 继续，  返回 'C'
// 仅用于 3 * 3 棋盘
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	// 判断行相等
	for (i = 0; i < col; i++)
	{
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[1][i];
	}

	// 判断列相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][1];
	}

	// 判断交叉线相等
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[1][1];
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];

	// 判断平局
	if (1 == IsFull(board, row, col))
		return 'Q';

	// 游戏继续
	return 'C';
}

// //用于 多 * 多棋盘判定
//char IsWin(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	// 判断行相等
//	for (i = 0; i < row; i++)
//	{		
//		for (j = 0; j < col; j++)
//		{
//			if (' ' == board[i][0] || board[i][0] != board[i][j])			
//				break;							
//		}
//		if (col == j)
//			return board[i][0];
//	}
//
//	// 判断列相等
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (' ' == board[0][i] || board[0][i] != board[j][i])
//				break;
//		}
//		if (col == j)
//			return board[0][i];
//	}
//
//	// 判断主对角线相等
//	for (i = 1; i < col; i++)
//	{
//		if (' ' == board[0][0] || board[0][0] != board[i][i])
//			break;
//	}
//	if (col == i)
//		return board[0][0];
//
//	// 判断副对角线相等
//	for (i = 1; i < col; i++)
//	{
//		if (' ' == board[0][col - 1] || board[0][col - 1] != board[i][col - i - 1])
//			break;
//	}
//	if (col == i)
//		return board[0][col - 1];
//
//	// 判断平局
//	if (1 == IsFull(board, row, col))
//		return 'Q';
//
//	// 游戏继续
//	return 'C';
//}

