/*
 * Source: http://poj.grids.cn/practice/3715
 * Description: day count
 * tag: 
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    return 0;
}

int mon_day[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int year_day[] = {365, 366};

struct Employer {
    Employer():total_day(0){}
    string name;
    int s_year;
    int s_month;
    int s_day;
    int e_year;
    int e_month;
    int e_day;
    int total_day;
    int count_total_day() {
        if (s_year == e_year) {
            int leap = is_leap_year(s_year);
            if (s_month == e_month) {
                total_day += e_day - s_day + 1;
            } else {
                total_day += mon_day[leap][s_month - 1] - s_day + 1;
                for (int m = s_month + 1; m < e_month; m++)
                    total_day += mon_day[leap][m-1];
                total_day += e_day;

            }
        } else {    // s_year < e_year
            int s_leap = is_leap_year(s_year);
            total_day += mon_day[s_leap][s_month - 1] - s_day + 1;
            for (int m = s_month + 1; m <= 12; m++)
                total_day += mon_day[s_leap][m - 1];
            for (int y = s_year + 1; y < e_year; y++) {
                int leap = is_leap_year(y);
                total_day += year_day[leap];
            }
            int e_leap = is_leap_year(e_year);
            for (int m = 1; m < e_month; m++)
                total_day += mon_day[e_leap][m - 1];
            total_day += e_day;
        }
    }
    bool operator< (const Employer& rhs) const{
        return total_day > rhs.total_day;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Employer> emp(n);
    for (int i = 0; i < n; i++) {
        cin >> emp[i].name;
        cin >> emp[i].s_year >> emp[i].s_month >> emp[i].s_day;
        cin >> emp[i].e_year >> emp[i].e_month >> emp[i].e_day;
    }
    for_each(emp.begin(), emp.end(), mem_fun_ref(&Employer::count_total_day));
    stable_sort(emp.begin(), emp.end());
    for (int i = 0; i < n; i++) {
        cout << emp[i].name << ' ' << emp[i].total_day << endl;
    }
    return 0;
}

