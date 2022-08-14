#pragma once

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define Easy_Count 10

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <wincrypt.h>


//					�� �� �� ��

//		    1.  ��ʼ������
void InitBoard(char board[ROWS][COLS], int row, int col, char set);

//			2.  ��ӡ����
void DisPlayBoard(char board[ROWS][COLS],int row,int col);

//          3.  ������
void SetMine(char board[ROWS][COLS], int row, int col);

//          4.  ��ʼɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);


void Unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count);