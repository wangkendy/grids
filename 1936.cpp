#include <iostream>

using namespace std;

int main()
{
	string s1, s2;
	int i, j;
	while (cin >> s1 >> s2) {
		j = 0;
		for (i = 0; i < s1.length(); i++) {
			while(j < s2.length() && s2[j] != s1[i]) j++;
			if (j < s2.length() && s2[j] == s1[i]) j++;
			else break;
		}
		if (i == s1.length()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
