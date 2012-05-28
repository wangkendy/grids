#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int m, n;
	int height;
	int max, min;
	int count;
	double power;
	cin >> m >> n;
	while (m + n) {
		if (n < m * 2) {
			cout << 1 << endl;
		} else {
			height = 0;
			do {
				power = pow(2, height);
				max = m * power + power - 1;
				height++;
			} while (max < n);
			min = m * power;
			count = pow(2, height) - 1;
			if (n >= min)
				count -= max - n;
			else count -= pow(2, height-1);
			cout << count << endl;
		}
		cin >> m >> n;
	}
	return 0;
}
