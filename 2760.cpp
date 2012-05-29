#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector< vector<int> > tri(N);
	for(int i = 0; i < N; i++) {
		tri[i] = vector<int>(i+1);
		for(int j = 0; j <= i; j++)
			cin >> tri[i][j];
	}

	for(int i = N - 2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
		}
	}
	
	cout << tri[0][0] << endl;
	return 0;
}
