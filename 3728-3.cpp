/*
 * Source: http://poj.grids.cn/practice/3728
 * Description: blah number set
 * tag: ugly number
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b) {
        vector<int> vi;
        int pm2, pm3;
        int tmp1, tmp2;
        vi.push_back(a);
        pm2 = 0;
        pm3 = 0;
        while (vi.size() < b) {
            vi.push_back(min(vi[pm2] * 2 + 1, vi[pm3] * 3 + 1));
            while (vi[pm2] * 2 + 1 <= vi.back())
                pm2++;
            while (vi[pm3] * 3 + 1 <= vi.back())
                pm3++;
        }
        cout << vi[b-1] << endl;
    }
    return 0;
}

