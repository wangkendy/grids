/*
 * Source: http://poj.grids.cn/practice/3717
 * Description: Ant move
 * tag: dynamic programming
 *
 */
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int> > table(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        table[i][0] = 1;
    for (int i = 0; i < n; i++)
        table[0][i] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            table[i][j] = table[i][j-1] + table[i-1][j];

    cout << table[m-1][n-1] << endl;
    return 0;
}

