/*
 * Source: http://poj.grids.cn/practice/3726/
 * Description: maze
 * tag: Bread First Search (BFS)
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;

int min_step = 0x7fffffff;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void bfs(vvc &maze, int m, int n, int i, int j, vi &parent)
{
    queue<pair<int,int> > q;
    vi visited = vi(m * n, 0);
    int tmpi, tmpj;

    q.push(make_pair(i, j));
    visited[i * n + j] = 1;
    while (!q.empty()) {
        pair<int, int> u = q.front();
        i = u.first;
        j = u.second;
        int index = i * n + j;
        q.pop();
        for (int k = 0; k < 4; k++) {   // four directions
            tmpi = i + di[k];
            tmpj = j + dj[k];
            int idx = tmpi * n + tmpj;
            if (tmpi >= 0 && tmpi < m &&
                tmpj >= 0 && tmpj < n &&
                maze[tmpi][tmpj] != '#' &&
                visited[idx] == 0 ) {
                visited[idx] = 1;
                parent[idx] = index;
                q.push(make_pair(tmpi, tmpj));
            }
        }
    }
}

int main()
{
    int m, n;
    string line;
    cin >> m >> n;
    while (m != 0 && n != 0) {
        vvc maze = vvc(m, vc(n, 0));
        vi parent = vi(m * n, -1);
        int starti, startj;
        int endi, endj;
        for (int i = 0; i < m; i++) {
            cin >> line;
            for (int j = 0; j < n; j++) {
                maze[i][j] = line[j];
                if (line[j] == '@') {
                    starti = i;
                    startj = j;
                } else if (line[j] == '*') {
                    endi = i;
                    endj = j;
                }
            }
        }
        bfs(maze, m, n, starti, startj, parent);
        int start = starti * n + startj;
        int end = endi * n + endj;
        if (parent[end] == -1)
            cout << -1 << endl;
        else {
            int step = 1;
            while (parent[end] != start) {
                step++;
                end = parent[end];
            }
            cout << step << endl;
        }
        cin >> m >> n;
    }
    return 0;
}   
