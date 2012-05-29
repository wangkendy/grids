#include <iostream>
using namespace std;

int main()
{
	int N;
	int input;
	cin >> N;
	while (N--) {
		cin >> input;
		if (input % 2 != 0) {
			cout << "0 0" << endl;
		} else {
			if (input % 4 != 0) {
				cout << input / 4 + 1 << ' ' << input / 2 << endl;
			} else {
				cout << input / 4 << ' ' << input / 2 << endl;
			}
		}
	}
	return 0;
}
