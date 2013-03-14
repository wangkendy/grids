/*
 * Source: http://poj.grids.cn/practice/1132
 * Description: bitmap
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int dx[26] = {0};
int dy[26] = {0};

int bx[26] = {0};
int by[26] = {0};

int main()
{
    int T;
    int x, y;
    string dir;

    dx['E'-'A'] = 1;
    dy['E'-'A'] = 0;

    dx['N'-'A'] = 0;
    dy['N'-'A'] = -1;

    dx['W'-'A'] = -1;
    dy['W'-'A'] = 0;

    dx['S'-'A'] = 0;
    dy['S'-'A'] = 1;
    
    bx['E'-'A'] = 0;
    by['E'-'A'] = -1;

    bx['N'-'A'] = 0;
    by['N'-'A'] = 0;

    bx['W'-'A'] = -1;
    by['W'-'A'] = 0;

    bx['S'-'A'] = -1;
    by['S'-'A'] = -1;

    cin >> T;
    int d;
    for (int t = 1; t <=T; t++) {
        vvc bitmap(32, vc(32, '.'));
        cin >> x >> y;
        y = 32 - y;
        cin >> dir;
        for (int i = 0; dir[i] != '.'; i++) {
             d = dir[i] - 'A';
             bitmap[x + bx[d]][y + by[d]] = '#';
             x += dx[d];
             y += dy[d];
        }
        cout << "Bitmap #" << t << endl;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                cout << bitmap[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
