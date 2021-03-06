/*
 * Source: http://poj.grids.cn/practice/1611/
 * Description: The Suspects
 * tag: Disjoint Sets
 *
 */
#include <cstdio>

class DisjointSet {
public:
    DisjointSet(int max):MAX(max) {
        mem = new Node[MAX];
        for (int i = 0; i < MAX; i++) {
            mem[i].parent = i;
            mem[i].rank = 0;
        }
    }
    ~DisjointSet() {
        delete [] mem;
    }
    int find_set(int x);
    void union_set(int x, int y);
    int count_suspects();
private:
    void link(int x, int y);
    struct Node {
        unsigned short parent;
        char rank;
    };
    Node *mem;
    int MAX;
};

int DisjointSet::find_set(int x)
{
    if (mem[x].parent != x)
        mem[x].parent = find_set(mem[x].parent);
    return mem[x].parent;
}

void DisjointSet::union_set(int x, int y)
{
    link(find_set(x), find_set(y));
}

void DisjointSet::link(int x, int y)
{
    if (mem[x].rank > mem[y].rank)
        mem[y].parent = x;
    else {
        mem[x].parent = y;
        if (mem[x].rank == mem[y].rank)
            mem[y].rank += 1;
    }
}

int DisjointSet::count_suspects()
{
    int suspect_count = 1;
    for (int i = 1; i < MAX; i++) {
        if (find_set(i) == find_set(0))
            suspect_count++;
    }
    return suspect_count;
}

int main()
{
    int n, m, k;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        DisjointSet djset(n);
        for (int i = 0; i < m; i++) {
            scanf("%d", &k);
            int a, b;
            scanf("%d", &a);
            for (int j = 1; j < k; j++) {
                scanf("%d", &b);
                djset.union_set(a, b);
            }
        }
        printf("%d\n", djset.count_suspects());
    }
    return 0;
}
