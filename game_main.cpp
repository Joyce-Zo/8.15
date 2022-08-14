#include "game.h"

//					   �� �� �� ��

//			 1.  ��ʼ������
void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

//			 2.  ��ӡ����
void DisPlayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("\n-----ɨ����Ϸ------\n");
	//   ��ӡ�к�
	for (i = 0; i < row + 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row+1; i++)
	{
		printf("%d ", i);// ��ӡ�к�
		for (j = 1; j < col+1; j++)
		{
			printf("%c ", board[i][j]);
		}
		//  ��������Ǵ�ӡһ�У����滻�к��ٽ���ѭ��
		printf("\n");
	}
	//printf("-----ɨ����Ϸ------\n");

}
//              3.������
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{ 
		//      ���ֵ % 9 ���Ϊ1-8������+1 =9
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//            4.1 ������ѡ������Χ�׵ĸ���
int Get_Mine_Count(char mine[ROWS][COLS], int x, int y)
{
	return	mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void Unfold(char mine[ROWS][COLS],int x,int y)
{
	if (1);
}

//              4. ��ʼɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y = 0;
	int Win = 0;
	while (Win	<	row*col-Easy_Count)
	{
		printf("������Ҫ�Ų��׵�����:");
		scanf("%d%d", &x, &y);
		//   �������Ϸ�
		if (x >= 1 && x < row + 1 && y >= 1 && y < col + 1)
		{
			//   ֱ�Ӳ���
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻��ը����!\n	");
				DisPlayBoard(mine, row, col);
				break;
			}
			//   δ����
			else
			{
				//   ������ѡ������Χ�м����� 
				int count = Get_Mine_Count(mine, x, y);
				show[x][y] = count + '0';
				Unfold(mine, x, y);
				DisPlayBoard(show, row, col);
				Win++;
			}
		}
		//   �������Ƿ�
		else
		{
			printf("����Ƿ�������������!");
		}
	}
	if (Win == row * col - Easy_Count)
	{
		printf("��ϲ�����׳ɹ�!\n");
		DisPlayBoard(mine, row, col);
	}
}