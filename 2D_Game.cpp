#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <WTypes.h>
using namespace std;
void Design(char Mat[][135], int &Lose)
{
	int r, c;
	for (r = 0; r < 43; r++)
	{
		for (c = 0; c < 135; c++)
		{
			if (Mat[r][c] != '>')
			{
				Mat[r][c] = ' ';
			}
		}
	}
	for (r = 1; r<43; r++)
	{
		Mat[r][0] = 186;
		Mat[r][134] = 186;
	}
	for (c = 1; c<134; c++)
	{
		Mat[0][c] = 205;
		Mat[42][c] = 205;
	}
	Mat[0][0] = 201; Mat[0][134] = 187;
	Mat[42][0] = 200; Mat[42][134] = 188;
	for (int i = 1; i <= Lose; i++)
	{
		Mat[1][i] = 3;
	}
}
void Disp(char Mat[][135])
{
	int r, c;
	system("cls");
	for (int r = 0; r < 43; r++)
	{
		for (int c = 0; c < 135; c++)
		{
			cout << Mat[r][c];
		}
	}
	cout.flush();
	Sleep(1);
}
void Design2(char Mat[][135], int &Lose)
{
	int r, c;
	for (r = 0; r < 43; r++)
	{
		for (c = 0; c < 135; c++)
		{
			Mat[r][c] = ' ';
		}
	}
	for (r = 1; r<43; r++)
	{
		Mat[r][0] = 186;
		Mat[r][134] = 186;
	}
	for (c = 1; c<134; c++)
	{
		Mat[0][c] = 205;
		Mat[42][c] = 205;
	}
	Mat[0][0] = 201; Mat[0][134] = 187;
	Mat[42][0] = 200; Mat[42][134] = 188;
	for (int i = 1; i <= Lose; i++)
	{
		Mat[1][i] = 3;
	}
}

