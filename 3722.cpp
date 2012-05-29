#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		int a;
		for (a = 1; a < M; a++) {
			if (N % a == 0 && N % (M - a) == 0) {
				cout << a << endl;
				break;
			}
		}
		if (a == M) {
			cout << -1 << endl;
		}
	}
	return 0;
}
