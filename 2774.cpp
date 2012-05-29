#include <iostream>
#include <vector>

using namespace std;

bool willDo(const vector<int>& wood, int K, int len)
{
	int count = 0;
	for (int i = 0; i < wood.size(); i++) {
		count += wood[i] / len;
		if (count >= K) return true;
	}
	return false;
}

int main()
{
	int N, K;
	int total_len = 0;
	int max_len = 0;
	cin >> N >> K;
	vector<int> wood(N);
	for (int i = 0; i < N; i++) {
		cin >> wood[i];
		total_len += wood[i];
	}

	max_len = total_len / K;
	int min_len = 1;
	int len;
	int last_len = 0;

	while (min_len <= max_len) {
		len = (min_len + max_len) / 2;
		if (willDo(wood, K, len)) {
			last_len = len;
			min_len = len + 1;
		} else {
			max_len = len - 1;
		}
	}
	cout << last_len << endl;
	return 0;
}
