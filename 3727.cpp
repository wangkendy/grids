/*
 * Source: http://poj.grids.cn/practice/3727.cpp
 * Description: peanut
 * tag: dynamic programming
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int T;
    int R, C;
    cin >> T;
    while (T--) {
        cin >> R >> C;
        vvi field = vvi(R, vi(C, 0));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> field[i][j];
        for (int c = 1; c < C; c++)
            field[0][c] += field[0][c-1];
        for (int r = 1; r < R; r++)
            field[r][0] += field[r-1][0];

        for (int r = 1; r < R; r++)
            for (int c = 1; c < C; c++)
                field[r][c] += max(field[r][c-1], field[r-1][c]);

        cout << field[R-1][C-1] << endl;
    }
    return 0;
}
