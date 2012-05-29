#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T, size;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> size;
		vector<int> array(size);
		int result = 0;
		for (int j = 0; j < size; j++)
			cin >> array[j];
		sort(array.begin(), array.end());
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				int l = k + 1;
				for (; l < size; l++) {
					if (array[j] == array[k] + array[l] && j != k && j != l) {
						result++;
						k = size;
						l = size;
					}
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}
