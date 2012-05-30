/*
 * source: http://poj.grids.cn/practice/2799/
 * tag: string manipulation
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int index = 0;
	int i, j = 0;
	string input;
	cin >> N;
	vector< pair<string, int> > numbers(N);
	while (N--) {
		cin >> input;
		i = input.find('.');
		if (index < i) index = i;
		numbers[j++] = make_pair(input, i);
	}

	N = numbers.size();
	for (int k = 0; k < N; k++) {
		j = index - numbers[k].second;
		cout << string(j, ' ');
		cout << numbers[k].first << endl;
	}
	return 0;
}
