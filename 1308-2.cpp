/*
 * Source: http://poj.grids.cn/practice/1308/
 * Description: Is It A Tree?
 * tag: Disjoint Sets
 *
 */

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1000;

class DisjointSet {
public:
    DisjointSet(){
        memset(mem, 0, sizeof(mem));
    }
    void make_set(int x);
    int find_set(int x);
    bool union_set(int x, int y);
    bool is_tree();
private:
    unsigned short mem[MAX];
};

void DisjointSet::make_set(int x)
{
    if (!mem[x])
        mem[x] = x;
}

int DisjointSet::find_set(int x)
{
    if (mem[x] != x)
        return find_set(mem[x]);
    return x;
}

bool DisjointSet::union_set(int x, int y)
{
    if (x == y) return false;
    int temp = x;
    if (mem[y] == y) {  // y is sub root
        while (x != mem[x]) {
            x = mem[x];
            if (x == y) 
                return false;
        }
        mem[y] = temp;
        return true;
    } else {
        return false;
    }
    return false;
}

bool DisjointSet::is_tree()
{
    int sum = 0;
    for (int i = 1; i < MAX; i++) {
        if (mem[i] == i)
            sum++;
        if (sum > 1)
            return false;
    }
    return true;
}

int main()
{
    int a, b, count = 1;
    bool flag;
    while (true) {
        scanf("%d %d", &a, &b);
        if (a < 0) break;
        flag = true;
        DisjointSet djset;
        while (a != 0) {
            if (flag) {
                djset.make_set(a);
                djset.make_set(b);
                flag = djset.union_set(a, b);
            }
            scanf("%d %d", &a, &b);
        }
        if (flag) {
            if (djset.is_tree())
                printf("Case %d is a tree.\n", count++);
            else
                printf("Case %d is not a tree.\n", count++);
        } else
            printf("Case %d is not a tree.\n", count++);
    }
    return 0;
}
