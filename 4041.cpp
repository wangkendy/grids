#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1;
	vector< vector<int> > A(x1, vector<int>(y1));
	for(int i = 0; i < x1; i++) {
		for(int j = 0; j < y1; j++) {
			cin >> A[i][j];
		}
	}

	cin >> x2 >> y2;
	vector< vector<int> > B(x2, vector<int>(y2));

	for(int i = 0; i < x2; i++) {
		for(int j = 0; j < y2; j++) {
			cin >> B[i][j];
		}
	}

	if (y1 == x2) { // A, B could multiply
		vector< vector<int> > C(x1, vector<int>(y2));
		for(int i = 0; i < x1; i++) {
			for(int j = 0; j < y2; j++) {
				C[i][j] = 0;
				for(int k = 0; k < y1; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		for(int i = 0; i < y2; i++) {
			for(int j = 0; j < x1; j++) {
				cout << setw(5) << C[j][i];
			}
			cout << endl;
		}
	} else {
		for(int i = 0; i < y1; i++) {
			for(int j = 0; j < x1; j++) {
				cout << setw(5) << A[j][i];
			}
			cout << endl;
		}
	}

	return 0;
}
