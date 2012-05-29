#include <iostream>
#include <vector>
#define MOD 10007

using namespace std;
typedef unsigned int uint;

uint pow_mod(uint a, uint pow, uint mod = MOD)
{
	if (a == 0 && pow != 0) return 0;
	uint product = 1;
	uint topow = a % mod;
	while (pow) {
		if (pow&1)
			product = product * topow % mod;
		topow *= topow;
		topow %= mod;
		pow >>= 1;
	}
	return product;
}

uint cnk_mod(uint n, uint k, uint mod = MOD)
{
	vector< vector<uint> > map(k+1, vector<uint>(n-k+1, 0));
	for (int i = 0; i <= k; i++)
		map[i][0] = 1;
	for (int i = 1; i <= n-k; i++)
		map[0][i] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n-k; j++) {
			map[i][j] = map[i-1][j] + map[i][j-1];
			if (map[i][j] > mod) map[i][j] %= mod;
		}
	}
	return map[k][n-k];
}

int main()
{
	uint a, b, k, n, m;
	cin >> a >> b >> k >> n >> m;
	uint result = pow_mod(a, n) * pow_mod(b, m) % MOD;
	result *= cnk_mod(k, m);
	result %= MOD;
	cout << result << endl;
	return 0;
}
