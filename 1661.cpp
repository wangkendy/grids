#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INFINITE = 1000000;

struct Board {
	int x1;
	int x2;
	int h;
};
struct BoardCompare{
	bool operator()(const struct Board& lhs, const struct Board& rhs){
		return lhs.h < rhs.h;	
	}
};

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, X, Y, maxHeight;
		cin >> N >> X >> Y >> maxHeight;
		vector<struct Board> boards(N + 1, Board());
		vector< pair<int, int> > time(N + 1, make_pair(0, 0));
		for(int i = 0; i < N; i++) {
			cin >> boards[i].x1;
			cin >> boards[i].x2;
			cin >> boards[i].h;
		}
		boards[N].x1 = X;
		boards[N].x2 = X;
		boards[N].h = Y;

		sort(boards.begin(), boards.end(), BoardCompare());

		int m;
		for (int i = 0; i <= N; i++) {
			m = -1;
			//time from the left hand side
			for(int j = i - 1; j >= 0; j--) {
				if (boards[j].x1 <= boards[i].x1 && boards[j].x2 >= boards[i].x1) {
					m = j;
					break;
				}
			}
			if (m != -1) { // There is a board under the current board
				if (boards[i].h - boards[m].h <= maxHeight) {
				time[i].first = boards[i].h - boards[m].h +
				min(time[m].first + boards[i].x1 - boards[m].x1, time[m].second + boards[m].x2 - boards[i].x1);
				} else {
					time[i].first = INFINITE;
				}
			} else {
				if (boards[i].h > maxHeight) {
					time[i].first = INFINITE;
				} else {
					time[i].first = boards[i].h;
				}
			}

			m = -1;
			//time from the right hand side
			for(int j = i - 1; j >= 0; j--) {
				if (boards[j].x1 <= boards[i].x2 && boards[j].x2 >= boards[i].x2) {
					m = j;
					break;
				}
			}

			if (m != -1) {
				if (boards[i].h - boards[m].h <= maxHeight) {
				time[i].second = boards[i].h - boards[m].h +
				min(time[m].first + boards[i].x2 - boards[m].x1, time[m].second + boards[m].x2 - boards[i].x2);
				} else {
					time[i].second = INFINITE;
				}
			} else {
				if (boards[i].h > maxHeight) {
					time[i].second = INFINITE;
				} else {
					time[i].second = boards[i].h;
				}
			}
		}
		cout << time[N].first << endl;
	}
	return 0;
}
