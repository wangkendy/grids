#include <iostream>
#include <sstream>

using namespace std;

string num2binary(int num)
{
	string res;
	//cout << num << endl;
	return res;
}

int main() {
	string ip;
	cin >> ip;
	while (ip.compare("-1") != 0) {
		istringstream is(ip);
		int num;
		char dot;
		string result;
		is >> num;
		result += num2binary(num);
		is >> dot;
		is >> num;
		result += num2binary(num);
		is >> dot;
		is >> num;
		result += num2binary(num);
		is >> dot;
		is >> num;
		result += num2binary(num);
		cout << result << endl;
		cin >> ip;
	}
	return 0;
}
