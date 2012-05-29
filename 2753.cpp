#include <iostream>

using namespace std;

int fabo[21];

int f(int a) {
	static int index = 2;
	if (a > index){
		for(int i = index + 1; i <= a; i++)
			fabo[i] = fabo[i-1] + fabo[i-2];
		index = a;
	}
	return fabo[a];
}

int main()
{
	fabo[1] = 1;
	fabo[2] = 1;
	int N, a;
	cin >> N;
	while (N--) {
		cin >> a;
		cout << f(a) << endl;
	}
	return 0;
}
