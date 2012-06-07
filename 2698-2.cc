/*
 * Source: http://poj.grids.cn/practice/1664/
 * Description: Eight Queen Problem
 * tag: recursion
 *
 */
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void clean_board(vvi& board)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = 0;
}

void set_board(vvi& board, int row, int col)
{
	int i = row - 1;
	int j = col - 1 ;

	//left up
	while (i >= 0 && j >= 0) board[i--][j--] = 2;

	i = row - 1;
	j = col + 1;
	//right up
	while (i >= 0 && j < 8) board[i--][j++] = 2;

	i = row + 1;
	j = col - 1;
	// left bottom
	while (i < 8 && j >= 0) board[i++][j--] = 2;

	i = row + 1;
	j = col + 1;
	//right bottom
	while (i < 8 && j < 8) board[i++][j++] = 2;
}

void print_board(vvi& board)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 1)
				cout << "1 ";
			else cout << "0 ";
		}
	}
}

void eight_queen(vvi& board, int row)
{
	for (int col = 0; col < 8; col++) {
		if (board[row][col] == 0) {
			board[row][col] = 1;
			set_board(board, row, col);

			if (col == 8 - 1) {
				print_board(board);
			} else {
				eight_queen(board, row + 1);
			}
		}
	}
}

int main()
{
	vvi board(8, vi(8,0));
	eight_queen(board, 0);
	return 0;
}
