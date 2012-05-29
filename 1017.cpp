#include <iostream>

using namespace std;

int main()
{
	int c1, c2, c3, c4, c5, c6;
	int threetwos[] = {0, 5, 3, 1};
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	while (c1 || c2 || c3 || c4 || c5 || c6) {
		int box_count = 0;
		int ones, twos;
		box_count += c6 + c5 + c4 + (c3+3)/4;
		twos = c4 * 5 + threetwos[c3 % 4];
		if (c2 > twos)
			box_count += (c2 - twos + 8) / 9;

		ones = 36 * box_count - 36 * c6 - 25 * c5 -16 * c4 - 9 * c3 - 4 * c2;
 		if(c1 > ones)
			box_count += (c1 - ones + 35) / 36;
		cout << box_count << endl;
		cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	}
	return 0;
}
