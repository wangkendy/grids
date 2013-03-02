/*
 * Source: http://poj.grids.cn/practice/1035/
 * Description: spell checker
 * tag: trie
 *
 */

#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main()
{
    int counter = 0;
    map<string, int> trie;
    string word;
    cin >> word;
    while (word[0] != '#') {
        trie[word] = counter++;
        cin >> word;
    }
    cin >> word;
    while (word[0] != '#') {
        if (trie.count(word)) {
            cout << word << " is correct" << endl;
        } else {
            cout << word << ":";
            set<pair<int,string> > candidate;
            string w;
            int word_size = word.size();
            for(int i = 0; i < word_size; i++) {
                w = word;
                w.erase(i, 1);
                if (trie.count(w))
                    candidate.insert(make_pair(trie[w], w));
            }
            for(char ch = 'a'; ch <= 'z'; ch++) {
                for(int i = 0; i < word_size; i++) {
                    w = word;
                    w.replace(i, 1, string(1, ch));
                    if (trie.count(w))
                        candidate.insert(make_pair(trie[w], w));
                }
            }
            for(char ch = 'a'; ch <= 'z'; ch++) {
                for(int i = 0; i <= word_size; i++) {
                    w = word;
                    w.insert(i, string(1, ch));
                    if (trie.count(w))
                        candidate.insert(make_pair(trie[w], w));
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
