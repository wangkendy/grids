/*
 * Source: http://poj.grids.cn/practice/1004
 * Description:
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    double input;
    double sum = 0.0;
    for (int i = 0; i < 12; i++) {
        cin >> input;
        sum += input;
    }
    printf("$%.2f\n", sum/12);
    return 0;
}
