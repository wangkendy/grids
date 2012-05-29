/*
 *source: http://poj.grids.cn/practice/2819
 *tag: string manipulation
 *
 */

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
	vi k(3, 0);
	cin >> k[0] >> k[1] >> k[2];
	while (k[0]+k[1]+k[2]) { // End with k1=k2=k3=0
		string input;
		vvi index(3, vi());
		cin >> input;
		int len = input.length();
		for (int i = 0; i < len; i++) {
			if (input[i] >= 'a' && input[i] <= 'i')
				index[0].push_back(i);
			else if (input[i] >= 'j' && input[i] <= 'r')
				index[1].push_back(i);
			else
				index[2].push_back(i);	
		}
	
		vvi new_index(3, vi());
		for (int i = 0; i < 3; i++) {
			int length = index[i].size();
			for (int j = 0; j < length; j++) {
				new_index[i].push_back(index[i][(j+k[i])%length]);
			}
		}
		/*
		for (int i = 0; i < 3; i++) {
			int length = new_index[i].size();
			for (int j = 0; j < length; j++) {
				cout << new_index[i][j] << " ";
			}
			cout << endl;
		}*/

		string str(len, '0');
		int j, m, l;
		j = m = l = 0;
		for (int i = 0; i < len; i++) {
			if (input[i] >= 'a' && input[i] <= 'i')
				str[new_index[0][j++]] = input[i];
			else if (input[i] >= 'j' && input[i] <= 'r')
				str[new_index[1][m++]] = input[i];
			else str[new_index[2][l++]] = input[i];
		}

		cout << str << endl;
		
		cin >> k[0] >> k[1] >> k[2];
	}
	return 0;
}
