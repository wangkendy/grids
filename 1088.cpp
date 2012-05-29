#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int R, C;
	cin >> R >> C;
	vector< vector<int> > matrix(R, vector<int>(C));
	vector< pair<int, pair<int, int> > > height(R*C);
	vector<int> length(R*C, 1);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> matrix[i][j];
			height[i*C+j] = make_pair(matrix[i][j], make_pair(i, j));
		}
	}
	sort(height.begin(), height.end());

	for (int k = 1; k < height.size(); k++) {
		int val, i, j, max = -1;
		int index;
		val = height[k].first;
		i = height[k].second.first;
		j = height[k].second.second;
		index = (i - 1) * C + j;
		if (i - 1 >= 0 && matrix[i - 1][j] < val && length[index] > max) max = length[index];
		index = i * C + j + 1;
		if (j + 1 < C && matrix[i][j+1] < val && length[index] > max) max = length[index];
		index = (i + 1) * C + j;
		if (i + 1 < R && matrix[i+1][j] < val && length[index] > max) max = length[index];
		index = i * C + j - 1;
		if (j - 1 >= 0 && matrix[i][j-1] < val && length[index] > max) max = length[index];
		index = i * C + j;
		if (max != -1)	length[index] = max + 1;	
	}

	cout << *max_element(length.begin(), length.end()) << endl;
	return 0;
}
