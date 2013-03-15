/*
 * Source: http://poj.grids.cn/practice/1789
 * Description: truck history
 * tag: minimum spanning tree
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

const int MAXDIS = 8;

int calc_distance(string &code1, string &code2)
{
    int dis = 0;
    for (int i =0; i < 7; i++)
        if (code1[i] != code2[i])
            dis++;
    return dis;
}

void init_graph(vvc &graph, vector<string> &trucks, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && graph[i][j] == MAXDIS) {
                graph[i][j] = calc_distance(trucks[i], trucks[j]);
                graph[j][j] = graph[i][j];
            }
}

void prim(vvc &graph, int start, vector<int> &distance, int N)
{
    vector<bool> in_tree(N, false);
    for (int i = 0; i < N; i++)
        distance[i] = MAXDIS;
    int v = start;
    int dist;
    distance[start] = 0;
    while (!in_tree[v]) {
        in_tree[v] = true;
        for (int i = 0; i < N; i++)
            if (!in_tree[i] && distance[i] > graph[v][i])
                distance[i] = graph[v][i];
        dist = MAXDIS;
        v = start;
        for (int i = 0; i < N; i++)
            if (!in_tree[i] && dist > distance[i]) {
                v = i;
                dist = distance[i];
            }

    }
    return;
}

int main()
{
    int N;
    cin >> N;
    while (N != 0) {
        vector<string> trucks(N, string());
        vvc graph = vvc(N, vc(N, MAXDIS));
        string code;
        for (int i = 0; i < N; i++) {
            cin >> trucks[i];
        }

        init_graph(graph, trucks, N);
        vector<int> distance(N, MAXDIS);
        prim(graph, 0, distance, N);
        int Q = 0;
        for (int i = 0; i < N; i++)
            Q += distance[i];
        cout << "The highest possible quality is 1/" << Q << "." << endl;

        cin >> N;
    }
}

