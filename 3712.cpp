/*
 * Source: http://poj.grids.cn/practice/3712
 * Description: phone number
 * tag: 
 *
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char cc_map[] = {
    '2', '2', '2',
    '3', '3', '3',
    '4', '4', '4',
    '5', '5', '5',
    '6', '6', '6',
    '7', '7', '7', '7',
    '8', '8', '8',
    '9', '9', '9', '9'
};

int main()
{
    int T;
    string word, phone;
    cin >> T;
    while (T--) {
        cin >> word;
        cin >> phone;
        if (word.size() != phone.size())
            cout << 'N' << endl;
        else {
            bool flag = false;
            for (int i = 0; i < word.size(); i++) {
                if (cc_map[tolower(word[i])-'a'] != phone[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << 'N'<< endl;
            else
                cout << 'Y' << endl;
        }
    }
    return 0;
}
