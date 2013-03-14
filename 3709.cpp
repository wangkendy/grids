/*
 * Source: http://poj.grids.cn/practice/3709/
 * Description: hex2 to hex3
 * tag: 
 *
 */
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int T;
    int dec;
    stack<int> si;
    string input;
    cin >> T;
    while (T--) {
        cin >> input;
        dec = 0;
        for (int i = 0; i < input.size(); i++)
            dec = dec * 2 + input[i] - '0';
        while (dec) {
            si.push(dec % 3);
            dec /= 3;
        }
        while (!si.empty()) {
            cout << si.top();
            si.pop();
        }
        cout << endl;
    }
    return 0;
}

