/*
 * Source: http://poj.grids.cn/practice/4015/
 * Description: email address validation
 * tag: 
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string email;
    while (cin >> email) {
        if (email[0] == '@' || email[0] == '.') {
            cout << "NO" << endl;
            continue;
        }
        int len = email.size();
        if (email[len-1] == '@' || email[len-1] == '.') {
            cout << "NO" << endl;
            continue;
        }
        int pos;
        if ((pos = email.find('@')) == string::npos) {
            cout << "NO" << endl;
        } else {
            if (email[pos-1] == '.')
                cout << "NO" << endl;
            else if (email[pos+1] == '.')
                cout << "NO" << endl;
            else if (email.find("@", pos + 1) != string::npos)
                cout << "NO" << endl;
            else if (email.find('.', pos) == string::npos)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}
