/*
 * Source: http://poj.grids.cn/practice/1035/
 * Description: spell checker
 * tag: trie
 *
 */

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Trie {
public:
    Trie():counter(0){
        root = new Node;
    }
    int containsWord(const string &word);
    void addWord(const string &word);
private:
    struct Node {
        Node():letter(' '), isWord(false), count(-1){
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
        char letter;
        bool isWord;
        int count;
        Node *children[26];
    };
    Node *root;
    int counter;
    void addWord(Node* &root, const string &word);
    int containsWord(Node* root, const string &word);
};

void Trie::addWord(const string &word)
{
    if (word.size() == 0) return;
    addWord(root->children[word[0]-'a'], word);
}

void Trie::addWord(Node* &root, const string &word)
{
    //if (word.size() == 0) return;
    if (root == NULL) {
        root = new Node;
        root->letter = word[0];
        root->count = -1;
    }
    if (word.size() == 1) {
        root->count = counter++;
        root->isWord = true;
    } else {
        addWord(root->children[word[1]-'a'], word.substr(1));
    }
}

int Trie::containsWord(const string &word)
{
    if (word.size() == 0) return -1;
    return containsWord(root->children[word[0] - 'a'], word);
}

int Trie::containsWord(Node* root, const string &word)
{
    if (root == NULL) return -1;
    if (word.size() == 1) {
        if (root->isWord)
            return root->count;
        else return -1;
    } else {
        return containsWord(root->children[word[1] - 'a'], word.substr(1));
    }
}

int main()
{
    Trie trie;
    string word;
    cin >> word;
    while (word[0] != '#') {
        trie.addWord(word);
        cin >> word;
    }
    cin >> word;
    while (word[0] != '#') {
        int ret = trie.containsWord(word);
        if (ret != -1) {
            cout << word << " is correct" << endl;
        } else {
            cout << word << ":";
            set<pair<int,string> > candidate;
            string w;
            int word_size = word.size();
            for(int i = 0; i < word_size; i++) {
                w = word;
                w.erase(i, 1);
                int ret = trie.containsWord(w);
                if (ret != -1)
                    candidate.insert(make_pair(ret, w));
            }
            for(char ch = 'a'; ch <= 'z'; ch++) {
                for(int i = 0; i < word_size; i++) {
                    w = word;
                    w.replace(i, 1, string(1, ch));
                    int ret = trie.containsWord(w);
                    if (ret != -1)
                        candidate.insert(make_pair(ret, w));
                }
            }
            for(char ch = 'a'; ch <= 'z'; ch++) {
                for(int i = 0; i <= word_size; i++) {
                    w = word;
                    w.insert(i, string(1, ch));
                    int ret = trie.containsWord(w);
                    if (ret != -1)
                        candidate.insert(make_pair(ret, w));
                }
            }

            set<pair<int, string> >::iterator itr;
            for (itr = candidate.begin(); itr != candidate.end(); itr++)
                cout << " " << itr->second;
            cout << endl;
        }
        cin >> word;
    }
    return 0;
}
