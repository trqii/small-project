#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' '; // ȫ����ʼ��Ϊ��
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

	printf("�������:>\n");
	while (1)
	{
		printf("��������Ҫ�µĵط�: ");
		scanf("%d %d", &x, &y);

		// �������˵�˼ά����Ӧ�ô�1��ʼ��������0
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// �жϸ������Ƿ�������
			if (' ' == board[x - 1][y - 1])
			{
				system("cls");
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����������ӣ�������\n");
			}
		}
		else
		{
			printf("�������겻�Ϸ���������\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������:>\n");
	Sleep(1000);
	system("cls");
	while (1)
	{
		// ���������������
		int x = rand() % row;
		int y = rand() % col;		
		
		// �ж��Ƿ�������
		if (' ' == board[x][y])
		{
			board[x][y] = '#';
			break;
		}		
	}	
}

// ����0����ʾ����δ��
// ����1����ʾ��������
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

// ���Ӯ������ '*'
// ����Ӯ������ '#'
// ƽ�֣�  ���� 'Q'
// ������  ���� 'C'
// ������ 3 * 3 ����
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	// �ж������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[1][i];
	}

	// �ж������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][1];
	}

	// �жϽ��������
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[1][1];
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];

	// �ж�ƽ��
	if (1 == IsFull(board, row, col))
		return 'Q';

	// ��Ϸ����
	return 'C';
}

// //���� �� * �������ж�
//char IsWin(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	// �ж������
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
//	// �ж������
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
//	// �ж����Խ������
//	for (i = 1; i < col; i++)
//	{
//		if (' ' == board[0][0] || board[0][0] != board[i][i])
//			break;
//	}
//	if (col == i)
//		return board[0][0];
//
//	// �жϸ��Խ������
//	for (i = 1; i < col; i++)
//	{
//		if (' ' == board[0][col - 1] || board[0][col - 1] != board[i][col - i - 1])
//			break;
//	}
//	if (col == i)
//		return board[0][col - 1];
//
//	// �ж�ƽ��
//	if (1 == IsFull(board, row, col))
//		return 'Q';
//
//	// ��Ϸ����
//	return 'C';
//}

