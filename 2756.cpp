#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int common(int x, int y)
{
	if (x == y) return x;
	if (x > y) return common(x/2, y);
	return common(x, y/2);
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << common(x, y) << endl;
	return 0;
}
