/*
 * Source: http://poj.grids.cn/practice/1083
 * Description:
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    int N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> vi(200, 0);
        int a, b;
        int s, e;
        int tmp;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            if (a > b) {
                tmp = a;
                a = b;
                b = tmp;
            }
            if (a & 1) s = a / 2;
            else s = a / 2 - 1;
            if (b & 1) e = b / 2;
            else e = b / 2 - 1;
            for (int k = s; k <= e; k++)
                vi[k]++;
        }
        int max = -1;
        for (int i = 0; i < 200; i++)
            if (max < vi[i])
                max = vi[i];
        cout << max * 10 << endl;
    }
    return 0;
}
