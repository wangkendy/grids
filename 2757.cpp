#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> l(N, 1);
	int len, index;
	
	for(int i = 0; i < N; i++) cin >> a[i];
	
	for(int i = 1; i < N; i++) {
		len = 0;
		for(int j = 0; j < i; j++) {
			if (a[i] > a[j])
				if (len < l[j])
					len = l[j];
		}
		l[i] += len;
	}
	cout << *max_element(l.begin(), l.end()) << endl;
	return 0;
}
