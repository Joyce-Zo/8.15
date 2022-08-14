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
	printf("ɨ����Ϸ��ʼ\n");
	Sleep(500);

	char mine[ROWS][COLS] = { 0 };// ��� ���ú��� ����Ϣ
	char show[ROWS][COLS] = { 0 };// ��� �Ų���� ����Ϣ

	//  ��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//  ��ӡ����
	//DisPlayBoard(mine, ROW, COL);
	DisPlayBoard(show, ROW, COL);

	//  ������
	SetMine(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);

	//  ��ʼɨ��
	FindMine(mine,show,ROW,COL);

}
void game_main()
{
	int input=0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
}

int main()
{
	game_main();
	return 0;
}