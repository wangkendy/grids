/*
 * source: http://poj.grids.cn/practice/2712
 * tag: date and time
 *
 */

#include <iostream>

using namespace std;

int get_days(int bm, int bd, int em, int ed)
{
	static int mon[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	int days = 0;
	if (bm < em) {
		days = mon[bm] - bd + ed;
	} else { // same month
		days = ed - bd;
	}
	for (int i = bm + 1; i < em; i++) {
		days += mon[i];
	}
	return days;
}

int main()
{
	int N;
	unsigned long init;
	int bm, bd, em, ed;
	cin >> N;
	while (N--) {
		cin >> bm >> bd >> init >> em >> ed;
		int days = get_days(bm, bd, em, ed);
		cout << (init << days) << endl;
	}
	return 0;
}
