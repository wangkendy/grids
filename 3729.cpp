/*
 * Source: http://poj.grids.cn/practice/3729
 * Description: string match
 * tag: set
 *
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Mystring {
public:
    bool operator< (const Mystring& rhs) const {
        int lval = get_val();
        int rval = rhs.get_val();
        if (lval == rval)
            return str.size() < rhs.str.size();
        else 
            return lval > rval;
    }

    bool operator==(const string& rhs) {
        return str == rhs;
    }

    friend ostream& operator<<(ostream& out, const Mystring& ms) {
        return out << ms.str;
    }

    friend istream& operator>>(istream& in, Mystring& ms) {
        return in >> ms.str;
    }

private:
    string str;
    int get_val() const {
        int val = 0;
        for (int i = 0; i < str.size(); i++)
            val = val * 10 + str[i] - '0';
        return val;
    }
};

int main()
{
    set<Mystring> sm;
    Mystring str;
    while (cin >> str) {
        if (str == "END")
            break;
        sm.insert(str);
    }

    set<Mystring>::iterator itr = sm.begin();
    for (; itr != sm.end(); itr++)
        cout << *itr << endl;
    
    while (cin >> str) {
        if (str == "END")
            break;
        if (sm.count(str))
            cout << str << " found" << endl;
        else 
            cout << str << " not Found" << endl;
    }
}

