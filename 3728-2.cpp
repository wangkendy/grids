/*
 * Source: http://poj.grids.cn/practice/3728
 * Description: blah number set
 * tag: ugly number
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b) {
        vector<int> vi;
        int p1, p2;
        int tmp1, tmp2;
        vi.push_back(a);
        vi.push_back(2 * a + 1);
        p1 = 0;
        p2 = 1;
        int min;
        while (vi.size() < b) {
            min = 0x7fffffff;
            for (int i = p1; i < p2; i++) {
                tmp1 = vi[i] * 2 + 1;
                tmp2 = vi[i] * 3 + 1;
                if (tmp1 <= vi[p2] && tmp2 <= vi[p2]) {
                    p1++;
                } else if (tmp1 <= vi[p2]) {
                    if (min > tmp2)
                        min = tmp2;
                } else {
                    if (min > tmp1)
                        min = tmp1;
                    break;
                }
            }
            vi.push_back(min);
            p2++;
        }
        cout << vi[b-1] << endl;
    }
    return 0;
}

