/*
 * Source: http://poj.grids.cn/practice/2524/
 * Description: Ubiquitous Religions
 * tag: Disjoint Sets
 *
 */
#include <cstdio>
using namespace std;

class DisjointSet {
public:
    DisjointSet(int max):max(max) {
        mem = new Node[max+1];
        for (int i = 0; i <= max; i++) {
            mem[i].parent = i;
            mem[i].rank = 1;
        }
    }
    int find_set(int x);
    void union_set(int x, int y);
private:
    struct Node {
        int parent;
        int rank;
    };
    int max;
    Node* mem;
    void link_set(int x, int y);

};

int DisjointSet::find_set(int x)
{
    if (x != mem[x].parent)
        mem[x].parent = find_set(mem[x].parent);
    return mem[x].parent;
}

void DisjointSet::union_set(int x, int y)
{
    link_set(find_set(x), find_set(y));
}

void DisjointSet::link_set(int x, int y)
{
    if (mem[x].rank > mem[y].rank)
        mem[y].parent = x;
    else {
        mem[x].parent = y;
        if (mem[x].rank == mem[y].rank)
            mem[y].rank += 1;
    }
}

int main()
{
    int n, m;
    int count = 1, num;
    scanf("%d %d", &n, &m);
    while (n != 0 && m != 0) {
        DisjointSet djset(n);
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            djset.union_set(a, b);
        }
        num = 0;
        for (int i = 1; i <= n; i++) {
            if (i == djset.find_set(i))
                num++;
        }
        printf("Case %d: %d\n", count++, num);
        scanf("%d %d", &n, &m);
    }
    return 0;
}
