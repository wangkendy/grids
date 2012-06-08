/*
 * Source: http://poj.grids.cn/practice/2754
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

void set_board(vvi& board, int row, int col, int val)
{
	int i;
	int j;

	for (i = 0; i < 8; i++) {
		board[row][i] += val;
		board[i][col] += val;
	}

	i = row - 1;
	j = col - 1;
	//left up
	while (i >= 0 && j >= 0) board[i--][j--] += val;

	i = row - 1;
	j = col + 1;
	//right up
	while (i >= 0 && j < 8) board[i--][j++] += val;

	i = row + 1;
	j = col - 1;
	// left bottom
	while (i < 8 && j >= 0) board[i++][j--] += val;

	i = row + 1;
	j = col + 1;
	//right bottom
	while (i < 8 && j < 8) board[i++][j++] += val;
}

void control_board(vvi& board, int row, int col)
{
	set_board(board, row, col, 2);
}

void clean_board(vvi& board, int row, int col)
{
	set_board(board, row, col, -2);
}

void print_board(vvi& board)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			/*
			if (board[i][j] == 1)
				cout << "1 ";
			else cout << "0 ";
			*/
			cout << (board[j][i] & 1) << " ";
		}
		cout << endl;
	}
}

void eight_queen(vvi& board, vi& result, vi& per, int row)
{
	static int count = 0;
	if (row == 8) {
		int res = 0;
		count++;
		for (int i = 0; i < 8; i++)
			res = res * 10 + per[i];
		result[count] = res;
		return;
	}
	for (int col = 0; col < 8; col++) {
		if (board[row][col] == 0) {
			per[row] = col + 1;
			control_board(board, row, col);
			board[row][col] = 1;

			eight_queen(board, result, per, row + 1);
			clean_board(board, row, col);
			board[row][col] = 0;
		}
	}
}

int main()
{
	vvi board(8, vi(8,0));
	vi result(93);
	vi per(8,0);
	eight_queen(board, result, per, 0);
	int N, No;
	cin >> N;
	while (N--) {
		cin >> No;
		cout << result[No] << endl;
	}
	return 0;
}
