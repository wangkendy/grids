/*
*source: http://poj.grids.cn/practice/2816/
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int mark_floor(const vector<string>& floor, vvi& mark, int i, int j, int row, int col)
{
	mark[i][j] = 1;
	if (j - 1 >=0 && floor[i][j-1] == '.' && mark[i][j-1] != 1)//left
		mark_floor(floor, mark, i, j-1, row, col);

	if (j + 1 < col && floor[i][j+1] == '.' && mark[i][j+1] != 1) //right
		mark_floor(floor, mark, i, j+1, row, col);

	if (i - 1 >=0 && floor[i-1][j] == '.' && mark[i-1][j] != 1)// front
		mark_floor(floor, mark, i-1, j, row, col);

	if (i + 1 < row && floor[i+1][j] == '.' && mark[i+1][j] != 1)//back
		mark_floor(floor, mark, i+1, j, row, col);
}

int main()
{
	int col, row;
	char ch;
	cin >> col >> row;
	while (col + row) {
		int i, j;
		vector<string> floor(row, string(col, '0'));
		vvi mark(row, vi(col,0));
		for (int k = 0; k < row; k++) {
			cin >> floor[k];
			if (floor[k].find('@') != string::npos) {
				i = k;
				j = floor[k].find('@');
			}
		}
		
		mark_floor(floor, mark, i, j, row, col);
		int result = 0;
		for (int i = 0; i < row; i++)
			result += accumulate(mark[i].begin(), mark[i].end(), 0);
		cout << result << endl;
		cin >> col >> row;
	}
	return 0;
}