void SetHero(char Mat[][135], int rh, int ch, int a)//the walking hero
{
	Mat[rh][ch] = '|'; Mat[rh][ch + 3] = '.'; Mat[rh][ch + 4] = '-'; Mat[rh][ch + 5] = '.';
	Mat[rh + 1][ch] = '|'; Mat[rh + 1][ch + 1] = '|'; Mat[rh + 1][ch + 2] = '/'; Mat[rh + 1][ch + 3] = '_'; Mat[rh + 1][ch + 4] = '_'; Mat[rh + 1][ch + 5] = ':'; Mat[rh + 1][ch + 6] = '`'; Mat[rh + 1][ch + 7] = '.';
	Mat[rh + 2][ch] = '|'; Mat[rh + 2][ch + 1] = '/'; Mat[rh + 2][ch + 2] = '/'; Mat[rh + 2][ch + 3] = '('; Mat[rh + 2][ch + 4] = ')'; Mat[rh + 2][ch + 5] = ':'; Mat[rh + 2][ch + 6] = '-'; Mat[rh + 2][ch + 7] = '.'; Mat[rh + 2][ch + 8] = ':';
	Mat[rh + 3][ch] = '|'; Mat[rh + 3][ch + 1] = '-'; Mat[rh + 3][ch + 2] = '.'; Mat[rh + 3][ch + 3] = '|'; Mat[rh + 3][ch + 4] = '|';
	Mat[rh + 4][ch] = '|'; Mat[rh + 4][ch + 1] = 'o'; Mat[rh + 4][ch + 2] = '('; Mat[rh + 4][ch + 3] = 'o'; Mat[rh + 4][ch + 4] = ')';
	Mat[rh + 5][ch] = '|'; Mat[rh + 5][ch + 1] = '|'; Mat[rh + 5][ch + 2] = '|'; Mat[rh + 5][ch + 3] = '\\'; Mat[rh + 5][ch + 4] = '\\'; Mat[rh + 5][ch + 5] = '\\'; Mat[rh + 5][ch + 8] = '.'; Mat[rh + 5][ch + 9] = 205; Mat[rh + 5][ch + 10] = 205; Mat[rh + 5][ch + 11] = '.'; Mat[rh + 5][ch + 12] = '_';
	Mat[rh + 6][ch] = '|'; Mat[rh + 6][ch + 1] = '|'; Mat[rh + 6][ch + 2] = '|'; Mat[rh + 6][ch + 3] = '('; Mat[rh + 6][ch + 4] = 'o'; Mat[rh + 6][ch + 5] = ')'; Mat[rh + 6][ch + 6] = 205; Mat[rh + 6][ch + 7] = 205; Mat[rh + 6][ch + 8] = ':'; Mat[rh + 6][ch + 9] = ':'; Mat[rh + 6][ch + 10] = '`';
	Mat[rh + 7][ch + 1] = '`'; Mat[rh + 7][ch + 2] = '|'; Mat[rh + 7][ch + 3] = 'T'; Mat[rh + 7][ch + 6] = '"'; Mat[rh + 7][ch + 7] = '"';
	Mat[rh + 8][ch + 2] = '('; Mat[rh + 8][ch + 3] = 'o'; Mat[rh + 8][ch + 4] = ')';
	if (a == 0) {
		Mat[rh + 9][ch + 2] = '|'; Mat[rh + 9][ch + 3] = '\\'; Mat[rh + 9][ch + 4] = '\\';
		Mat[rh + 10][ch + 2] = '|'; Mat[rh + 10][ch + 3] = '|'; Mat[rh + 10][ch + 4] = '\\'; Mat[rh + 10][ch + 5] = '\\';
		Mat[rh + 11][ch + 1] = '('; Mat[rh + 11][ch + 2] = 'o'; Mat[rh + 11][ch + 3] = ')'; Mat[rh + 11][ch + 4] = '('; Mat[rh + 11][ch + 5] = 'o'; Mat[rh + 11][ch + 6] = ')';
		Mat[rh + 12][ch + 1] = '/'; Mat[rh + 12][ch + 2] = '/'; Mat[rh + 12][ch + 4] = '/'; Mat[rh + 12][ch + 5] = '/';
		Mat[rh + 13][ch] = '('; Mat[rh + 13][ch + 1] = 'o'; Mat[rh + 13][ch + 2] = ')'; Mat[rh + 13][ch + 3] = '('; Mat[rh + 13][ch + 4] = 'o'; Mat[rh + 13][ch + 5] = ')';
		Mat[rh + 14][ch + 1] = '"'; Mat[rh + 14][ch + 4] = '"';
	}
	if (a == 1) {
		Mat[rh + 9][ch + 1] = '/'; Mat[rh + 9][ch + 2] = '/'; Mat[rh + 9][ch + 3] = '/';
		Mat[rh + 10][ch] = '/'; Mat[rh + 10][ch + 1] = '/'; Mat[rh + 10][ch + 2] = '/';
		Mat[rh + 11][ch - 1] = '('; Mat[rh + 11][ch] = '('; Mat[rh + 11][ch + 1] = 'o'; Mat[rh + 11][ch + 2] = ')';
		Mat[rh + 12][ch - 1] = '/'; Mat[rh + 12][ch] = '/'; Mat[rh + 12][ch + 1] = '/';
		Mat[rh + 13][ch - 2] = '('; Mat[rh + 13][ch - 1] = '('; Mat[rh + 13][ch] = 'o'; Mat[rh + 13][ch + 1] = ')';
		Mat[rh + 14][ch - 1] = '"'; Mat[rh + 14][ch] = '"';
	}
	if (a == 2) {
		Mat[rh + 9][ch + 3] = '\\'; Mat[rh + 9][ch + 4] = '\\'; Mat[rh + 9][ch + 5] = '\\';
		Mat[rh + 10][ch + 4] = '\\'; Mat[rh + 10][ch + 5] = '\\'; Mat[rh + 10][ch + 6] = '\\';
		Mat[rh + 11][ch + 4] = '('; Mat[rh + 11][ch + 5] = 'o'; Mat[rh + 11][ch + 6] = ')'; Mat[rh + 11][ch + 7] = ')';
		Mat[rh + 12][ch + 5] = '\\'; Mat[rh + 12][ch + 6] = '\\'; Mat[rh + 12][ch + 7] = '\\';
		Mat[rh + 13][ch + 5] = '('; Mat[rh + 13][ch + 6] = 'o'; Mat[rh + 13][ch + 7] = ')'; Mat[rh + 13][ch + 8] = ')';
		Mat[rh + 14][ch + 6] = '"'; Mat[rh + 14][ch + 7] = '"';
	}
	if (a == 3) {
		Mat[rh + 9][ch + 2] = '|'; Mat[rh + 9][ch + 3] = '\\'; Mat[rh + 9][ch + 4] = '\\';
		Mat[rh + 10][ch + 2] = '|'; Mat[rh + 10][ch + 3] = '|'; Mat[rh + 10][ch + 4] = '\\'; Mat[rh + 10][ch + 5] = '\\';
		Mat[rh + 11][ch + 1] = '('; Mat[rh + 11][ch + 2] = 'o'; Mat[rh + 11][ch + 3] = ')'; Mat[rh + 11][ch + 4] = '('; Mat[rh + 11][ch + 5] = 'o'; Mat[rh + 11][ch + 6] = ')';
		Mat[rh + 12][ch + 1] = '/'; Mat[rh + 12][ch + 2] = '/'; Mat[rh + 12][ch + 5] = '\\'; Mat[rh + 12][ch + 6] = '\\';
		Mat[rh + 13][ch] = '('; Mat[rh + 13][ch + 1] = 'o'; Mat[rh + 13][ch + 2] = ')'; Mat[rh + 13][ch + 5] = '('; Mat[rh + 13][ch + 6] = 'o'; Mat[rh + 13][ch + 7] = ')';
		Mat[rh + 14][ch + 1] = '"'; Mat[rh + 14][ch + 6] = '"';
		Mat[rh + 15][ch + 1] = '"'; Mat[rh + 15][ch + 6] = '"';
	}
	if (a == 4) {
		Mat[rh + 9][ch + 2] = '|'; Mat[rh + 9][ch + 3] = '\\'; Mat[rh + 9][ch + 4] = '\\';
		Mat[rh + 10][ch + 2] = '|'; Mat[rh + 10][ch + 3] = '|'; Mat[rh + 10][ch + 4] = '\\'; Mat[rh + 10][ch + 5] = '\\';
		Mat[rh + 11][ch + 1] = '('; Mat[rh + 11][ch + 2] = 'o'; Mat[rh + 11][ch + 3] = ')'; Mat[rh + 11][ch + 4] = '('; Mat[rh + 11][ch + 5] = 'o'; Mat[rh + 11][ch + 6] = ')';
		Mat[rh + 12][ch + 1] = '/'; Mat[rh + 12][ch + 2] = '/'; Mat[rh + 12][ch + 4] = '/'; Mat[rh + 12][ch + 5] = '/';
		Mat[rh + 13][ch] = '('; Mat[rh + 13][ch + 1] = 'o'; Mat[rh + 13][ch + 2] = ')'; Mat[rh + 13][ch + 3] = '('; Mat[rh + 13][ch + 4] = 'o'; Mat[rh + 13][ch + 5] = ')';
		Mat[rh + 14][ch + 1] = '"'; Mat[rh + 14][ch + 4] = '"';
	}
}
void MoveHero(char Mat[][135], char q, int &rh, int &ch)//moving the waliking
{
	if (q == 'd')
	{
		SetHero(Mat, rh, ch, 1);
		if (ch + 12 < 131) ch += 3;
	}
	if (q == 'a')
	{
		SetHero(Mat, rh, ch, 2);
		if (ch - 2 > 3) ch -= 3;
	}
	if (q == 'w')
	{
		for (int i = 0; i < 10; i++)rh--;
		if (ch + 12 < 131) ch += 10;
		SetHero(Mat, rh, ch, 3);
		for (int i = 0; i < 10; i++)rh++;
		/*for (int i = 0; i < 8; i++)
		{
		rh--; ch++; Design(Mat); SetHero(Mat, rh, ch, 3); Disp(Mat);
		}
		for (int i = 0; i < 8; i++)
		{
		rh++; ch++; Design(Mat); SetHero(Mat, rh, ch, 3); Disp(Mat);
		}*/
	}
	if (q == 's')
	{
		SetHero(Mat, rh, ch, 4);
		if (rh + 17 < 42)rh += 3;
	}
}
void SetHero2(char Mat[][135], int rh, int ch, int a)//the helicopter
{
	if (a == 11)//phase 1
	{
		Mat[rh + 1][ch + 8] = '|'; Mat[rh + 1][ch + 11] = '.'; Mat[rh + 1][ch + 12] = '-'; Mat[rh + 1][ch + 13] = '.';
		Mat[rh + 2][ch + 7] = '|'; Mat[rh + 2][ch + 8] = '|'; Mat[rh + 2][ch + 9] = '/'; Mat[rh + 2][ch + 10] = '_'; Mat[rh + 2][ch + 11] = '_'; Mat[rh + 2][ch + 12] = ':'; Mat[rh + 2][ch + 13] = '`'; Mat[rh + 2][ch + 14] = '.';
		Mat[rh + 3][ch + 6] = '|'; Mat[rh + 3][ch + 7] = '/'; Mat[rh + 3][ch + 8] = '/'; Mat[rh + 3][ch + 9] = '('; Mat[rh + 3][ch + 10] = ')'; Mat[rh + 3][ch + 11] = ':'; Mat[rh + 3][ch + 12] = '-'; Mat[rh + 3][ch + 13] = '.'; Mat[rh + 3][ch + 14] = ':';
		Mat[rh + 4][ch + 5] = '|'; Mat[rh + 4][ch + 6] = '-'; Mat[rh + 4][ch + 7] = '.'; Mat[rh + 4][ch + 8] = '|'; Mat[rh + 4][ch + 9] = '|';
		Mat[rh + 5][ch + 4] = '|'; Mat[rh + 5][ch + 5] = 'o'; Mat[rh + 5][ch + 6] = '('; Mat[rh + 5][ch + 7] = 'o'; Mat[rh + 5][ch + 8] = ')';
		Mat[rh + 6][ch + 3] = '|'; Mat[rh + 6][ch + 4] = '|'; Mat[rh + 6][ch + 5] = '|'; Mat[rh + 6][ch + 6] = '\\'; Mat[rh + 6][ch + 7] = '\\'; Mat[rh + 6][ch + 8] = '\\'; Mat[rh + 6][ch + 12] = '.'; Mat[rh + 6][ch + 13] = 205; Mat[rh + 6][ch + 14] = 205; Mat[rh + 6][ch + 15] = '.'; Mat[rh + 6][ch + 16] = '_';
		Mat[rh + 7][ch + 2] = '|'; Mat[rh + 7][ch + 3] = '|'; Mat[rh + 7][ch + 4] = '|'; Mat[rh + 7][ch + 5] = '('; Mat[rh + 7][ch + 6] = 'o'; Mat[rh + 7][ch + 7] = ')'; Mat[rh + 7][ch + 8] = 205; Mat[rh + 7][ch + 9] = 205; Mat[rh + 7][ch + 10] = ':'; Mat[rh + 7][ch + 11] = ':'; Mat[rh + 7][ch + 12] = '`';
		Mat[rh + 8][ch] = '`'; Mat[rh + 8][ch + 1] = '|'; Mat[rh + 8][ch + 2] = 'T'; Mat[rh + 8][ch + 3] = '"'; Mat[rh + 8][ch + 4] = '"';
		Mat[rh + 9][ch + 4] = '('; Mat[rh + 9][ch + 5] = 'o'; Mat[rh + 9][ch + 6] = ')';
		Mat[rh + 9][ch + 2] = '|'; Mat[rh + 9][ch + 3] = '\\'; Mat[rh + 9][ch + 4] = '\\';
		Mat[rh + 10][ch + 2] = '|'; Mat[rh + 10][ch + 3] = '|'; Mat[rh + 10][ch + 4] = '\\'; Mat[rh + 10][ch + 5] = '\\';
		Mat[rh + 11][ch + 1] = '('; Mat[rh + 11][ch + 2] = 'o'; Mat[rh + 11][ch + 3] = ')'; Mat[rh + 11][ch + 4] = '('; Mat[rh + 11][ch + 5] = 'o'; Mat[rh + 11][ch + 6] = ')';
		Mat[rh + 12][ch + 1] = '/'; Mat[rh + 12][ch + 2] = '/'; Mat[rh + 12][ch + 4] = '/'; Mat[rh + 12][ch + 5] = '/';
		Mat[rh + 13][ch] = '('; Mat[rh + 13][ch + 1] = 'o'; Mat[rh + 13][ch + 2] = ')'; Mat[rh + 13][ch + 3] = '('; Mat[rh + 13][ch + 4] = 'o'; Mat[rh + 13][ch + 5] = ')';
		Mat[rh + 14][ch + 1] = '"'; Mat[rh + 14][ch + 4] = '"';
	}
	if (a == 12)//phase 2
	{
		Mat[rh + 1][ch + 21] = '|'; Mat[rh + 1][ch + 22] = '.'; Mat[rh + 1][ch + 23] = '-'; Mat[rh + 1][ch + 24] = '.';
		Mat[rh + 2][ch + 20] = '|'; Mat[rh + 2][ch + 21] = '|'; Mat[rh + 2][ch + 22] = '/'; Mat[rh + 2][ch + 23] = '_'; Mat[rh + 2][ch + 24] = '_'; Mat[rh + 2][ch + 25] = ':'; Mat[rh + 2][ch + 26] = '`'; Mat[rh + 2][ch + 27] = '.';
		Mat[rh + 3][ch + 19] = '|'; Mat[rh + 3][ch + 20] = '/'; Mat[rh + 3][ch + 21] = '/'; Mat[rh + 3][ch + 22] = '('; Mat[rh + 3][ch + 23] = ')'; Mat[rh + 3][ch + 24] = ':'; Mat[rh + 3][ch + 25] = '-'; Mat[rh + 3][ch + 26] = '.'; Mat[rh + 3][ch + 27] = ':';
		Mat[rh + 4][ch + 18] = '|'; Mat[rh + 4][ch + 19] = '-'; Mat[rh + 4][ch + 20] = '.'; Mat[rh + 4][ch + 21] = '|'; Mat[rh + 4][ch + 22] = '|';
		Mat[rh + 5][ch + 17] = '|'; Mat[rh + 5][ch + 18] = 'o'; Mat[rh + 5][ch + 19] = '('; Mat[rh + 5][ch + 20] = 'o'; Mat[rh + 5][ch + 21] = ')';
		Mat[rh + 6][ch + 15] = '|'; Mat[rh + 6][ch + 16] = '|'; Mat[rh + 6][ch + 17] = '|'; Mat[rh + 6][ch + 18] = '\\'; Mat[rh + 6][ch + 19] = '\\'; Mat[rh + 6][ch + 20] = '\\'; Mat[rh + 6][ch + 21] = '.'; Mat[rh + 6][ch + 22] = 205; Mat[rh + 6][ch + 23] = 205; Mat[rh + 6][ch + 24] = '.'; Mat[rh + 6][ch + 25] = '_';
		Mat[rh + 7][ch + 14] = '|'; Mat[rh + 7][ch + 15] = '|'; Mat[rh + 7][ch + 16] = '|'; Mat[rh + 7][ch + 17] = '('; Mat[rh + 7][ch + 18] = 'o'; Mat[rh + 7][ch + 19] = ')'; Mat[rh + 7][ch + 20] = 205; Mat[rh + 7][ch + 21] = 205; Mat[rh + 7][ch + 22] = ':'; Mat[rh + 7][ch + 23] = ':'; Mat[rh + 7][ch + 24] = '`';
		Mat[rh + 8][ch + 13] = '`'; Mat[rh + 8][ch + 14] = '|'; Mat[rh + 8][ch + 15] = 'T'; Mat[rh + 8][ch + 16] = '"'; Mat[rh + 8][ch + 17] = '"';
		Mat[rh + 9][ch + 12] = '('; Mat[rh + 9][ch + 13] = 'o'; Mat[rh + 9][ch + 14] = ')';
		Mat[rh + 10][ch + 11] = '|'; Mat[rh + 10][ch + 12] = '|'; Mat[rh + 10][ch + 13] = '\\'; Mat[rh + 10][ch + 14] = '\\';
		Mat[rh + 11][ch + 10] = '('; Mat[rh + 11][ch + 11] = 'o'; Mat[rh + 11][ch + 12] = ')'; Mat[rh + 11][ch + 13] = '('; Mat[rh + 11][ch + 14] = 'o'; Mat[rh + 11][ch + 14] = ')';
		Mat[rh + 12][ch + 9] = '/'; Mat[rh + 12][ch + 10] = '/'; Mat[rh + 12][ch + 11] = '/'; Mat[rh + 12][ch + 12] = '/';
		Mat[rh + 13][ch + 8] = '('; Mat[rh + 13][ch + 9] = 'o'; Mat[rh + 13][ch + 10] = ')'; Mat[rh + 13][ch + 11] = '('; Mat[rh + 13][ch + 12] = 'o'; Mat[rh + 13][ch + 13] = ')';
		Mat[rh + 14][ch + 8] = '"'; Mat[rh + 14][ch + 12] = '"';
	}
	if (a == 0)//the still postion
	{
		int pr = rh, pc = ch;
		Mat[pr + 6][pc + 15] = '-'; Mat[pr + 6][pc + 16] = '-'; Mat[pr + 6][pc + 17] = '-'; Mat[pr + 6][pc + 18] = '-'; Mat[pr + 6][pc + 19] = '-'; Mat[pr + 6][pc + 20] = '-'; Mat[pr + 6][pc + 21] = '-'; Mat[pr + 6][pc + 22] = '-'; Mat[pr + 6][pc + 23] = '-'; Mat[pr + 6][pc + 24] = '-'; Mat[pr + 6][pc + 25] = '-'; Mat[pr + 6][pc + 26] = '-'; Mat[pr + 6][pc + 27] = '-'; Mat[pr + 6][pc + 28] = '-'; Mat[pr + 6][pc + 29] = '-'; Mat[pr + 6][pc + 30] = '-'; Mat[pr + 6][pc + 31] = '-'; Mat[pr + 6][pc + 32] = '-'; Mat[pr + 6][pc + 33] = '-'; Mat[pr + 6][pc + 34] = '-'; Mat[pr + 6][pc + 35] = '-'; Mat[pr + 6][pc + 36] = '-';
		Mat[pr + 7][pc + 25] = ']'; Mat[pr + 7][pc + 26] = '[';
		Mat[pr + 8][pc + 24] = '.'; Mat[pr + 8][pc + 25] = '.'; Mat[pr + 8][pc + 26] = '.'; Mat[pr + 8][pc + 27] = '.';
		Mat[pr + 9][pc + 20] = '.'; Mat[pr + 9][pc + 21] = ','; Mat[pr + 9][pc + 22] = '-'; Mat[pr + 9][pc + 23] = '-'; Mat[pr + 9][pc + 24] = '-'; Mat[pr + 9][pc + 25] = '-'; Mat[pr + 9][pc + 26] = '-'; Mat[pr + 9][pc + 27] = '-'; Mat[pr + 9][pc + 28] = '-'; Mat[pr + 9][pc + 29] = '-'; Mat[pr + 9][pc + 30] = '-';
		Mat[pr + 10][pc + 31] = '\\'; Mat[pr + 10][pc + 32] = '__'; Mat[pr + 10][pc + 11] = '//'; Mat[pr + 10][pc + 12] = '/'; Mat[pr + 10][pc + 13] = '/'; Mat[pr + 10][pc + 14] = '/'; Mat[pr + 10][pc + 15] = '__'; Mat[pr + 10][pc + 16] = '__'; Mat[pr + 10][pc + 17] = '__'; Mat[pr + 10][pc + 18] = '.'; Mat[pr + 10][pc + 19] = '//';
		Mat[pr + 11][pc + 8] = '\\'; Mat[pr + 11][pc + 9] = '\\'; Mat[pr + 11][pc + 9] = '='; Mat[pr + 11][pc + 10] = '='; Mat[pr + 11][pc + 11] = 'o'; Mat[pr + 11][pc + 12] = '='; Mat[pr + 11][pc + 13] = '='; Mat[pr + 11][pc + 14] = '='; Mat[pr + 11][pc + 15] = '='; Mat[pr + 11][pc + 16] = ':'; Mat[pr + 11][pc + 17] = ';'; Mat[pr + 11][pc + 33] = ')';
		Mat[pr + 12][pc + 32] = '.'; Mat[pr + 12][pc + 31] = '__'; Mat[pr + 12][pc + 30] = ','; Mat[pr + 12][pc + 29] = '.'; Mat[pr + 12][pc + 28] = '__'; Mat[pr + 12][pc + 27] = '__'; Mat[pr + 12][pc + 26] = '__'; Mat[pr + 12][pc + 25] = '__'; Mat[pr + 12][pc + 24] = '='; Mat[pr + 12][pc + 23] = '\\'; Mat[pr + 12][pc + 22] = '='; Mat[pr + 12][pc + 21] = '='; Mat[pr + 12][pc + 20] = '__'; Mat[pr + 12][pc + 19] = '__'; Mat[pr + 12][pc + 18] = '\\';
	}
}
void MoveHero2(char Mat[][135], char q, int &rh, int &ch)//moving the helicopter
{
	if (q == 'd')
	{
		SetHero2(Mat, rh, ch, 0);
		if (ch + 37 < 131) ch += 4;
	}
	if (q == 'a')
	{
		SetHero2(Mat, rh, ch, 0);
		if (ch + 8 > 4) ch -= 4;
	}
	if (q == 'w')
	{
		SetHero2(Mat, rh, ch, 0);
		if (rh + 6 > 3) rh -= 4;
	}
	if (q == 's')
	{
		SetHero2(Mat, rh, ch, 0);
		if (rh + 12 < 27)rh += 4;
	}
}

