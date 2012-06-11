/*
 * Source: http://poj.grids.cn/practice/2815/
 * Description: Castle Problem
 * Tag: recursion
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void mark_castle(const vvi& castle, vvi& mark, int i, int j, int tag)
{
	// west 1; north 2; east 4; south 8;
	unsigned int pos = 1;
	mark[i][j] = tag;
	for (pos = 1; pos <= 8; pos <<= 1){
		if ((castle[i][j] & pos) == 0) {
			switch (pos) {
				case 1: 
					if (mark[i][j-1] == 0)
						mark_castle(castle, mark, i, j-1, tag);
					break;
				case 2: 
					if (mark[i-1][j] == 0)
						mark_castle(castle, mark, i-1, j, tag);
					break;
				case 4:
					if (mark[i][j+1] == 0)
						mark_castle(castle, mark, i, j+1, tag);
					break;
				case 8:
					if (mark[i+1][j] == 0)
						mark_castle(castle, mark, i+1, j, tag);
					break;
			}
		}
	}

}

int main()
{
	int row, col;
	int tag = 1;
	cin >> row >> col;
	vvi castle(row, vi(col));
	vvi mark(row, vi(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> castle[i][j];
			mark[i][j] = 0;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mark[i][j] == 0) {
				mark_castle(castle, mark, i, j, tag);
				tag++;
			}
		}
	}

	vi tag_count(tag, 0);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			tag_count[mark[i][j]]++;
		}
	}
	cout << tag-1 << endl;
	cout << *max_element(tag_count.begin(), tag_count.end()) << endl;

	return 0;
}
