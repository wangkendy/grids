/*
 * Source: http://poj.grids.cn/practice/3723
 * Description: chess game
 * tag: recursion
 * author: wangkendy (wkendy@gmail.com)
 *
 */
#include <iostream>
#include <vector>
using namespace std;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void paint(vector<vector<char> > &board, int i, int j)
{
    board[i][j] = 0;
    for (int k = 0; k < 4; k++) {   // four directions
        int tempi = i + di[k];
        int tempj = j + dj[k];
        int size = board.size();
        if (tempi >= 0 && tempi < size &&
            tempj >= 0 && tempj < size &&
            board[tempi][tempj] != 0) {
            if (board[tempi][tempj] == '.') {
                paint(board, tempi, tempj);
            }
            board[i][j] = board[tempi][tempj];
            return;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<char> > board(N, vector<char>(N));
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < line.size(); j++)
            board[i][j] = line[j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (board[i][j] == '.')
                paint(board, i, j);
    }
    int black = 0;
    int white = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (board[i][j] == 'B')
                black++;
            else
                white++;
    }
    cout << black << ' ' << white << endl;
    return 0;
        
}
