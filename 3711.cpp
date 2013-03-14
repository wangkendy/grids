/*
 * Source: http://poj.grids.cn/practice/3711
 * Description: string shift and substring
 * tag: 
 *
 */

#include <iostream>
#include <string>
using namespace std;

void reverse(string &str, int start, int stop)
{
    char temp;
    while (start < stop) {
        temp = str[start];
        str[start] = str[stop];
        str[stop] = temp;
        start++;
        stop--;
    }
}

void shift_k(string &str, int k) {
    reverse(str, 0, str.size() - k - 1);
    reverse(str, str.size() - k, str.size() - 1);
    reverse(str, 0, str.size() - 1);
}

int main()
{
    string str1, str2, temp;
    int T;
    cin >> T;
    while (T--) {
        cin >> str1;
        cin >> str2;
        if (str2.size() > str1.size()) {
            temp = str1;
            str1 = str2;
            str2 = temp;
        }
        if (str1.find(str2) != string::npos)
            cout << "true" << endl;
        else {
            bool found = false;
            for (int i = 1; i < str2.size(); i++) {
                shift_k(str1, i);
                if (str1.find(str2) != string::npos) {
                    found = true;
                    break;
                }
            }
            if (found)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
}

