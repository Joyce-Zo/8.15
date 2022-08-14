#include "game.h"


void menu()
{
	printf("\n*************************\n");
	printf("******** 1.Play *********\n"); 
	printf("******** 0.Quit *********\n");
	printf("*************************\n");
}

void game()
{
	printf("扫雷游戏开始\n");
	Sleep(500);

	char mine[ROWS][COLS] = { 0 };// 存放 布置好雷 的信息
	char show[ROWS][COLS] = { 0 };// 存放 排查出雷 的信息

	//  初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//  打印棋盘
	//DisPlayBoard(mine, ROW, COL);
	DisPlayBoard(show, ROW, COL);

	//  布置雷
	SetMine(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);

	//  开始扫雷
	FindMine(mine,show,ROW,COL);

}
void game_main()
{
	int input=0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}

int main()
{
	game_main();
	return 0;
}