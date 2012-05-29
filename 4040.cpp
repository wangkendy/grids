#include <iostream>

using namespace std;

int main()
{
	int N;
	int count;
	int total_count;
	double price;
	double total_price;
	double strategy1, strategy2;
	cin >> N;
	while (N != -1) {
		total_count = 0;
		total_price = 0.0;
		for(int i = 0; i < N; i++) {
			cin >> count >> price;
			total_count += count;
			total_price += count * price;
		}
		if (total_price > 100) {
			strategy1 = total_price;
		} else {
			strategy1 = total_price + 20;
		}
		if (total_count > 3) {
			strategy2 = total_price * 0.95 + 20;
		} else {
			strategy2 = total_price + 20;
		}
		if (strategy1 < strategy2)
			cout << strategy1 << endl;
		else
			cout << strategy2 << endl;
		cin >> N;
	}
	return 0;
}
