/*
 * Source: http://poj.grids.cn/practice/3710/
 * Description: How many different bits
 * tag: popcount
 *
 */
#include <iostream>
using namespace std;

int popcount(int num)
{
    int count = 0;
    while (num) {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

int main()
{
    int T;
    int a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << popcount(a^b) << endl;
    }
    return 0;
}
