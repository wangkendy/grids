/*
 * Source: http://poj.grids.cn/practice/2251
 * Description: 3D maze
 * tag: Bread First Search (BFS)
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

struct Index3D {
    Index3D(int ll, int rr, int cc):
        l(ll), r(rr), c(cc) {}
    int l;
    int r;
    int c;
};

int dl[] = {0, 0, 0, 0, -1, 1};
int dr[] = {0, 1, 0, -1, 0, 0};
int dc[] = {1, 0, -1, 0, 0, 0};

int try_escape(vvvc &dungeon, int l, int r, int c, int el, int er, int ec)
{
    int L = dungeon.size();
    int R = dungeon[0].size();
    int C = dungeon[0][0].size();
    int step = 1;
    queue<Index3D> q;
    queue<Index3D> nextq;
    vc visited = vc(L*R*C, 0);

    q.push(Index3D(l, r, c));
    
    visited[l * R * C + r * C + c] = 1;

    int tmpl, tmpr, tmpc;
    while (!q.empty()) {
        Index3D cur = q.front();
        l = cur.l;
        r = cur.r;
        c = cur.c;
        q.pop();
        for (int i = 0;  i < 6; i++) {
            tmpl = l + dl[i];
            tmpr = r + dr[i];
            tmpc = c + dc[i];
            if (tmpl >= 0 && tmpl < L &&
                tmpr >= 0 && tmpr < R &&
                tmpc >= 0 && tmpc < C &&
                dungeon[tmpl][tmpr][tmpc] == '.') {
                int ind = tmpl * R * C + tmpr * C + tmpc;
                if (visited[ind] == 0) {
                    if (tmpl == el && tmpr == er && tmpc == ec)
                        return step;
                    visited[ind] = 1;
                    nextq.push(Index3D(tmpl, tmpr, tmpc));
                }
            }
        }
        if (q.empty()) {
            if (!nextq.empty()) {
                step++;
                while (!nextq.empty()) {
                    q.push(nextq.front());
                    nextq.pop();
                }
            }
        }
    }
    return 0;
}

int main()
{
    int L, R, C;
    cin >> L >> R >> C;
    while (L != 0) {
        vvvc dungeon = vvvc(L, vvc(R, vc(C, 0)));
        string row;
        int sl, sr, sc;
        int el, er, ec;
        for (int l = 0; l < L; l++) {
            for (int r = 0; r < R; r++) {
                cin >> row;
                for (int c = 0; c < C; c++) {
                    dungeon[l][r][c] = row[c];
                    if (row[c] == 'S') {
                        sl = l;
                        sr = r;
                        sc = c;
                    } else if (row[c] == 'E') {
                        dungeon[l][r][c] = '.';
                        el = l;
                        er = r;
                        ec = c;
                    }

                }
            }
        }
        int step = 0;
        step = try_escape(dungeon, sl, sr, sc, el, er, ec);
        if (step != 0) {
            cout << "Escaped in " << step <<" minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }

        cin >> L >> R >> C;
    }
    return 0;
}

