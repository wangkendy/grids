/*
 * Source: http://poj.grids.cn/practice/2262
 * Description: prime number, Goldbach's Conjecture
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

void calc_prime(vector<int> &prime)
{
    for (int i = 2; i < prime.size(); i++) {
        if (prime[i])
            for (int k = i * 2; k < prime.size(); k += i)
                prime[k] = 0;
    }
}

int main()
{
    int num;
    vector<int> prime(1000000,1);
    calc_prime(prime);
    cin >> num;
    while (num != 0) {
        bool found = false;
        for (int i = 3; i < prime.size(); i++)
            if (prime[i] && prime[num-i]) {
                found = true;
                cout << num << " = " << i << " + " << num - i << endl;
                break;
            }
        if (!found) cout << "Goldbach's conjecture is wrong." << endl;
        cin >> num;
    }
    return 0;
}