void SetEnemy2(char Mat[][135], int re, int ce, int a)//the plane
{
	Mat[re][ce + 26] = '_'; Mat[re][ce + 27] = '_';
	Mat[re + 1][ce + 25] = '/'; Mat[re + 1][ce + 27] = '/'; Mat[re + 1][ce + 28] = ']';
	Mat[re + 2][ce + 24] = '/'; Mat[re + 2][ce + 26] = '/'; Mat[re + 2][ce + 28] = ']';
	Mat[re + 3][ce + 6] = ','; Mat[re + 3][ce + 7] = '='; Mat[re + 3][ce + 8] = '='; Mat[re + 3][ce + 9] = '='; Mat[re + 3][ce + 10] = '='; Mat[re + 3][ce + 11] = '='; Mat[re + 3][ce + 12] = '='; Mat[re + 3][ce + 13] = '='; Mat[re + 3][ce + 14] = '='; Mat[re + 3][ce + 15] = '_'; Mat[re + 3][ce + 16] = '_'; Mat[re + 3][ce + 17] = '_'; Mat[re + 3][ce + 18] = '_'; Mat[re + 3][ce + 19] = '_'; Mat[re + 3][ce + 20] = ','; Mat[re + 3][ce + 21] = '.'; Mat[re + 3][ce + 23] = '"'; Mat[re + 3][ce + 25] = '/'; Mat[re + 3][ce + 28] = ']';
	Mat[re + 4][ce + 2] = '_'; Mat[re + 4][ce + 3] = '_'; Mat[re + 4][ce + 4] = '_'; Mat[re + 4][ce + 5] = '/'; Mat[re + 4][ce + 6] = '_'; Mat[re + 4][ce + 7] = '_'; Mat[re + 4][ce + 8] = '_'; Mat[re + 4][ce + 9] = '_'; Mat[re + 4][ce + 10] = '|'; Mat[re + 4][ce + 11] = '_'; Mat[re + 4][ce + 12] = '_'; Mat[re + 4][ce + 13] = '_'; Mat[re + 4][ce + 14] = ')'; Mat[re + 4][ce + 25] = '_'; Mat[re + 4][ce + 26] = '_'; Mat[re + 4][ce + 27] = '`'; Mat[re + 4][ce + 28] = ']';
	Mat[re + 5][ce] = '<'; Mat[re + 5][ce + 1] = '|'; Mat[re + 5][ce + 10] = '|'; Mat[re + 5][ce + 20] = ','; Mat[re + 5][ce + 21] = '.'; Mat[re + 5][ce + 22] = '`'; Mat[re + 5][ce + 22] = '`';
	Mat[re + 6][ce + 2] = '\\'; Mat[re + 6][ce + 10] = '|'; Mat[re + 6][ce + 15] = ','; Mat[re + 6][ce + 16] = '.'; Mat[re + 6][ce + 17] = '`'; Mat[re + 6][ce + 18] = '`';
	Mat[re + 7][ce + 3] = '\\'; Mat[re + 7][ce + 4] = ','; Mat[re + 7][ce + 5] = '_'; Mat[re + 7][ce + 6] = '_'; Mat[re + 7][ce + 7] = '_'; Mat[re + 7][ce + 8] = '_'; Mat[re + 7][ce + 9] = '_'; Mat[re + 7][ce + 10] = '|'; Mat[re + 7][ce + 11] = '_'; Mat[re + 7][ce + 12] = ','; Mat[re + 7][ce + 13] = '.'; Mat[re + 7][ce + 14] = '`'; Mat[re + 7][ce + 15] = '`';
	Mat[re + 8][ce + 7] = '('; Mat[re + 8][ce + 8] = '_'; Mat[re + 8][ce + 9] = '_'; Mat[re + 8][ce + 10] = '_'; Mat[re + 8][ce + 11] = '_'; Mat[re + 8][ce + 12] = '='; Mat[re + 8][ce + 13] = '=';
}
void MoveEnemy2(char Mat[][135], int &re, int &ce)
{
	ce -= 3; if (ce + 28 <= 0)ce = 107;
}
void SetBulletEnemy2(char Mat[][135], int e2rbul, int e2cbul)
{
	Mat[e2rbul][e2cbul] = '<';
}
void MoveBulletEnemy2(char Mat[][135], int &e2rbul, int &e2cbul, int ce2)
{
	if (e2cbul - 5 > 0)e2cbul -= 5; else Mat[e2rbul][e2cbul] = ' ';
	if (e2cbul - 5 <= 0 && ce2 == 107)e2cbul = 113;
}

