/*
 * Source: http://poj.grids.cn/practice/3718
 * Description: bit shift
 * tag:  popcount
 *
 */

#include <cstdio>

int popcount(unsigned short n)
{
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main()
{
    int T;
    unsigned short a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%hd %hd", &a, &b);
        if (popcount(a) != popcount(b)) {
            printf("NO\n");
        } else {
            unsigned short flag = 0x8000;
            bool same = false;
            for (int i = 0; i < 16; i++) {
                if (a & flag) {
                    a = (a << 1) + 1;
                } else {
                    a = a << 1;
                }
                if (a == b) {
                    same = true;
                    break;
                }
            }
            if (same) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
