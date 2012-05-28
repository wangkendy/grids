/*
*source: http://poj.grids.cn/practice/1664/
*/
#include <iostream>

using namespace std;

int count(int apple, int plate)
{
	if (plate == 1 || apple == 0) {
		return 1;
	}
	if (plate > apple) {
		plate = apple;
		return count(apple, plate);
	}
	return count(apple, plate-1) + count(apple - plate, plate);
}

int main()
{
	int N;
	int apple, plate;
	cin >> N;
	while (N--) {
		cin >> apple >> plate;
		cout << count(apple, plate) << endl;
	}
	return 0;
}