void SetEnemy1(char Mat[][135], int re, int ce)//the ground enemy
{
	Mat[re - 2][ce - 8] = '('; Mat[re - 2][ce - 7] = '__'; Mat[re - 2][ce - 6] = ')'; Mat[re - 2][ce - 4] = '('; Mat[re - 2][ce - 3] = '__'; Mat[re - 2][ce - 2] = ')';
	Mat[re - 3][ce] = '|'; Mat[re - 3][ce - 10] = '//';	Mat[re - 3][ce - 9] = '__'; Mat[re - 3][ce - 8] = '__'; Mat[re - 3][ce - 7] = '__'; Mat[re - 3][ce - 6] = '__'; Mat[re - 3][ce - 5] = '__'; Mat[re - 3][ce - 4] = '__'; Mat[re - 3][ce - 3] = '__'; Mat[re - 3][ce - 2] = '__'; Mat[re - 3][ce - 1] = '__';
	Mat[re - 4][ce] = '|'; Mat[re - 4][ce - 9] = '//';
	Mat[re - 5][ce] = '|';	Mat[re - 5][ce - 8] = '//';
	Mat[re - 6][ce] = '|'; Mat[re - 6][ce - 7] = '//';
	Mat[re - 7][ce] = '|';	Mat[re - 7][ce - 6] = '//';
	Mat[re - 8][ce] = '|'; Mat[re - 8][ce - 6] = '\\'; Mat[re - 8][ce - 5] = '//';
	Mat[re - 9][ce - 1] = '__'; Mat[re - 9][ce - 2] = '|'; Mat[re - 9][ce - 3] = '|'; Mat[re - 9][ce - 4] = '__'; Mat[re - 9][ce - 7] = '['; Mat[re - 9][ce - 6] = ']';
	Mat[re - 10][ce - 2] = '|'; Mat[re - 10][ce - 3] = '|';
	Mat[re - 11][ce - 4] = '|'; Mat[re - 11][ce - 3] = '/'; Mat[re - 11][ce - 2] = '__'; Mat[re - 11][ce - 1] = '|';
	Mat[re - 12][ce - 1] = '|'; Mat[re - 12][ce - 3] = '\\'; Mat[re - 12][ce - 4] = '|'; Mat[re - 12][ce - 5] = '='; Mat[re - 12][ce - 6] = '='; Mat[re - 12][ce - 7] = '=';
	Mat[re - 13][ce - 4] = '__'; Mat[re - 13][ce - 2] = '__'; Mat[re - 13][ce - 3] = '__';
}
void MoveEnemy1(char Mat[][135], int &re, int &ce)
{
	ce -= 2; if (ce - 4 <= 0)ce = 135;
}
void SetBulletEnemy1(char Mat[][135], int e1rbul, int e1cbul)//ground enemy shooting
{
	Mat[e1rbul][e1cbul] = '<';
}
void MoveBulletEnemy1(char Mat[][135], int &e1rbul, int &e1cbul, int ce1)
{
	if (e1cbul - 5 > 0)e1cbul -= 5; else Mat[e1rbul][e1cbul] = ' ';
	if (e1cbul - 5 <= 0 && ce1 == 135)e1cbul = 127;
}

void SetBullet(char Mat[][135], int rbul, int cbul)
{
	Mat[rbul][cbul] = '>';
}
void MoveBullet(char Mat[][135])
{
	int r, c, a = 0;
	for (r = 0; r < 44; r++)
	{
		for (c = 0; c < 135; c++)
		{
			if (Mat[r][c] == '>')
			{
				if (c + 4 < 134)
				{
					Mat[r][c + 4] = '>';
					Mat[r][c] = ' ';
					c += 4;
				}
				else Mat[r][c] = ' ';
				/*if (c >= 133)
				{
				a = 1;
				break;
				}*/
			}
		}
		//if (a == 1)break;
	}
}

void ClashWithEnemy(char Mat[][135], int tflag, int &level, int &re1, int &ce1, int &re2, int &ce2, int &e1rbul, int &e1cbul, int &e2rbul, int &e2cbul)
{
	int r, c, a = 0, r1 = 0, c1 = 0, r2 = 0, c2 = 0;
	for (r = 0; r < 44; r++)
	{
		for (c = 0; c < 135; c++)
		{
			if (level == 1 || level == 2)
			{
				if (Mat[r][c] == '>')
				{
					r1 = r, c1 = c;
				}
				if (r1 == (re1 - 11) && c1 >= (ce1 - 8) && c1 <= (ce1 + 1))
				{
					Mat[r][c] = ' ';
					level++; a = 1;
					re1 = 43, ce1 = 135;
					e1rbul = re1 - 12, e1cbul = ce1 - 8;
					break;
				}
			}
			if (level == 3)
			{
				if (Mat[r][c] == '>')
				{
					r2 = r, c2 = c;
				}
				if (r2 >= (re2 + 3) && r2 <= (re2 + 8) && c2 >= (ce2) && c2 <= (ce2 + 28))
				{
					Mat[r][c] = ' ';
					level++; a = 1;
					re2 = 2, ce2 = 107;
					e2rbul = re2 + 8, e2cbul = ce2 + 6;
					break;
				}
			}
			if (level == 4 || level == 5)
			{
				if (Mat[r][c] == '>')
				{
					r1 = r, c1 = c;
				}
				if (r1 == (re1 - 11) && c1 >= (ce1 - 8) && c1 <= (ce1 + 1))
				{
					Mat[r][c] = ' ';
					a = 1;
					level++;
					re1 = 43, ce1 = 135;
					e1rbul = re1 - 12, e1cbul = ce1 - 8;
					break;
				}
				if (Mat[r][c] == '>')
				{
					r2 = r, c2 = c;
				}
				if (r2 >= (re2 + 3) && r2 <= (re2 + 8) && c2 >= (ce2) && c2 <= (ce2 + 28))
				{
					Mat[r][c] = ' ';
					a = 1;
					level++;
					re2 = 2, ce2 = 107;
					e2rbul = re2 + 8, e2cbul = ce2 + 6;
					break;
				}
			}
		}if (a == 1)break;
	}
}
void ClashWithHero(char Mat[][135], int &Lose, int tflag, int rh, int ch, int &e1rbul, int &e1cbul, int &e2rbul, int &e2cbul, int re1, int ce1, int re2, int ce2)
{
	if (tflag % 2 != 0)
	{
		if (e1rbul >= rh && e1rbul <= (rh + 13) && e1cbul >= ch && e1cbul < (ch + 4))//Mat[e1rbul][e1cbul] != ' ' &&
		{
			Lose--;
		}
		if ((ce1 - 7) <= (ch + 8) && (ce1 - 7) >= ch && (re1 - 13) <= (rh + 13) && (re1 - 13) >= (rh))
		{
			Lose--;
		}
	}
	if (tflag % 2 == 0)
	{
		if (e2rbul >= (rh + 7) && e2rbul <= (rh + 12) && e2cbul >= (ch + 8) && e2cbul < (ch + 33))//Mat[e2rbul][e2cbul] != ' ' && 
		{
			Lose--;
		}
		if ((re2 + 2) <= (rh + 10) && (re2 + 7) >= (rh + 9) && (((ce2 + 2) <= (ch + 30) && (ce2 + 2) >= (ch + 7)) || ((ce2 + 27) >= (ch + 7) && (ce2 + 28) <= (ch + 30))))
		{
			Lose--;
		}
	}
}

void Trans(char Mat[][135], int &rh, int &ch, int tflag, int &level, int &Lose, int &re1, int &ce1, int &re2, int &ce2, int &e1rbul, int &e1cbul, int &e2rbul, int &e2cbul)//hero transformation
{
	//tflag is for the hel. or the ironman
	if (tflag % 2 == 0) //to a plane 
	{
		Design(Mat, Lose); SetHero2(Mat, rh, ch, 11); MoveBullet(Mat);
		if (level == 1)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 2)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 3)
		{
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 4 || level == 5)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}Disp(Mat);

		Design(Mat, Lose); SetHero2(Mat, rh, ch, 12); MoveBullet(Mat);
		if (level == 1)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 2)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 3)
		{
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 4 || level == 5)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}Disp(Mat);

		Design(Mat, Lose); SetHero2(Mat, rh, ch, 0);  MoveBullet(Mat);
		if (level == 1)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 2)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 3)
		{
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 4 || level == 5)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}Disp(Mat);

		for (int i = 0; i < 5; i++)
		{
			rh -= 2;
			Design(Mat, Lose); SetHero2(Mat, rh, ch, 0); MoveBullet(Mat);
			if (level == 1)
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 2)
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				SetBulletEnemy1(Mat, e1rbul, e1cbul);
				MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 3)
			{
				SetEnemy2(Mat, re2, ce2, 0);
				MoveEnemy2(Mat, re2, ce2);
				SetBulletEnemy2(Mat, e2rbul, e2cbul);
				MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 4 || level == 5)
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				SetBulletEnemy1(Mat, e1rbul, e1cbul);
				MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
				SetEnemy2(Mat, re2, ce2, 0);
				MoveEnemy2(Mat, re2, ce2);
				SetBulletEnemy2(Mat, e2rbul, e2cbul);
				MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}Disp(Mat);

		}
	}
	if (tflag % 2 != 0) //to an ironman
	{
		Design(Mat, Lose); SetHero2(Mat, rh, ch, 12); MoveBullet(Mat);
		if (level == 1)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 2)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 3)
		{
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 4 || level == 5)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}Disp(Mat);

		Design(Mat, Lose); SetHero2(Mat, rh, ch, 11); MoveBullet(Mat);
		if (level == 1)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 2)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 3)
		{
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 4 || level == 5)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}Disp(Mat);

		while (rh + 14 < 41)
		{
			rh++;
			Design(Mat, Lose); SetHero(Mat, rh, ch, 0);  MoveBullet(Mat);
			if (level == 1)
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 2)
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				SetBulletEnemy1(Mat, e1rbul, e1cbul);
				MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 3)
			{
				SetEnemy2(Mat, re2, ce2, 0);
				MoveEnemy2(Mat, re2, ce2);
				SetBulletEnemy2(Mat, e2rbul, e2cbul);
				MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 4 || level == 5)
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				SetBulletEnemy1(Mat, e1rbul, e1cbul);
				MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
				SetEnemy2(Mat, re2, ce2, 0);
				MoveEnemy2(Mat, re2, ce2);
				SetBulletEnemy2(Mat, e2rbul, e2cbul);
				MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}Disp(Mat);
		}
		Design(Mat, Lose); SetHero(Mat, rh, ch, 0); MoveBullet(Mat);
		if (level == 1)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 2)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 3)
		{
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 4 || level == 5)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}Disp(Mat);
	}
}



