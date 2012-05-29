#include <iostream>

using namespace std;

int main()
{
	int N;
	char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s1, s2;
	string empty;
	cin >> N;
	getline(cin, empty);
	while (N--) {
		getline(cin, s1);
		getline(cin, s2);
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == ' ') {
				s1.erase(i,1);
				i--;
			}
		}
		for (int i = 0; i < s2.length() ; i++) {
			if (s2[i] == ' ') {
				s2.erase(i,1);
				i--;
			}
		}
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] >= 'a' && s1[i] <= 'z') {
				s1[i] = map[s1[i]-'a'];
			}
		}
		for (int i = 0; i < s2.length(); i++) {
			if (s2[i] >= 'a' && s2[i] <= 'z') {
				s2[i] = map[s2[i]-'a'];
			}
		}
		if (s1 == s2) cout << "YES" << endl;
		else cout << "NO" << endl;
		if (N != 0)
			getline(cin, empty);
	}
	return 0;
}
