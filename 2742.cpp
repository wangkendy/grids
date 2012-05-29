#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	string input;
	cin >> N;
	while (N--) {
		cin >> input;
		vector<int> count(26, 0);
		for (int i = 0; i < input.length(); i++)
			count[input[i]-'a']++;
		int max = 0;
		char ch;
		for (int i = 0; i < 26; i++) {
			if (count[i] > max) {
				max = count[i];
				ch = i + 'a';
			}
		}
		cout << ch << ' ' << max << endl;
	}
	return 0;
}
