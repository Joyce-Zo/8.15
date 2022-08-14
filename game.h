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


//					声 明 函 数

//		    1.  初始化函数
void InitBoard(char board[ROWS][COLS], int row, int col, char set);

//			2.  打印函数
void DisPlayBoard(char board[ROWS][COLS],int row,int col);

//          3.  布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//          4.  开始扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);


void Unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* count);