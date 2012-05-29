#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int sum;
	int len1, len2;
	cin >> N;
	while (N--) {
		cin >> sum;
		cin >> len1;
		vector<int> a1(len1);
		for (int i = 0; i < len1; i++)
			cin >> a1[i];
		cin >> len2;
		vector<int> a2(len2);
		for (int i = 0; i < len2; i++)
			cin >> a2[i];

		sort(a1.begin(), a1.end());
		sort(a2.rbegin(), a2.rend());

		int total = 0;
		int count = 0;
		int lastj = 0;
		for (int i = 0; i < len1; i++) {
			if (i != 0 && a1[i] == a1[i-1]) goto addtototal;
			count = 0;
			if (lastj < len2) {
			while (a1[i] + a2[lastj] >= sum) {
				if (a1[i] + a2[lastj] == sum)
					count++;
				lastj++;
				if (lastj == len2) break;
			}
			} else {
				break;
			}
			addtototal:
			total += count;
		}
		cout << total << endl;
	}
	return 0;
}
