#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned int mod = 32767;
unsigned int p[1000000];

unsigned int pell(int k)
{
	static int index = 2;
	if (k > index) {
		for (int i = index + 1; i <= k; i++) {
			p[i] = 2 * p[i-1] + p[i-2];
			p[i] %= mod;
		}
		index = k;
	}
	return p[k];
}

int main()
{
	p[1] = 1;
	p[2] = 2;
	int N;
	int k;
	cin >> N;
	while (N--) {
		cin >> k;
		cout << pell(k) << endl;	
	}
	return 0;
}
