/*
 * Source: http://poj.grids.cn/practice/1003
 * Description:
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
using namespace std;

int main()
{
    double input;
    cin >> input;
    while (input != 0.0) {
        int card = 1;
        double sum = 0.5;
        while (sum < input) {
            card++;
            sum += 1.0/(card+1);
        }
        cout << card << " card(s)" << endl;
        cin >> input;
    }
    return 0;
}
