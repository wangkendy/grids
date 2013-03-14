/*
 * Source: http://poj.grids.cn/practice/3728
 * Description: blah set
 * tag: stl vector
 *
 */

#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b) {
        set<int> si;
        si.insert(a);
        int x = a + 1;
        int count = 1;
        while (true) {
            if ((x & 1) && si.find(x/2) != si.end()) {
                si.insert(x);
                count++;
            }

            if (x % 3 == 1 && si.find(x/3) != si.end()) {
                si.insert(x);
                count++;
                if (count >= b)
                    break;
            }
            x++;
        }

        set<int>::iterator itr = si.begin();
        advance(itr, b - 1);
        cout << *itr << endl;
    }
    return 0;
}

