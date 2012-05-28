#include <iostream>

using namespace std;

int node_count(int m, int n)
{
	int left = 0, right = 0;
	if (2 * m <= n) {
		left = node_count(2*m, n);
	}

	if (2 * m + 1 <= n) {
		right = node_count(2*m+1, n);
	}

	return left + right + 1;
}

int main()
{
	int m, n;
	cin >> m >> n;
	while (m + n) {
		cout << node_count(m, n) << endl;
		cin >> m >> n;
	}
	return 0;
}
