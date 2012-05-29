#include <iostream>
#include <vector>
using namespace std;

bool is_cyclic(vector<int>& num)
{
	//1. break in half, sums to 999..
	int n = num.size();
	if (n % 2 != 0) {
		return false;
	} else {
		int half = n/2;
		for (int i = 0; i < half; i++) {
			if (num[i] + num[i+half] != 9)
				return false;
		}
	}
	
	//2. times (n+1) euqal 999...
	int bits = n + 1;
	for (int i = 0; i < n; i++) {
		num[i] *= bits;
	}
	int c = 0;
	for (int i = n - 1; i > 0; i--) {
		num[i] += c;
		c = num[i] / 10;
		num[i] %= 10;
		if (num[i] != 9) return false;
	}
	if (num[0] + c != 9) return false;
	return true;
}

int main()
{
	string input;
	while (cin >> input) {
		vector<int> num(input.length());
		for (int i = 0; i < num.size(); i++)
			num[i] = input[i] - '0';
		if (is_cyclic(num)) {
			cout << input << " is cyclic" << endl;
		} else {
			cout << input << " is not cyclic" << endl;
		}
	}
	return 0;
}