void Design(char Mat[][135])
{
	int r, c;
	for (r = 0; r < 43; r++)
	{
		for (c = 0; c < 135; c++)
		{
			if (Mat[r][c] != '>')
			{
				Mat[r][c] = ' ';
			}
		}
	}
	for (r = 1; r<43; r++)
	{
		Mat[r][0] = 186;
		Mat[r][134] = 186;
	}
	for (c = 1; c<134; c++)
	{
		Mat[0][c] = 205;
		Mat[42][c] = 205;
	}
	Mat[0][0] = 201; Mat[0][134] = 187;
	Mat[42][0] = 200; Mat[42][134] = 188;
}
void Disp3(char Mat[][135], int &jumbing, int &rh5, int &ch5, int &cb3, int &cb, int &appear)
{
	int r, c;
	system("cls");
	for (int r = 0; r < 43; r++)
	{
		for (int c = 0; c < 135; c++)
		{
			cout << Mat[r][c];
		}
	}
	if (jumbing == 1)
	{
		rh5 -= 3;
		ch5 += 5;
		jumbing = 20;
	}
	if (jumbing == 2)
	{
		rh5++;
		ch5++;
		jumbing = 21;
	}
	if (jumbing == 3)
	{
		//rh5++;
		ch5++;
		jumbing = 22;
		
	}
	//if ( (cb3-8) - cb == 15)
	//{
	//appear=1;
	//}
	cout.flush();
	Sleep(30);
}
void fish1(char Mat[][135], int r1, int c1)
{


	Mat[r1][c1] = '>'; Mat[r1][c1 - 1] = ':'; Mat[r1 - 1][c1 + 1] = '.'; Mat[r1 - 2][c1 + 1] = '.';
	Mat[r1 - 1][c1 - 1] = '\\'; Mat[r1 - 2][c1 - 2] = '\\';
	Mat[r1 - 1][c1 - 2] = '//';
	Mat[r1][c1 - 2] = ')'; Mat[r1][c1 - 3] = '='; Mat[r1][c1 - 4] = '>';
	Mat[r1 + 1][c1 - 2] = '\\'; Mat[r1 + 1][c1 - 1] = '//';
	Mat[r1 + 2][c1 - 2] = '//';

}
void movefish1(char Mat[][135], int &r1, int &c1, int &flag)
{
	c1 += 2;
	if (c1 == 30)
	{
		flag = 1;
	}
}
void dol(char Mat[][135], int r2, int c2)
{
	Mat[r2][c2] = '('; Mat[r2 - 1][c2 - 2] = '.'; Mat[r2 - 2][c2 - 3] = '.'; Mat[r2 - 3][c2 - 2] = '.'; Mat[r2 - 4][c2 - 3] = '.'; Mat[r2 - 5][c2 - 2] = '.'; Mat[r2 - 6][c2 - 3] = '.';
	Mat[r2 - 1][c2 + 1] = '__'; Mat[r2 - 1][c2 + 2] = '__'; Mat[r2 - 1][c2 + 3] = '__';	Mat[r2 - 1][c2 + 4] = '//';
	Mat[r2 - 2][c2 + 5] = '__'; Mat[r2 - 2][c2 + 6] = '-'; Mat[r2 - 3][c2 + 7] = '__'; Mat[r2 - 3][c2 + 8] = '__'; Mat[r2 - 3][c2 + 29] = '-'; Mat[r2 - 3][c2 + 30] = '-'; Mat[r2 - 3][c2 + 31] = '-'; Mat[r2 - 3][c2 + 32] = '-'; Mat[r2 - 3][c2 + 33] = '-'; Mat[r2 - 2][c2 + 37] = '-'; Mat[r2 - 2][c2 + 38] = '-'; Mat[r2 - 2][c2 + 39] = '-';	Mat[r2 - 5][c2 + 21] = '//'; Mat[r2 - 5][c2 + 24] = '|'; Mat[r2 - 6][c2 + 22] = '//'; Mat[r2 - 6][c2 + 24] = '|'; Mat[r2 - 7][c2 + 23] = '//'; Mat[r2 - 7][c2 + 24] = '\\'; Mat[r2 - 4][c2 + 45] = '//';
	Mat[r2 - 3][c2 + 8] = '-'; Mat[r2 - 3][c2 + 9] = '-'; Mat[r2 - 3][c2 + 10] = '-'; Mat[r2 - 3][c2 + 11] = '-'; Mat[r2 - 3][c2 + 12] = '-'; Mat[r2 - 3][c2 + 34] = '__'; Mat[r2 - 3][c2 + 35] = '__'; Mat[r2 - 3][c2 + 36] = '__'; Mat[r2 - 3][c2 + 44] = '//';
	Mat[r2 - 4][c2 + 13] = '__'; Mat[r2 - 4][c2 + 14] = '__'; Mat[r2 - 4][c2 + 15] = '__'; Mat[r2 - 4][c2 + 16] = '__'; Mat[r2 - 4][c2 + 17] = '__'; Mat[r2 - 4][c2 + 18] = '__'; Mat[r2 - 4][c2 + 19] = '__'; Mat[r2 - 4][c2 + 20] = '//'; Mat[r2 - 4][c2 + 24] = '('; Mat[r2 - 4][c2 + 25] = '__'; Mat[r2 - 4][c2 + 26] = '__'; Mat[r2 - 4][c2 + 27] = '__'; Mat[r2 - 4][c2 + 28] = '__'; Mat[r2 - 2][c2 + 40] = '__'; Mat[r2 - 2][c2 + 41] = '__'; Mat[r2 - 2][c2 + 42] = '__'; Mat[r2 - 2][c2 + 43] = '//';
	Mat[r2 - 4][c2 + 46] = '|'; Mat[r2 - 3][c2 + 46] = '|'; Mat[r2 - 2][c2 + 46] = '//'; Mat[r2 - 1][c2 + 46] = '<'; Mat[r2 - 1][c2 + 45] = '-'; Mat[r2][c2 + 46] = '\\'; Mat[r2 + 1][c2 + 47] = '\\'; Mat[r2 + 2][c2 + 47] = '|'; Mat[r2 + 3][c2 + 46] = '\\'; Mat[r2 + 2][c2 + 45] = '\\'; Mat[r2 + 1][c2 + 44] = '\\'; Mat[r2][c2 + 43] = '\\'; Mat[r2 - 1][c2 + 43] = '>';
	///////////////////////////////////////////////////
	Mat[r2][c2 + 1] = '__'; Mat[r2][c2 + 2] = '__'; Mat[r2][c2 + 3] = '__'; Mat[r2][c2 + 4] = '\\'; Mat[r2 - 1][c2 + 6] = 'o'; Mat[r2 + 1][c2 + 5] = '\\'; Mat[r2 + 1][c2 + 6] = '__'; Mat[r2 + 1][c2 + 12] = '|';
	Mat[r2 + 2][c2 + 7] = '-'; Mat[r2 + 2][c2 + 8] = '-'; Mat[r2 + 2][c2 + 9] = '-';
	Mat[r2 + 2][c2 + 10] = '__'; Mat[r2 + 2][c2 + 11] = '__'; Mat[r2 + 2][c2 + 12] = '\\'; Mat[r2 + 1][c2 + 17] = '\\';
	Mat[r2 + 3][c2 + 13] = '\\'; Mat[r2 + 2][c2 + 17] = '|';
	Mat[r2 + 4][c2 + 14] = '\\'; Mat[r2 + 3][c2 + 17] = '|';
	Mat[r2 + 5][c2 + 15] = '\\'; Mat[r2 + 4][c2 + 17] = '|';
	Mat[r2 + 5][c2 + 16] = '__'; Mat[r2 + 5][c2 + 17] = '|';
	Mat[r2 + 2][c2 + 18] = '__'; Mat[r2 + 2][c2 + 19] = '__'; Mat[r2 + 2][c2 + 20] = '__'; Mat[r2 + 2][c2 + 21] = '__'; Mat[r2 + 2][c2 + 22] = '__'; Mat[r2 + 2][c2 + 23] = '__'; Mat[r2 + 2][c2 + 24] = '-'; Mat[r2 + 2][c2 + 25] = '-'; Mat[r2 + 2][c2 + 26] = '-'; Mat[r2 + 2][c2 + 27] = '-'; Mat[r2 + 2][c2 + 28] = '-'; Mat[r2 + 2][c2 + 29] = '-';
	Mat[r2 + 1][c2 + 30] = '__'; Mat[r2 + 1][c2 + 31] = '__'; Mat[r2 + 1][c2 + 32] = '__'; Mat[r2 + 1][c2 + 33] = '__'; Mat[r2 + 1][c2 + 34] = '-'; Mat[r2 + 1][c2 + 35] = '-'; Mat[r2 + 1][c2 + 36] = '-'; Mat[r2 + 1][c2 + 37] = '-';
	Mat[r2][c2 + 38] = '__'; Mat[r2][c2 + 39] = '__'; Mat[r2][c2 + 40] = '__'; Mat[r2][c2 + 41] = '__';

}
void movedol(char Mat[][135], int &r2, int &c2)
{
	c2--;
}
void fish2(char Mat[][135], int r3, int c3)
{
	Mat[r3][c3] = '|'; Mat[r3][c3 + 1] = '\\'; Mat[r3 + 1][c3] = '|'; Mat[r3 + 1][c3 + 1] = '//';
	Mat[r3][c3 + 2] = '//'; Mat[r3 + 1][c3 + 2] = '\\';
	Mat[r3 - 1][c3 + 3] = '__'; Mat[r3 - 1][c3 + 4] = '__'; Mat[r3 - 1][c3 + 5] = '__'; Mat[r3 - 1][c3 + 6] = '__'; Mat[r3][c3 + 7] = '\\';
	Mat[r3 + 1][c3 + 3] = '__'; Mat[r3 + 1][c3 + 4] = '__'; Mat[r3 + 1][c3 + 5] = '__'; Mat[r3 + 1][c3 + 6] = '__'; Mat[r3 + 1][c3 + 7] = '//'; Mat[r3][c3 + 6] = 'o'; Mat[r3][c3 + 8] = '.'; Mat[r3 - 1][c3 + 9] = '.'; Mat[r3 - 2][c3 + 7] = '.';
}
void movefish2(char Mat[][135], int &r3, int &c3)
{
	c3++;
}
void sethero(char Mat[][135], int rh5, int ch5)
{
	Mat[rh5 - 4][ch5 + 16] = 'o'; Mat[rh5 - 3][ch5 + 16] = '|'; Mat[rh5 - 3][ch5 + 17] = '__'; Mat[rh5 - 3][ch5 + 18] = '__';/*Mat[rb-2][cb+16]='|'*/; Mat[rh5 - 2][ch5 + 15] = '//'; Mat[rh5 - 2][ch5 + 17] = '\\';////////////////stick man 
}
void boathero(char Mat[][135], int rb, int cb, int &rh5, int &ch5) /////////////////////////hero boat 
{
	Mat[rb][cb] = '\\'; Mat[rb - 1][cb] = '__'; Mat[rb - 1][cb + 1] = '__'; Mat[rb - 1][cb + 2] = '__'; Mat[rb - 1][cb + 3] = '__'; Mat[rb - 1][cb + 4] = '.'; Mat[rb - 1][cb + 5] = '.'; Mat[rb - 1][cb + 6] = '.'; Mat[rb - 1][cb + 7] = '.';
	Mat[rb - 1][cb + 8] = '-'; Mat[rb - 1][cb + 9] = '-'; Mat[rb - 1][cb + 10] = '-'; Mat[rb - 1][cb + 11] = '-'; Mat[rb - 1][cb + 12] = '|'; Mat[rb - 1][cb + 13] = '-'; Mat[rb - 1][cb + 14] = '-'; Mat[rb - 1][cb + 15] = '-'; Mat[rb - 1][cb + 16] = '-'; Mat[rb - 1][cb + 17] = '//'; Mat[rb][cb + 16] = '//';
	Mat[rb - 1][cb + 12] = '|'; Mat[rb - 2][cb + 12] = '|'; Mat[rb - 3][cb + 12] = '|'; Mat[rb - 3][cb + 11] = '__'; Mat[rb - 3][cb + 10] = '__'; Mat[rb - 3][cb + 9] = '__'; Mat[rb - 3][cb + 8] = '__'; Mat[rb - 3][cb + 7] = '__'; Mat[rb - 3][cb + 6] = '__'; Mat[rb - 4][cb + 12] = '|'; Mat[rb - 5][cb + 12] = '|'; Mat[rb - 6][cb + 12] = '|';
	Mat[rb - 6][cb + 11] = '//'; Mat[rb - 6][cb + 10] = ','; Mat[rb - 5][cb + 9] = '//'; Mat[rb - 5][cb + 8] = ','; Mat[rb - 4][cb + 7] = '//'; Mat[rb - 4][cb + 6] = ','; Mat[rb - 3][cb + 5] = '//';
	Mat[rb - 6][cb + 13] = '\\'; Mat[rb - 5][cb + 14] = '|'; Mat[rb - 5][cb + 13] = '__';
	//Mat[rb-2][cb+16]='|';Mat[rb-2][cb+15]='|';Mat[rb-3][cb+16]='__';Mat[rb-3][cb+15]='__';Mat[rb-3][cb+17]='__';Mat[rb-3][cb+18]='__';Mat[rb-3][cb+19]='__';Mat[rb-4][cb+15]='__';Mat[rb-4][cb+16]='__';Mat[rb-4][cb+17]='__';Mat[rb-4][cb+18]='__';Mat[rb-4][cb+19]='__';
	sethero(Mat, rh5, ch5);
}
void moveboathero(char Mat[][135], int &rb, int &cb, int a, int &rh5, int &ch5, int &jumbing)
{
	if (a == 1)
	{
		cb += 2;
		ch5 += 2;
	}
	if (a == 2)
	{
		cb -= 2;
		ch5 -= 2;
	}
}
void boat2(char Mat[][135], int rb2, int cb2, int &z) /////////////////// enemy boat 
{
	if (z == 0)
	{
		Mat[rb2][cb2] = '__'; Mat[rb2][cb2 + 1] = '__'; Mat[rb2][cb2 + 2] = '__'; Mat[rb2][cb2 + 3] = '//'; Mat[rb2][cb2 - 4] = '\\'; Mat[rb2][cb2 - 3] = '__'; Mat[rb2][cb2 - 2] = '__'; Mat[rb2][cb2 - 1] = '__';
		Mat[rb2 - 1][cb2 - 5] = '\\'; Mat[rb2 - 1][cb2 + 4] = '//'; Mat[rb2 - 1][cb2 - 4] = '"'; Mat[rb2 - 1][cb2 - 3] = '"'; Mat[rb2 - 1][cb2 - 2] = '"'; Mat[rb2 - 1][cb2 - 1] = '"'; Mat[rb2 - 1][cb2] = '"'; Mat[rb2 - 1][cb2 + 1] = '"'; Mat[rb2 - 1][cb2 + 2] = '"'; Mat[rb2 - 1][cb2 + 3] = '"';
		Mat[rb2 - 2][cb2 - 5] = '__'; Mat[rb2 - 2][cb2 - 4] = '__'; Mat[rb2 - 2][cb2 - 3] = '|'; Mat[rb2 - 2][cb2 - 2] = '__'; Mat[rb2 - 2][cb2 - 1] = 'o'; Mat[rb2 - 2][cb2] = '__'; Mat[rb2 - 2][cb2 + 1] = 'o'; Mat[rb2 - 2][cb2 + 2] = '__'; Mat[rb2 - 2][cb2 + 3] = 'o'; Mat[rb2 - 2][cb2 + 4] = '\\'; Mat[rb2 - 2][cb2 + 5] = '__';
		Mat[rb2 - 3][cb2 - 2] = '__'; Mat[rb2 - 3][cb2 - 1] = '__'; Mat[rb2 - 3][cb2] = '['; Mat[rb2 - 3][cb2 + 1] = ']'; Mat[rb2 - 3][cb2 + 2] = '__'; Mat[rb2 - 3][cb2 + 3] = '__';
	}
	else
	{
		Mat[rb2][cb2] = ' '; Mat[rb2][cb2 + 1] = ' '; Mat[rb2][cb2 + 2] = ' '; Mat[rb2][cb2 + 3] = ' '; Mat[rb2][cb2 - 4] = ' '; Mat[rb2][cb2 - 3] = ' '; Mat[rb2][cb2 - 2] = ' '; Mat[rb2][cb2 - 1] = ' ';
		Mat[rb2 - 1][cb2 - 5] = ' '; Mat[rb2 - 1][cb2 + 4] = ' '; Mat[rb2 - 1][cb2 - 4] = ' '; Mat[rb2 - 1][cb2 - 3] = ' '; Mat[rb2 - 1][cb2 - 2] = ' '; Mat[rb2 - 1][cb2 - 1] = ' '; Mat[rb2 - 1][cb2] = ' '; Mat[rb2 - 1][cb2 + 1] = ' '; Mat[rb2 - 1][cb2 + 2] = ' '; Mat[rb2 - 1][cb2 + 3] = ' ';
		Mat[rb2 - 2][cb2 - 5] = ' '; Mat[rb2 - 2][cb2 - 4] = ' '; Mat[rb2 - 2][cb2 - 3] = ' '; Mat[rb2 - 2][cb2 - 2] = ' '; Mat[rb2 - 2][cb2 - 1] = ' '; Mat[rb2 - 2][cb2] = ' '; Mat[rb2 - 2][cb2 + 1] = ' '; Mat[rb2 - 2][cb2 + 2] = ' '; Mat[rb2 - 2][cb2 + 3] = ' '; Mat[rb2 - 2][cb2 + 4] = ' '; Mat[rb2 - 2][cb2 + 5] = ' ';
		Mat[rb2 - 3][cb2 - 2] = ' '; Mat[rb2 - 3][cb2 - 1] = ' '; Mat[rb2 - 3][cb2] = ' '; Mat[rb2 - 3][cb2 + 1] = ' '; Mat[rb2 - 3][cb2 + 2] = ' '; Mat[rb2 - 3][cb2 + 3] = ' ';
	}
}
void moveboat2(char Mat[][135], int &rb2, int &cb2, int &flag2, int &finish1)
{
	cb2 -= 3;
	if (cb2 == 110)
	{
		flag2 = 1;
	}
	if (cb2 == 2)
	{
		finish1 = 1;
	}
}
void boat3(char Mat[][135], int rb3, int cb3) ///////////////////////////boat enemy2 
{
	Mat[rb3][cb3 - 8] = '\\'; Mat[rb3][cb3 + 5] = '//';
	Mat[rb3 - 1][cb3 - 8] = '__'; Mat[rb3 - 1][cb3 - 7] = '__'; Mat[rb3 - 1][cb3 - 6] = '|'; Mat[rb3 - 2][cb3 - 8] = ')'; Mat[rb3 - 2][cb3 - 7] = '__'; Mat[rb3 - 2][cb3 - 6] = '__'; Mat[rb3 - 2][cb3 - 5] = '__'; Mat[rb3 - 2][cb3 - 4] = ')';
	Mat[rb3 - 3][cb3 - 4] = ')'; Mat[rb3 - 3][cb3 - 5] = '__'; Mat[rb3 - 3][cb3 - 6] = '__'; Mat[rb3 - 3][cb3 - 7] = ')';
	Mat[rb3 - 4][cb3 - 5] = '\\'; Mat[rb3 - 4][cb3 - 7] = '//'; Mat[rb3 - 5][cb3 - 6] = '|';
	Mat[rb3 - 1][cb3 - 5] = '__'; Mat[rb3 - 1][cb3 - 4] = '__'; Mat[rb3 - 1][cb3 - 3] = '__'; Mat[rb3 - 1][cb3 - 2] = '__'; Mat[rb3 - 1][cb3 - 1] = '__'; Mat[rb3 - 1][cb3] = '__'; Mat[rb3 - 1][cb3 + 1] = '__'; Mat[rb3 - 1][cb3 + 2] = '__'; Mat[rb3 - 1][cb3 + 3] = '__'; Mat[rb3 - 1][cb3 + 4] = '__'; Mat[rb3 - 1][cb3 + 5] = '__';
}
void moveboat3(char Mat[][135], int &rb3, int &cb3, int &finish2)
{
	cb3 -= 2;
	if (cb3 == 3)
	{
		finish2 = 1;
	}
}
void Design3(char Mat[][135], int r1, int c1, int r2, int c2, int r3, int c3) /////////the sea
{
	int r, c;
	for (r = 0; r<44; r++)
	{
		for (c = 0; c<135; c++)
		{
			Mat[r][c] = ' ';
		}
	}
	///////////////////////////////////////////
	for (r = 25; r<26; r++)
	{
		for (c = 0; c<135; c++)
		{
			Mat[r][c] = '~';
		}
	}
	///////////////////////////////////
	for (r = 1; r<43; r++)
	{
		Mat[r][0] = 186;
		Mat[r][134] = 186;
	}
	for (c = 1; c<134; c++)
	{
		Mat[0][c] = 205;
		Mat[42][c] = 205;
	}
	Mat[0][0] = 201; Mat[0][134] = 187;
	Mat[42][0] = 200; Mat[42][134] = 188;
	Mat[41][5] = ')'; Mat[40][6] = '('; Mat[39][5] = ')'; Mat[38][6] = '('; Mat[37][5] = ')';
}
void setbullets(char Mat[][135], int rbul, int cbul)
{
	Mat[rbul][cbul] = '>';
}
void movebullets(char Mat[][135], int &rbul, int &cbul, int &fbul, int i, int &count, int &appear)
{
	if (fbul == 1)
	{
		if (Mat[rbul][cbul] == ' ' || Mat[rbul][cbul + 1] == '>')
		{
			Mat[rbul][cbul + 1] = ' ';
			Mat[rbul][cbul] = '>';
			cbul += 3;
		}
	}
}
void plane2(char Mat[][135], int rplan, int cplan)
{
	Mat[rplan][cplan + 26] = '_'; Mat[rplan][cplan + 27] = '_';
	Mat[rplan + 1][cplan + 25] = '/'; Mat[rplan + 1][cplan + 27] = '/'; Mat[rplan + 1][cplan + 28] = ']';
	Mat[rplan + 2][cplan + 24] = '/'; Mat[rplan + 2][cplan + 26] = '/'; Mat[rplan + 2][cplan + 28] = ']';
	Mat[rplan + 3][cplan + 6] = ','; Mat[rplan + 3][cplan + 7] = '='; Mat[rplan + 3][cplan + 8] = '='; Mat[rplan + 3][cplan + 9] = '='; Mat[rplan + 3][cplan + 10] = '='; Mat[rplan + 3][cplan + 11] = '='; Mat[rplan + 3][cplan + 12] = '='; Mat[rplan + 3][cplan + 13] = '='; Mat[rplan + 3][cplan + 14] = '='; Mat[rplan + 3][cplan + 15] = '_'; Mat[rplan + 3][cplan + 16] = '_'; Mat[rplan + 3][cplan + 17] = '_'; Mat[rplan + 3][cplan + 18] = '_'; Mat[rplan + 3][cplan + 19] = '_'; Mat[rplan + 3][cplan + 20] = ','; Mat[rplan + 3][cplan + 21] = '.'; Mat[rplan + 3][cplan + 23] = '"'; Mat[rplan + 3][cplan + 25] = '/'; Mat[rplan + 3][cplan + 28] = ']';
	Mat[rplan + 4][cplan + 2] = '_'; Mat[rplan + 4][cplan + 3] = '_'; Mat[rplan + 4][cplan + 4] = '_'; Mat[rplan + 4][cplan + 5] = '/'; Mat[rplan + 4][cplan + 6] = '_'; Mat[rplan + 4][cplan + 7] = '_'; Mat[rplan + 4][cplan + 8] = '_'; Mat[rplan + 4][cplan + 9] = '_'; Mat[rplan + 4][cplan + 10] = '|'; Mat[rplan + 4][cplan + 11] = '_'; Mat[rplan + 4][cplan + 12] = '_'; Mat[rplan + 4][cplan + 13] = '_'; Mat[rplan + 4][cplan + 14] = ')'; Mat[rplan + 4][cplan + 25] = '_'; Mat[rplan + 4][cplan + 26] = '_'; Mat[rplan + 4][cplan + 27] = '`'; Mat[rplan + 4][cplan + 28] = ']';
	Mat[rplan + 5][cplan] = '<'; Mat[rplan + 5][cplan + 1] = '|'; Mat[rplan + 5][cplan + 10] = '|'; Mat[rplan + 5][cplan + 20] = ','; Mat[rplan + 5][cplan + 21] = '.'; Mat[rplan + 5][cplan + 22] = '`'; Mat[rplan + 5][cplan + 22] = '`';
	Mat[rplan + 6][cplan + 2] = '\\'; Mat[rplan + 6][cplan + 10] = '|'; Mat[rplan + 6][cplan + 15] = ','; Mat[rplan + 6][cplan + 16] = '.'; Mat[rplan + 6][cplan + 17] = '`'; Mat[rplan + 6][cplan + 18] = '`';
	Mat[rplan + 7][cplan + 3] = '\\'; Mat[rplan + 7][cplan + 4] = ','; Mat[rplan + 7][cplan + 5] = '_'; Mat[rplan + 7][cplan + 6] = '_'; Mat[rplan + 7][cplan + 7] = '_'; Mat[rplan + 7][cplan + 8] = '_'; Mat[rplan + 7][cplan + 9] = '_'; Mat[rplan + 7][cplan + 10] = '|'; Mat[rplan + 7][cplan + 11] = '_'; Mat[rplan + 7][cplan + 12] = ','; Mat[rplan + 7][cplan + 13] = '.'; Mat[rplan + 7][cplan + 14] = '`'; Mat[rplan + 7][cplan + 15] = '`';
	Mat[rplan + 8][cplan + 4] = '|'; Mat[rplan + 8][cplan + 11] = '|';
	Mat[rplan + 9][cplan + 4] = '-'; Mat[rplan + 9][cplan + 5] = '--'; Mat[rplan + 9][cplan + 6] = '--'; Mat[rplan + 9][cplan + 7] = '--'; Mat[rplan + 9][cplan + 8] = '--'; Mat[rplan + 9][cplan + 9] = '--'; Mat[rplan + 9][cplan + 10] = '--';
}
void moveplane(char Mat[][135], int &rplan, int &cplan, int &position, int &cb)
{
	if (cplan != cb + 17)
	{
		cplan -= 2;

	}
	if (cplan == cb + 17)
	{
		position = 1;
	}
}
void elevator(char Mat[][135], int rplan, int cplan)
{
	Mat[rplan][cplan + 26] = '_'; Mat[rplan][cplan + 27] = '_';
	Mat[rplan + 1][cplan + 25] = '/'; Mat[rplan + 1][cplan + 27] = '/'; Mat[rplan + 1][cplan + 28] = ']';
	Mat[rplan + 2][cplan + 24] = '/'; Mat[rplan + 2][cplan + 26] = '/'; Mat[rplan + 2][cplan + 28] = ']';
	Mat[rplan + 3][cplan + 6] = ','; Mat[rplan + 3][cplan + 7] = '='; Mat[rplan + 3][cplan + 8] = '='; Mat[rplan + 3][cplan + 9] = '='; Mat[rplan + 3][cplan + 10] = '='; Mat[rplan + 3][cplan + 11] = '='; Mat[rplan + 3][cplan + 12] = '='; Mat[rplan + 3][cplan + 13] = '='; Mat[rplan + 3][cplan + 14] = '='; Mat[rplan + 3][cplan + 15] = '_'; Mat[rplan + 3][cplan + 16] = '_'; Mat[rplan + 3][cplan + 17] = '_'; Mat[rplan + 3][cplan + 18] = '_'; Mat[rplan + 3][cplan + 19] = '_'; Mat[rplan + 3][cplan + 20] = ','; Mat[rplan + 3][cplan + 21] = '.'; Mat[rplan + 3][cplan + 23] = '"'; Mat[rplan + 3][cplan + 25] = '/'; Mat[rplan + 3][cplan + 28] = ']';
	Mat[rplan + 4][cplan + 2] = '_'; Mat[rplan + 4][cplan + 3] = '_'; Mat[rplan + 4][cplan + 4] = '_'; Mat[rplan + 4][cplan + 5] = '/'; Mat[rplan + 4][cplan + 6] = '_'; Mat[rplan + 4][cplan + 7] = '_'; Mat[rplan + 4][cplan + 8] = '_'; Mat[rplan + 4][cplan + 9] = '_'; Mat[rplan + 4][cplan + 10] = '|'; Mat[rplan + 4][cplan + 11] = '_'; Mat[rplan + 4][cplan + 12] = '_'; Mat[rplan + 4][cplan + 13] = '_'; Mat[rplan + 4][cplan + 14] = ')'; Mat[rplan + 4][cplan + 25] = '_'; Mat[rplan + 4][cplan + 26] = '_'; Mat[rplan + 4][cplan + 27] = '`'; Mat[rplan + 4][cplan + 28] = ']';
	Mat[rplan + 5][cplan] = '<'; Mat[rplan + 5][cplan + 1] = '|'; Mat[rplan + 5][cplan + 10] = '|'; Mat[rplan + 5][cplan + 20] = ','; Mat[rplan + 5][cplan + 21] = '.'; Mat[rplan + 5][cplan + 22] = '`'; Mat[rplan + 5][cplan + 22] = '`';
	Mat[rplan + 6][cplan + 2] = '\\'; Mat[rplan + 6][cplan + 10] = '|'; Mat[rplan + 6][cplan + 15] = ','; Mat[rplan + 6][cplan + 16] = '.'; Mat[rplan + 6][cplan + 17] = '`'; Mat[rplan + 6][cplan + 18] = '`';
	Mat[rplan + 7][cplan + 3] = '\\'; Mat[rplan + 7][cplan + 4] = ','; Mat[rplan + 7][cplan + 5] = '_'; Mat[rplan + 7][cplan + 6] = '_'; Mat[rplan + 7][cplan + 7] = '_'; Mat[rplan + 7][cplan + 8] = '_'; Mat[rplan + 7][cplan + 9] = '_'; Mat[rplan + 7][cplan + 10] = '|'; Mat[rplan + 7][cplan + 11] = '_'; Mat[rplan + 7][cplan + 12] = ','; Mat[rplan + 7][cplan + 13] = '.'; Mat[rplan + 7][cplan + 14] = '`'; Mat[rplan + 7][cplan + 15] = '`';
	Mat[rplan + 8][cplan + 4] = '|'; Mat[rplan + 8][cplan + 11] = '|';
	//Mat[rplan + 9][cplan + 4]='-';Mat[rplan + 9][cplan + 5]='--';Mat[rplan+9][cplan+6]='--';Mat[rplan+9][cplan+7]='--';Mat[rplan+9][cplan+8]='--';Mat[rplan+9][cplan+9]='--';Mat[rplan+9][cplan+10]='--';
	Mat[rplan + 9][cplan + 4] = '|'; Mat[rplan + 10][cplan + 4] = '|'; Mat[rplan + 11][cplan + 4] = '|'; Mat[rplan + 12][cplan + 4] = '|'; Mat[rplan + 13][cplan + 4] = '|'; Mat[rplan + 14][cplan + 4] = '|'; Mat[rplan + 15][cplan + 4] = '|'; Mat[rplan + 16][cplan + 4] = '|'; Mat[rplan + 17][cplan + 4] = '|'; Mat[rplan + 18][cplan + 4] = '|'; Mat[rplan + 19][cplan + 4] = '|';
	Mat[rplan + 9][cplan + 11] = '|'; Mat[rplan + 10][cplan + 11] = '|'; Mat[rplan + 11][cplan + 11] = '|'; Mat[rplan + 12][cplan + 11] = '|'; Mat[rplan + 13][cplan + 11] = '|'; Mat[rplan + 14][cplan + 11] = '|'; Mat[rplan + 15][cplan + 11] = '|'; Mat[rplan + 16][cplan + 11] = '|'; Mat[rplan + 17][cplan + 11] = '|'; Mat[rplan + 18][cplan + 11] = '|'; Mat[rplan + 19][cplan + 11] = '|';
	Mat[rplan + 19][cplan + 5] = '__'; Mat[rplan + 19][cplan + 6] = '__'; Mat[rplan + 19][cplan + 7] = '__'; Mat[rplan + 19][cplan + 8] = '__'; Mat[rplan + 19][cplan + 9] = '__'; Mat[rplan + 19][cplan + 10] = '__';
}
void lose(char Mat[][135])
{
	cout << " _______  _______  __   __  _______    _______  __   __  _______  ______   " << endl;

	cout << "|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  " << endl;
	cout << "|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  " << endl;
	cout << "|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ " << endl;
	cout << "|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |" << endl;
	cout << "|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |" << endl;
	cout << "|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|" << endl;
}
void win(char Mat[][135])
{
	cout << " __   __  _______  __   __    _     _  ___   __    _ " << endl;
	cout << "|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |" << endl;
	cout << "|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |" << endl;
	cout << "|       ||  | |  ||  |_|  |  |       ||   | |       |" << endl;
	cout << "|_     _||  |_|  ||       |  |       ||   | |  _    |" << endl;
	cout << "  |   |  |       ||       |  |   _   ||   | | | |   |" << endl;
	cout << "  |___|  |_______||_______|  |__| |__||___| |_|  |__|" << endl;
}
int main()
{
	int Lose = 4, Win = 0;
	char Mat[44][135];
	int rh = 27, ch = 8;//hero
	int re2 = 1, ce2 = 107;//enemy2 plane
	int re1 = 43, ce1 = 135;//enemy1 ground

							//tflag: for the transformation
	int tflag = 1, level = 1;

	int rbul, cbul, e1rbul = re1 - 12, e1cbul = ce1 - 8, e2rbul = re2 + 8, e2cbul = ce2 + 6;
	while (Lose >= 0 && Win == 0)
	{
		while (!_kbhit() && Lose >= 0 && Win == 0)
		{
			Design(Mat, Lose);
			if (tflag % 2 != 0)
			{
				SetHero(Mat, rh, ch, 0);
				MoveBullet(Mat);
			}
			if (tflag % 2 == 0)
			{
				SetHero2(Mat, rh, ch, 0);
				MoveBullet(Mat);
			}
			if (level == 1)//enemy1 attack moving only
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 2)//enemy1 attack with bullets
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				SetBulletEnemy1(Mat, e1rbul, e1cbul);
				MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 3)
			{
				SetEnemy2(Mat, re2, ce2, 0);
				MoveEnemy2(Mat, re2, ce2);
				SetBulletEnemy2(Mat, e2rbul, e2cbul);
				MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level == 4 || level == 5)
			{
				SetEnemy1(Mat, re1, ce1);
				MoveEnemy1(Mat, re1, ce1);
				SetBulletEnemy1(Mat, e1rbul, e1cbul);
				MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
				SetEnemy2(Mat, re2, ce2, 0);
				MoveEnemy2(Mat, re2, ce2);
				SetBulletEnemy2(Mat, e2rbul, e2cbul);
				MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
				ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
				ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
			}
			if (level>5) { Win = 1; break; }
			if (Lose<0 || Win == 1) { break; }
			Disp(Mat);
		}
		if (level>5) { Win = 1; break; }
		if (Lose<0 || Win == 1) { break; }
		Design(Mat, Lose);
		MoveBullet(Mat);

		char q = _getch();
		if (q == 'w' || q == 'd' || q == 'a' || q == 's')
		{
			if (tflag % 2 != 0)
			{
				MoveHero(Mat, q, rh, ch);
			}
			if (tflag % 2 == 0)
			{
				MoveHero2(Mat, q, rh, ch);
			}
		}
		if (q == 'j')
		{
			if (tflag % 2 != 0)
			{
				SetHero(Mat, rh, ch, 0);
				rbul = rh + 5, cbul = ch + 13;
				SetBullet(Mat, rbul, cbul);
			}
			if (tflag % 2 == 0)
			{
				SetHero2(Mat, rh, ch, 0);
				rbul = rh + 11, cbul = ch + 34;
				SetBullet(Mat, rbul, cbul);
			}
		}
		if (level == 1)//enemy1 attack empty handed
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 2)//enemy1 attack with bullets
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 3)
		{
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (level == 4 || level == 5)
		{
			SetEnemy1(Mat, re1, ce1);
			MoveEnemy1(Mat, re1, ce1);
			SetBulletEnemy1(Mat, e1rbul, e1cbul);
			MoveBulletEnemy1(Mat, e1rbul, e1cbul, ce1);
			SetEnemy2(Mat, re2, ce2, 0);
			MoveEnemy2(Mat, re2, ce2);
			SetBulletEnemy2(Mat, e2rbul, e2cbul);
			MoveBulletEnemy2(Mat, e2rbul, e2cbul, ce2);
			ClashWithEnemy(Mat, tflag, level, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
			ClashWithHero(Mat, Lose, tflag, rh, ch, e1rbul, e1cbul, e2rbul, e2cbul, re1, ce1, re2, ce2);
		}
		if (q == 'k')
		{
			tflag++;
			Trans(Mat, rh, ch, tflag, level, Lose, re1, ce1, re2, ce2, e1rbul, e1cbul, e2rbul, e2cbul);
		}
		Disp(Mat);
	}
	if (Lose <= 0)
	{
		Design2(Mat, Lose);
		lose(Mat);
		//Disp(Mat);
	}
	if (Win >= 1)
	{
		char Mat[44][135];
		int lol = 0;
		int r1 = 33, c1 = 10;
		int r2 = 35, c2 = 80;
		int r3 = 33, c3 = 40;
		int rb = 24, cb = 5;
		int rb2 = 24, cb2 = 125;
		int rh5 = 24, ch5 = 4;
		int flag = 0, flag2 = 0;
		int rb3 = 24, cb3 = 135;
		int rbul = 21, cbul = 25;
		int rowbul[2000], colbul[2000], fbul[2000], count = 0, j;
		int finish1 = 0, finish2 = 0;
		int rplan = 1, cplan = 100;
		int postion = 0;
		int pos1 = 0, pos2 = 0;
		int jumbing = 0;
		int z = 0;
		int appear = 0;

		int o = cb, l = cb3 - 8;
		for (int m = 0; m<2000; m++)
		{
			fbul[m] = 0;
		}
		while (1)
		{
			while (!_kbhit())
			{
				Design3(Mat, r1, c1, r2, c2, r3, c3);
				fish1(Mat, r1, c1);
				movefish1(Mat, r1, c1, flag);
				//system("pause");
				if (flag == 1)
				{
					c1 = 10;

				}
				movefish1(Mat, r1, c1, flag);
				dol(Mat, r2, c2);
				if (postion == 1)
				{
					Disp3(Mat, jumbing, rh5, ch5, cb3, cb, appear);
				}
				fish2(Mat, r3, c3);
				boathero(Mat, rb, cb, rh5, ch5);   /////////////////// heroboat
				boat2(Mat, rb2, cb2, z);    /////////////////// enemyboat1
				moveboat2(Mat, rb2, cb2, flag2, finish1);
				if (finish1 == 1) ////////////////////////// flag to back the boat in the same row 
				{
					cb2 = 125;
					rb2 = 24;
					finish1 = 0;
				}
				//////////////////////////////////////// flag  appear another boat 
				if (flag2 == 1)
				{
					boat3(Mat, rb3, cb3); ///////////////// enemyboat2
					moveboat3(Mat, rb3, cb3, finish2);
					if (finish2 == 1)
					{
						rb3 = 24, cb3 = 135;
						finish2 = 0;
					}
				}
				////////////////////////////////////////////////// bullets
				for (j = 0; j<count; j++)
				{
					if (fbul[j] == 1)
					{
						movebullets(Mat, rowbul[j], colbul[j], fbul[j], j, count, appear);
					}
				}
				//if (appear == 1)
				//{
					//////////////////////////////////////////////// the plane
					plane2(Mat, rplan, cplan);
					//elevator(Mat,rplan,cplan);
					moveplane(Mat, rplan, cplan, postion, cb);
					if (postion == 1)
					{
						elevator(Mat, rplan, cplan);
					}
					///////////////////////////////////////////////    jumb0
				//}
				if (jumbing == 20)
				{
					jumbing = 2;
				}
				if (jumbing == 21)
				{
					jumbing = 3;
				}
				if (jumbing == 22)
				{
					lol = 1;
					jumbing = 0;
				}
				//////////////////////////////////////////// 
				Disp3(Mat, jumbing, rh5, ch5, cb3, cb, appear);
				if (lol == 1)
				{
					win(Mat);
					break;
				}
			}
			char z = _getch();
			int a;
			if (z == 'd')
			{
				moveboathero(Mat, rb, cb, 1, rh5, ch5, jumbing);
			}
			if (z == 'a')
			{
				moveboathero(Mat, rb, cb, 2, rh5, ch5, jumbing);
				pos2 = cb;
			}
			if (z == 'f')
			{
				cbul = cb + 19;
				rowbul[j] = rbul;
				colbul[j] = cbul;
				fbul[j] = 1;
				count++;
				setbullets(Mat, rbul, cbul);
				movebullets(Mat, rowbul[j], colbul[j], fbul[j], j, count, appear);
				j++;
			}
			if (z == 'j')
			{
				rh5--;
				ch5++;
				jumbing = 1;

			}
		}
	}
	return 0;
}