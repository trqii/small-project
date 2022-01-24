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
	// ���ڴ洢������Ϣ
	char board[ROW][COL] = { 0 };

	// ���ڴ洢���״̬
	char ret = 0;

	// ��ʼ������
	InitBoard(board, ROW, COL);

	// ��ӡ����
	PrintBoard(board, ROW, COL);

	while (1)
	{
		// �������
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		// ��������
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}

	// �ж����ս��
	if ('*' == ret)
		printf("���Ӯ\n");
	else if ('#' == ret)
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������\n");
			break;
		}
	} while (input);

	return 0;
}