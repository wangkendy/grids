#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, n;
	cin >> N;
	while (N--) {
		cin >> n;
		vector<string> input(n);
		string shortest;
		int min_len = 101;
		int index;
		for (int i = 0; i < n; i++) {
			cin >> input[i];
			if (min_len > input[i].length()) {
				min_len = input[i].length();
				index = i;
			}
		}
		shortest = input[index];
		bool found = false;
		for (int j = shortest.length(); j > 0; j--) {
			for (int i = 0; i + j <= shortest.length(); i++) {
				string sub_str = shortest.substr(i, j);
				string rev_sub = string(sub_str.rbegin(), sub_str.rend());
				int k;
				for (k = 0; k < n; k++) {
					if (input[k].find(sub_str) == string::npos && input[k].find(rev_sub) == string::npos) {
						break;
					}	
				}
				if (k == n) {
					cout << j << endl;
					found = true;
					j = 0; // break the first loop
					break;
				}
			}
		}
		if (!found) {
			cout << 0 << endl;
		}
	}
	return 0;
}
