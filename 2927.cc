/*
 * source: http://poj.grids.cn/practice/2927
 * tag: string manipulation
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string input;
	while (getline(cin, input)) {
		vector<int> count(10, 0);
		for (int i = 0; i < input.length(); i++) {
			char ch = input[i];
			if (ch >= '0' && ch <= '9') {
				count[ch-'0']++;
			}
		}
		for (int i = 0; i < 10; i++) {
			if (count[i] != 0) {
				cout << i << ':' << count[i] << endl;
			}
		}
	}
	return 0;
}
