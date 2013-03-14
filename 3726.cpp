/*
 * Source: http://poj.grids.cn/practice/3726/
 * Description: maze
 * tag: recursion
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int min_step = 0x7fffffff;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void find_path(vvc &maze, int i, int j, int step)
{
    if (maze[i][j] == '*') {
        if (step < min_step)
            min_step = step;
        return;
    }
    if (step >= min_step) return;

    int maxi = maze.size();
    int maxj = maze[i].size();
    int tmpi, tmpj;
    char tmp;

    tmp = maze[i][j];
    maze[i][j] = 0;
    for (int k = 0; k < 4; k++) {   // four directions
        tmpi = i + di[k];
        tmpj = j + dj[k];
        if (tmpi >= 0 && tmpi < maxi &&
            tmpj >= 0 && tmpj < maxj &&
            maze[tmpi][tmpj] != 0 &&
            maze[tmpi][tmpj] != '#') {
            find_path(maze, tmpi, tmpj, step+1);
        }
    }
    maze[i][j] = tmp;
}

int main()
{
    int m, n;
    string line;
    cin >> m >> n;
    while (m != 0 && n != 0) {
        vvc maze = vvc(m, vc(n, 0));
        int starti, startj;
        for (int i = 0; i < m; i++) {
            cin >> line;
            for (int j = 0; j < n; j++) {
                maze[i][j] = line[j];
                if (line[j] == '@') {
                    starti = i;
                    startj = j;
                }
            }
        }
        min_step = 0x7fffffff;
        find_path(maze, starti, startj, 0); 
        if (min_step != 0x7fffffff)
            cout << min_step << endl;
        else
            cout << -1 << endl;

        cin >> m >> n;
    }
    return 0;
}   
