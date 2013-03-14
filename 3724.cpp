/*
 * Source: http://poj.grids.cn/practice/3724
 * Description: unix timestamp
 * tag: time function
 * author: wangkendy (wkendy@gmail.com)
 *
 */

#include <cstdio>
#include <ctime>
using namespace std;

int main()
{
    time_t t;
    while (scanf("%ld",&t) != EOF) {
        struct tm* mytm = gmtime(&t);
        printf("%d-%02d-%02d %02d:%02d:%02d\n",
                mytm->tm_year + 1900,
                mytm->tm_mon + 1,
                mytm->tm_mday,
                mytm->tm_hour,
                mytm->tm_min,
                mytm->tm_sec);
    }
    return 0;
}
