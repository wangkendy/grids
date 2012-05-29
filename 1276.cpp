#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int cash, N;
	int n, d;
	while (cin >> cash >> N) {
		vector< pair<int, int> > money(N);
		for (int i = 0; i < N; i++) {
			cin >> n >> d;
			money[i] = make_pair(n, d);
		}
		if (N == 0 || cash == 0) {
			cout << 0 << endl;
			continue;
		}
		
		/*
		vector<int> pos_money;
		for (int i = 0; i < N; i++) {
			n = money[i].first;
			d = money[i].second;
			int cur_size = pos_money.size();
			for (int k = 1; k <= n; k++) {
				for (int j = 0; j < cur_size; j++) {
					pos_money.push_back(pos_money[j] + k * d);
				}
				pos_money.push_back(k*d);
			}
		}*/
		set<int> money_set;
		for (int i = 0; i < N; i++) {
			n = money[i].first;
			d = money[i].second;
			vector<int> temp(money_set.begin(), money_set.end());
			for (int k = 1; k <= n; k++) {
				for (int j = 0; j < temp.size(); j++) {
					int m = temp[j] + k * d;
					if (m <= cash)
						money_set.insert(m);
					else break;
				}
				money_set.insert(k*d);
			}
		}
		vector<int> pos_money(money_set.begin(), money_set.end());
		
		/*
		set<int> money_set(pos_money.begin(), pos_money.end());
		vector<int> money_vec(money_set.begin(), money_set.end());
		int index = money_vec.size() - 1;
		while (index >= 0 && money_vec[index] > cash) {
			index--;
		}
		if (index < 0) cout << 0 << endl;
		else cout << money_vec[index] << endl;
		*/
		
		//sort(pos_money.begin(), pos_money.end());
		int index = pos_money.size() - 1;
		while (index >= 0 && pos_money[index] > cash) {
			index--;
		}
		if (index < 0) cout << 0 << endl;
		else cout << pos_money[index] << endl;
	}
	return 0;
}
