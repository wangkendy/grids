#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Metal {
	int weight;
	int value;
};

struct MetalCompare {
	bool operator()(const struct Metal& lhs, const struct Metal& rhs) {
		return lhs.value * rhs.weight < rhs.value * lhs.weight;
	}
};

int main()
{
	int N;
	cin >> N;
	int maxw;
	int kind;
	double total_value;
	while (N--) {
		cin >> maxw >> kind;
		vector<Metal> metals(kind);
		for (int i = 0; i < kind; i++)
			cin >> metals[i].weight >> metals[i].value;
		sort(metals.rbegin(), metals.rend(), MetalCompare());

		total_value = 0.0;
		for (int i = 0; i < kind; i++) {
			if (maxw >= metals[i].weight) {
				total_value += metals[i].value;
				maxw -= metals[i].weight;
			} else {
				total_value += metals[i].value * 1.0 / metals[i].weight * maxw;
				break;
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << total_value << endl;
	}
	return 0;
}
