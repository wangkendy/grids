#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2) {
		vector< vector<int> > maxLength(s1.size() + 1, vector<int>(s2.size() + 1));
		for(int i = 0; i <= s1.size(); i++) maxLength[i][0] = 0;
		for(int i = 0; i <= s2.size(); i++) maxLength[0][i] = 0;
		
		for(int i = 0; i < s1.size(); i++) {
			for(int j = 0; j < s2.size(); j++) {
				if (s1[i] == s2[j]) {
					maxLength[i+1][j+1] = maxLength[i][j] + 1;
				} else {
					maxLength[i+1][j+1] = max(maxLength[i][j+1], maxLength[i+1][j]);
				}
			}
		}
		cout << maxLength[s1.size()][s2.size()] << endl;
	}
	return 0;
}
