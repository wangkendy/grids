#include <iostream>
#include <vector>

using namespace std;
const int NEINFINITE = -100000;

typedef vector<int> vi;
typedef vector<vi> vvi;

int max_sub_seq(const vi& seq)
{
	int max = NEINFINITE;
	int sum = 0;
	for (int i = 0; i < seq.size(); i++) {
		if (sum > 0) sum += seq[i];
		else sum = seq[i];
		if (sum > max) max = sum;
	}
	return max;
}

int max_sub_matrix(const vvi& mat)
{
	int max = NEINFINITE;
	int sum = 0;
	int len = mat.size();
	vi array(len);

	for (int i = 0; i < len; i++) {
		for(int k = 0; k < len; k++) array[k] = 0;
		for(int j = i; j < len; j++) {
			for (int k = 0; k < len; k++) {
				array[k] += mat[j][k];
			}
			sum = max_sub_seq(array);
			if (sum > max) max = sum;
		}
	}
	return max;
}

int main()
{
	int N;
	cin >> N;
	vvi a(N, vi(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	cout << max_sub_matrix(a) << endl;
	return 0;
}
