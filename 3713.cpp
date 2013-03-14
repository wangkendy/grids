/*
 * Source: http://poj.grids.cn/practice/3713/
 * Description: English word to number
 * tag: recursion
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <deque>
using namespace std;

struct StringInt {
    const char *str;
    int num;
};

StringInt si[] = {
    {"negative", -1}, 
    {"zero", 0}, 
    {"one", 1}, 
    {"two", 2}, 
    {"three", 3}, 
    {"four", 4}, 
    {"five", 5}, 
    {"six", 6}, 
    {"seven", 7}, 
    {"eight", 8},
    {"nine", 9}, 
    {"ten", 10}, 
    {"eleven", 11}, 
    {"twelve", 12}, 
    {"thirteen", 13}, 
    {"fourteen", 14}, 
    {"fifteen", 15}, 
    {"sixteen", 16},
    {"seventeen", 17}, 
    {"eighteen", 18}, 
    {"nineteen", 19},
    {"twenty", 20}, 
    {"thirty", 30}, 
    {"forty", 40}, 
    {"fifty", 50}, 
    {"sixty", 60},
    {"seventy", 70}, 
    {"eighty", 80}, 
    {"ninety", 90}, 
    {"hundred", 100}, 
    {"thousand", 1000}, 
    {"million", 1000000}
};

int tail_zero(int n)
{
    int res = 10;
    while (n % res == 0)
        res *= 10;
    return res/10;
}

int main() {
    string line;
    map<string, int> simap;
    int si_size = sizeof si / sizeof *si;
    for (int i = 0; i < si_size; i++)
        simap[si[i].str] = si[i].num;

    while (getline(cin, line)) {
        int pos = 0;
        int start = 0;
        bool negative =  false;
        int i = 0;
        int num;
        deque<int> ds;
        while (!line.empty()) {
            if((pos = line.find(' ', start)) != string::npos)
                num = simap[line.substr(start, pos - start)];
            else {
                num = simap[line.substr(start)];
                line = "";
            }
            if (num == -1) {
                negative = true;
            } else {
                if (i % 2 == 0) {
                    ds.push_back(num);
                } else {
                    int temp = ds.back();
                    ds.pop_back();
                    if (num % 100 == 0)
                        ds.push_back(temp * num);
                    else
                        ds.push_back(temp + num);
                }
                i++;
            }
            start = pos + 1;
        }
        int temp, sum = 0;
        sum = ds.front();
        ds.pop_front();
        for (int i = 0; i < ds.size(); i++) {
            if (sum > ds[i]) {
                sum += ds[i];
            } else {
                sum = sum * tail_zero(ds[i]) + ds[i];
            }
        }
        if (negative)
            sum *= -1;
        cout << sum << endl;
    }
    return 0;
}
