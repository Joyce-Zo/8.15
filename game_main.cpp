#include "game.h"

//					   定 义 函 数

//			 1.  初始化函数
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

//			 2.  打印函数
void DisPlayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("\n-----扫雷游戏------\n");
	//   打印列号
	for (i = 0; i < row + 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row+1; i++)
	{
		printf("%d ", i);// 打印行号
		for (j = 1; j < col+1; j++)
		{
			printf("%c ", board[i][j]);
		}
		//  上面代码是打印一行，下面换行后再进入循环
		printf("\n");
	}
	//printf("-----扫雷游戏------\n");

}
//              3.布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{ 
		//      随机值 % 9 结果为1-8，所以+1 =9
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//            4.1 计算所选坐标周围雷的个数
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

//              4. 开始扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y = 0;
	int Win = 0;
	while (Win	<	row*col-Easy_Count)
	{
		printf("请输入要排查雷的坐标:");
		scanf("%d%d", &x, &y);
		//   如果坐标合法
		if (x >= 1 && x < row + 1 && y >= 1 && y < col + 1)
		{
			//   直接踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被雷炸死了!\n	");
				DisPlayBoard(mine, row, col);
				break;
			}
			//   未踩雷
			else
			{
				//   计算所选坐标周围有几个雷 
				int count = Get_Mine_Count(mine, x, y);
				show[x][y] = count + '0';
				Unfold(mine, x, y);
				DisPlayBoard(show, row, col);
				Win++;
			}
		}
		//   如果坐标非法
		else
		{
			printf("坐标非法，请重新输入!");
		}
	}
	if (Win == row * col - Easy_Count)
	{
		printf("恭喜你排雷成功!\n");
		DisPlayBoard(mine, row, col);
	}
}