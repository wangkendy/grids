/*
 * Source: http://poj.grids.cn/practice/3704
 * Description: Matching brackets
 * tag: stack
 *
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string input;
    stack<pair<char,int> > spci;
    while (cin >> input) {
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '(') {
                spci.push(make_pair(input[i], i));
            } else if (input[i] == ')') {
                if (!spci.empty() && spci.top().first == '(') {
                        spci.pop();
                } else {
                    spci.push(make_pair(input[i], i));
                }
            }
        }
        cout << input << endl;
        if (spci.empty()) {
            cout << endl;
        } else {
            string res(spci.top().second + 1, ' ');
            while (!spci.empty()) {
                if (spci.top().first == '(')
                    res[spci.top().second] = '$';
                else 
                    res[spci.top().second] = '?';
                spci.pop();
            }
            cout << res << endl;
        }
    }

}

