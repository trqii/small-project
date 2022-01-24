#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}

void game()
{
	// 用于存储棋盘信息
	char board[ROW][COL] = { 0 };

	// 用于存储棋局状态
	char ret = 0;

	// 初始化棋盘
	InitBoard(board, ROW, COL);

	// 打印棋盘
	PrintBoard(board, ROW, COL);

	while (1)
	{
		// 玩家下棋
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		// 电脑下棋
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}

	// 判断最终结果
	if ('*' == ret)
		printf("玩家赢\n");
	else if ('#' == ret)
		printf("电脑赢\n");
	else
		printf("平局\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重输\n");
			break;
		}
	} while (input);

	return 0;
}