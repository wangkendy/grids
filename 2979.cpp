#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int m, n;
	int T = 0;
	cin >> n >> m;
	while (m + n) { // end when n==m==0
		int p, d;
		vector<int> V(n);
		vector<int> S(n);
		int minP_D = m * 20;
		vector< vector<int> > f(m+1, vector<int>(2 * minP_D + 1, -1)); //f[j][k] j people, deviation is k
		vector< vector<int> > path(m+1, vector<int>(2 * minP_D + 1, 0));
		for (int i = 0; i < n; i++) {
			cin >> p >> d;
			V[i] = p - d;
			S[i] = p + d;
		}

		f[0][minP_D] = 0;

		for (int j = 1; j <= m; j++) {
			for (int k = 0; k <= 2 * minP_D; k++) {
				if (f[j-1][k] >= 0) {
					for(int i = 0; i < n; i++) {
						if (k+V[i] <= 2*minP_D && f[j-1][k] + S[i] > f[j][k+V[i]]) {
							int j1 = j - 1, k1 = k;
							while (j1 > 0 && path[j1][k1] != i+1) {
								k1 -= V[path[j1][k1]];
								j1 --;
							}
							if (j1 == 0) {
								f[j][k+V[i]] = f[j-1][k] + S[i];
								path[j][k+V[i]] = i + 1;
							}
							
						}
					}
				}
			}
		}
		/*	
		for (int j = 1; j <= m; j++) {
			for(int k = 0; k <= 2 * minP_D; k++) {
				cout << j << ' ' << k - minP_D << ' ' << f[j][k] << endl;
			}
			cout << endl;
		}*/

		int j = 0;
		int k;
		while (f[m][minP_D + j] < 0 && f[m][minP_D - j] < 0)
			j++;
		if (f[m][minP_D+j] > f[m][minP_D-j])
			k = minP_D + j;
		else
			k = minP_D - j;
		cout << "Jury #" << ++T << endl; 
		cout << "Best jury has value " 
			<< (k - minP_D + f[m][k])/2
			<< " for prosecution and value "
			<< (f[m][k] - k + minP_D) / 2
			<< " for defence:" << endl;

		vector<int> ans(m+1);
		for (int i = m; i >= 1; i--){
			ans[i] = path[i][k];
			k -= V[ans[i] - 1];
		}
		sort(ans.begin(), ans.end());
		cout << ' ';
		for (int i = 1; i < m; i++) cout << ans[i] << ' ';
		cout << ans[m] << endl << endl;
		cin >> n >> m;
	}
	return 0;
}
