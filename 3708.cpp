/*
 * Source: http://poj.grids.cn/practice/3708/
 * Description: popcount
 * tag: popcount
 *
 */

#include <iostream>
using namespace std;
int main(){int N, n, c;cin>>N;while(N--){cin>>n;c=0;while(n){if(n&1)c++;n>>=1;}cout << c << endl;}}
