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
    int ch;
    deque<char> word;
    scanf("%d %d", &N, &NC);
    word.push_back(getchar());  // read in the return key
    for (int i = 1; i < N; i++) { // read in N-1 char
        word.push_back(getchar());
    }
    while ((ch = getchar()) != EOF && ch != '\n') {
        word.pop_front();
        word.push_back(ch);
        total += trie.addWord(word);
    }
    printf("%d", total);
    return 0;
}
