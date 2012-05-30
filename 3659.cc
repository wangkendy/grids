/*
 * source: http://poj.grids.cn/practice/3659
 * tag: string manipulation
 *
 */

#include <iostream>

using namespace std;

bool is_valid(const string& var)
{
	char ch = var[0];
	if(!((ch >= 'a' && ch <= 'z') || 
		 (ch >= 'A' && ch <= 'Z') || 
		 (ch == '_'))) return false;

	for (int i = 1; i < var.length(); i++) {
		ch = var[i];
		if(!((ch >= 'a' && ch <= 'z') ||
			 (ch >= 'A' && ch <= 'Z') ||
			 (ch >= '0' && ch <= '9') ||
			 (ch == '_'))) return false;
	}
	return true;
}

int main()
{
	int N;
	string var;
	cin >> N;
	getline(cin, var, '\n');
	while (N--) {
		getline(cin, var, '\n');
		if (is_valid(var)) cout << "1" << endl;
		else cout << "0" << endl;
	}
	return 0;
}
