#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<char>& vec)
{
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i];
	cout << endl;
}

int main()
{
	string input;
	cin >> input;
	vector<char> ch(input.size());
	for (int i = 0; i < input.size(); i++) {
		ch[i] = input[i];
	}

	do {
		print_vector(ch);
	} while (next_permutation(ch.begin(), ch.end()));
	return 0;
}
