#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int site_cnt, pass_cnt, accu_cnt;
	cin >> site_cnt >> pass_cnt >> accu_cnt;
	vector<int> distance(site_cnt - 1);
	vector<int> latest(site_cnt, 0);
	vector<int> earlest(site_cnt, 0);
	vector<int> seg_cnt(site_cnt, 0);
	vector<int> arrive_cnt(site_cnt, 0);
	vector<int> arrive_time(site_cnt, 0);
	vector< pair<int, int> > seg_pair(site_cnt);
	vector< pair<int, int> > arrive_pair(site_cnt);
	vector< pair<int, pair<int, int> > > passenger(pass_cnt);
	for (int i = 0; i < site_cnt - 1; i++)
		cin >> distance[i];

	for (int i = 0; i < pass_cnt; i++) {
		int ti, ai, bi;
		cin >> ti >> ai >> bi;
		if (ti > earlest[ai - 1]) {
			earlest[ai - 1] = ti;
		}
		arrive_cnt[bi - 1]++;
		for (int j = ai - 1; j < bi - 1; j++) {
			seg_cnt[j] += 1;
		}
		passenger[i] = make_pair(ti, make_pair(ai, bi));
	}
	for (int i = 0; i < site_cnt; i++) {
		seg_pair[i] = make_pair(seg_cnt[i], i);
	}
	sort(seg_pair.rbegin(), seg_pair.rend());

	for (int i = 0; i < site_cnt; i++) {
		arrive_pair[i] = make_pair(arrive_cnt[i], i);
	}
	sort(arrive_pair.rbegin(), arrive_pair.rend());
	
	for (int i = 0; i < site_cnt - 1; i++) {
		int index = seg_pair[i].second;
		while (accu_cnt > 0) {
			if (earlest[index] + distance[index] > earlest[index + 1] && distance[index] > 1) {
				accu_cnt--;
				distance[index]--;
			} else {
				break;
			}
		}
		if (accu_cnt == 0) break;
	}

	for (int i = 0; i < site_cnt; i++) {
		int index = arrive_pair[i].second;
		while (accu_cnt > 0) {
			if (distance[index - 1] > 1) {
				accu_cnt--;
				distance[index - 1]--;
			} else {
				break;
			}
		}
		if (accu_cnt == 0) break;
	}

	arrive_time[0] = earlest[0];
	for (int i = 1; i < site_cnt; i++) {
		int takeoff_time = max(earlest[i - 1], arrive_time[i - 1]);
		arrive_time[i] = takeoff_time + distance[i - 1];
	}

	int total_time = 0;
	for (int i = 0; i < pass_cnt; i++) {
		int ti = passenger[i].first;
		int bi = passenger[i].second.second;
		total_time += arrive_time[bi - 1] - ti;
	}
	cout << total_time << endl;
	/*
	cout << "arrive time: ";
	for (int i = 0; i < site_cnt; i++) {
		cout << arrive_time[i] << ' ';
	}
	cout << endl;

	cout << "arrive count: ";
	for (int i = 0; i < site_cnt; i++) {
		cout << arrive_cnt[i] << ' ';
	}
	cout << endl;

	cout << "arrive pair: ";
	for (int i = 0; i < site_cnt; i++) {
		cout << arrive_pair[i].second << ", " << arrive_pair[i].first << endl;
	}
	cout << endl;

	for (int i = 0; i < site_cnt; i++) {
		cout << seg_pair[i].first << ", " << seg_pair[i].second << endl;
	}
	for (int i = 0; i < site_cnt; i++) {
		cout << earlest[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < site_cnt; i++) {
		cout << seg_cnt[i] << ' ';
	}*/
	return 0;

}
