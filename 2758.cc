#include <iostream>

using namespace std;

const int MOD = 1000;

int fibo[1000001];

int fibonacci(int num) {
	static int index = 2;
	if (num > index) {
		for(int i = index + 1; i <= num; i++)
			fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
		index = num;
	}
	return fibo[num];
}

int main()
{
	int N;
	int num;
	cin >> N;
	fibo[1] = 1;
	fibo[2] = 1;
	while (N--) {
		cin >> num;
		cout << fibonacci(num) << endl;
	}
	return 0;
}
