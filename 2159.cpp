/*
 * Source: http://poj.grids.cn/practice/2159
 * Description:
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string word1;
    string word2;
    cin >> word1;
    cin >> word2;
    int size = word1.size();
    vector<int> fre1(26, 0);
    vector<int> fre2(26, 0);
    for (int i = 0; i < size; i++) {
        fre1[word1[i]-'A']++;
        fre2[word2[i]-'A']++;
    }
    sort(fre1.begin(), fre1.end());
    sort(fre2.begin(), fre2.end());
    for (int i = 0; i < 26; i++)
        if (fre1[i] != fre2[i]) {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}
