#include "game.h"

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = set; // 初始为指定的格式
		}
	}
}

// 打印棋盘
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	// 打印列标
	for (i = 0; i <= row; i++)
	{
		printf(" %-3d", i);
	}
	printf("\n\n");

	// 打印每一行
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%2d", i); // 打印行标
		for (j = 1; j <= col; j++)
		{
			printf("%4c", board[i][j]);
		}
		printf("\n\n");
	}
}

// 设置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;	
	while (count)
	{
		int x = rand() % row + 1; // 1 ~ 9
		int y = rand() % col + 1; // 1 ~ 9
		if ('0' == board[x][y])
		{
			board[x][y] = '1';
			count--;
		}
	}
}

// 获取九宫格内雷的数量
static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	int i = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			count += mine[i][j];
		}
	}
	return count - 9 * '0';
}

// 判断第一次是否踩雷
static void IsFirstStepMine(char mine[ROWS][COLS], int x, int y)
{
	while ('1' == mine[x][y])
	{
		int m = rand() % ROW + 1;
		int n = rand() % COL + 1;
		if ('0' == mine[m][n])
		{
			mine[m][n] = '1';
			mine[x][y] = '0';
		}
	}  
}

// 利用递归实现一下展开一片
static void CleanMore(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{	
	int i = 0;
	show[x][y] = ' '; // 为了美观将 '0' 全部用 ' ' 代替
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			if (i < 1 || i > ROW || j < 1 || j > COL) // 不合法坐标
				continue;
			if ('*' == show[i][j]) // 对未展开的进行展开，已展开跳过
			{
				show[i][j] = '0' + GetMineCount(mine, i, j);
				if ('0' == show[i][j])
					CleanMore(mine, show, i, j);
			}			
		}
	}	
}

// 判断是否赢
static int IsWin(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	int i = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0; 
		for (j = 1; j <= col; j++)
		{
			if ('*' == show[i][j] || '?' == show[i][j]) // 统计被标记及未被排查雷个数
				count++;								// 等于总的雷数，获胜
		}
	}
	return count == EASY_COUNT;
}

// 标记雷
static SignMine(char show[ROWS][COLS], int x, int y)
{
	if ('*' == show[x][y])
		show[x][y] = '?';
	else if ('?' == show[x][y])
		show[x][y] = '*';
	system("cls");
	PrintBoard(show, ROW, COL);
}

// 排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int flag = 0;  // 用于判断是否标记
	int first = 1; // 用于保证第一次不是雷，且仅执行一次
	while (IsWin(show, ROW, COL) != 1)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d %d", &x, &y, &flag);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (1 == flag)
			{
				SignMine(show, x, y);
				continue;
			}
			 // 判断第一次是否踩雷
			if (1 == first)
			{
				IsFirstStepMine(mine, x, y);
				first = 0;
			}

			if ('1' == mine[x][y])
			{
				printf("很遗憾，你被雷炸死了！\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else
			{	
				system("cls"); // 清屏
				show[x][y] = '0' + GetMineCount(mine, x, y);
				// 展开一片
				if ('0' == show[x][y])
					CleanMore(mine, show, x, y);
				PrintBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("输入坐标不合法，请重输！\n");
		}
	}
	if (IsWin(show, ROW, COL) == 1)
		printf("恭喜，你赢了！\n");
}

