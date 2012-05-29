/*
 *source: http://poj.grids.cn/practice/2820
 *tag: string manipulation
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main()
{
	string origin, encoded;
	cin >> encoded;
	cin >> origin;
	vi fr1(26, 0);
	vi fr2(26, 0);
	for (int i = 0; i < encoded.length(); i++) {
		fr1[encoded[i]-'A']++;
	}
	for (int i = 0; i < origin.length(); i++) {
		fr2[origin[i]-'A']++;
	}
	sort(fr1.begin(), fr1.end());
	sort(fr2.begin(), fr2.end());
	for (int i = 0; i < 26; i++) {
		if (fr1[i] != fr2[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0; 
}
