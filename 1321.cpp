/*
 * Source: http://poj.grids.cn/practice/1321
 * Description: chess board
 * tag: recursion, dfs
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int count = 0;

int setable(vvc& board, int r, int c)
{
    for (int j = 0; j < board.size(); j++)
        if (board[r][j] == 1)
            return 0;

    for (int i = 0; i < board.size(); i++)
        if (board[i][c] == 1)
            return 0;
    return 1;
}

void try_put(vvc& board, int r, int c, int step, int k)
{
    if (step == k) {
        count++;
        return;
    }
    int N = board.size();
    board[r][c] = 1;
    for (int i = r + 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '#' && setable(board, i, j)) {
                try_put(board, i, j, step+1, k);
            }
        }
    }
    board[r][c] = '#';
}

int main()
{
    int N, k;
    cin >> N >> k;
    while (N != -1) {
        vvc board = vvc(N, vc(N, 0));
        string row;
        for (int r = 0; r < N; r++) {
            cin >> row;
            for (int c = 0; c < N; c++)
                board[r][c] = row[c];
        }
        count = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] == '#') {
                    try_put(board, r, c, 1, k);
                    board[r][c] = '.';
                }
            }
        }
        cout << count << endl;
        cin >> N >> k;
    }
    return 0;
}
