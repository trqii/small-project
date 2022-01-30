#include "game.h"

void menu()
{
	printf("************************\n");
	printf("******** 1.play ********\n");
	printf("******** 0.exit ********\n");
	printf("************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 }; // 用于存储雷的位置
	char show[ROWS][COLS] = { 0 }; // 用于显示给用户

	// 初始化数组
	InitBoard(mine, ROWS, COLS, '0'); 
	InitBoard(show, ROWS, COLS, '*');	

	// 设置地雷
	SetMine(mine, ROW, COL);

	//PrintBoard(mine, ROW, COL); // 如果需要答案将这一行注释去掉
	PrintBoard(show, ROW, COL);

	// 排雷
	FindMine(mine, show, ROW, COL);
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  // 设置随机数种子
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

