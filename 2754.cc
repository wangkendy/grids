/*
 * Source: http://poj.grids.cn/practice/2754/
 * Description: Eight Queen Problem
 * Tag: permutation
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void set_board(vvi& board, int i, int j)
{
	for (int k = 0; k < 8; k++) {
		board[i][k] = 1;
		board[k][j] = 1;
	}

	int m = i;
	int n = j;
	while (m >=0 && n >=0)
		board[m--][n--] = 1;//left up

	m = i;
	n = j;
	while (m >= 0 && n < 8)
		board[m--][n++] = 1; //right up

	m = i;
	n = j;
	while (m < 8 && n >= 0)
		board[m++][n--] = 1;

	m = i;
	n = j;
	while (m < 8 && n < 8)
		board[m++][n++] = 1;
}

void clean_board(vvi& board)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = 0;
}

void cal_res(vi& result)
{
	int count = 0;
	vi per(8);
	vvi board(8, vi(8, 0));
	for (int i = 0; i < 8; i++)
		per[i] = i+1;

	do {
		clean_board(board);
		int i;
		for(i = 0; i < 8; i++) {
			int j = per[i] - 1;
			if (board[i][j] != 1) {
				set_board(board, i, j);
			} else break;
		}
		if (i == 8) {
			count++;
			for (int k = 0; k < 8; k++)
				result[count] = result[count] * 10 + per[k];
		}
	} while (next_permutation(per.begin(), per.end()));
}

int main()
{
	int N, No;
	vi result(93, 0);
	cal_res(result);
	cin >> N;
	while (N--) {
		cin >> No;
		cout << result[No] << endl;
	}
	return 0;
}
