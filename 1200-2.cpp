/*
 * Source: http://poj.grids.cn/practice/1200/
 * Description: Crazy Search
 * tag: Trie
 *
 */
#include <cstdio>
#include <deque>
#include <map>
using namespace std;

class Trie {
public:
    Trie() {
        root = new Node;
    }
    int addWord(deque<char> &word); // new word return 1
private:
    struct Node {
        map<char, Node*> children;
    };
    Node *root;
};

int Trie::addWord(deque<char> &word)
{
    Node *cur = root;
    deque<char>::iterator itr;
    bool newWord = false;
    for (itr = word.begin(); itr != word.end(); itr++) {
        if (!cur->children.count(*itr)) {
            cur->children[*itr] = new Node;
            newWord = true;
        }
        cur = cur->children[*itr];
    }
    if (newWord) return 1;
    return 0;
}

int main()
{
    Trie trie;
    int N, NC, total = 0;
    char input[10000];
    int ch;
    deque<char> word;
    scanf("%d %d", &N, &NC);
    getchar();
    gets(input);
    int i;
    for (i = 0; i < N-1; i++) { // read in N-1 char
        word.push_back(input[i]);
    }
    while (input[i] != '\0') {
        word.push_back(input[i]);
        total += trie.addWord(word);
        word.pop_front();
        i++;
    }
    printf("%d", total);
    return 0;
}
