/*
 * Source: http://poj.grids.cn/practice/2513/
 * Description: Colored Sticks
 * tag: Trie, Disjoint Sets, Euler circuit
 *
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Trie {
public:
    Trie():counter(0) {
        root = new Node;
    }
    int addWord(const string &word);
    int addWord(const char *word);
    int max_count() {
        return counter;
    }
private:
    struct Node {
        int hash;
        Node* children[26];
        Node():hash(-1) {
            //for(int i = 0; i < 26; i++)
                //children[i] = NULL;
            memset(children, 0, sizeof(children));
        }
    };
    int counter;
    Node *root;
};

int Trie::addWord(const string &word)
{
    Node *p = root;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i]-'a';
        if (p->children[index] == NULL) {
            Node *newNode = new Node;
            p->children[index] = newNode;
        } 
        p = p->children[index];
    }
    if (p->hash == -1)
        p->hash = counter++;
    return p->hash;
}

int Trie::addWord(const char *word)
{
    Node *p = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i]-'a';
        if (p->children[index] == NULL) {
            Node *newNode = new Node;
            p->children[index] = newNode;
        } 
        p = p->children[index];
    }
    if (p->hash == -1)
        p->hash = counter++;
    return p->hash;
}

class DisjointSet {
public:
    DisjointSet(){
        for (int i = 0; i < MAX; i++) {
            member[i].parent = i;
            member[i].rank = 1;
        }
    }

    void union_set(int x, int y);
    int find_set(int x);
    int find(int x);
private:
    struct Node {
        int parent;
        int rank;
    };
    enum {MAX=500001};
    Node member[MAX];
    void link_set(int x, int y);
};

void DisjointSet::union_set(int x, int y)
{
    //link_set(find_set(x), find_set(y));
    link_set(find(x), find(y));
}

void DisjointSet::link_set(int x, int y)
{
    if (member[x].rank > member[y].rank)
        member[y].parent = x;
    else {
        member[x].parent = y;
        if (member[x].rank == member[y].rank)
            member[y].rank += 1;
    }

}

int DisjointSet::find_set(int x)
{
    if (x != member[x].parent)
        member[x].parent = find_set(member[x].parent);
    return member[x].parent;
}

int DisjointSet::find(int x)
{
    int root,temp;
    temp=x;
    while(x!=member[x].parent)
        x=member[x].parent;
    root=x;
    x=temp;
    while (x!=member[x].parent)
    {
        temp=member[x].parent;
        member[x].parent=root;
        x=temp;
    }
    return root;
}

int main()
{
    Trie trie;
    DisjointSet djset;
    int degree[500001] = {0};
    string word1, word2;
    char w1[15], w2[15];
    int hash1, hash2;
    while (scanf("%s %s", w1, w2) != EOF) {
        hash1 = trie.addWord(w1);
        hash2 = trie.addWord(w2);
        degree[hash1]++;
        degree[hash2]++;
        djset.union_set(hash1, hash2);
    }
    int max_count = trie.max_count();
    int sum = 0;
    for (int i = 0; i < max_count; i++) {
        if (degree[i] & 1)
            sum++;
        if (sum > 2) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (int i = 0; i < max_count; i++) {
        if (djset.find_set(i) != djset.find_set(0)) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}
