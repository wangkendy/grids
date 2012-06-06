/*
 * source: http://poj.grids.cn/practice/2802
 * tag: recursion
 *
 */
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
	int col, row;
	cin >> col >> row;
	while (col + row) {
		vvi board(row + 2, v(col + 2, 0));
		string input;
		for (int i = 1; i <= row; i++) {
			cin >> input;
			for (int j = 1; j <= col; j++) {
				
			}
		}
	}
	return 0;
}
