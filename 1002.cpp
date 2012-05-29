#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
	char cn[] = {0, 0, 0, // '-' and two other
		     0, 1, 2, 3, 4, 5, 6, 7, 8, 9, //0-9
	   	     0, 0, 0, 0, 0, 0, 0,
		     2, 2, 2,//A,B,C
	             3, 3, 3,
		     4, 4, 4,
                     5, 5, 5,
		     6, 6, 6,
		     7, 7, 7, 7,
                     8, 8, 8,
 		     9, 9, 9};

	int N, j, count = 0;
	string input;
	//map<string, int> tel_count;
	//string tel(8, '0');
	map<int, int> tel_count;
	int phone;
	cin >> N;
	while (N--) {
		cin >> input;
		j = 0;
		phone = 0;
		for (int i = 0; i < input.size(); i++) {
			phone =  phone * 10 * bool(input[i] - '-') + cn[input[i] - '-'];
		}
		tel_count[phone] += 1;
	}
	for (map<int, int>::iterator it = tel_count.begin(); it != tel_count.end(); it++) {
		if (it->second > 1) {
			count++;
			int tel = it->first;
			printf("%03d-%04d %d\n", tel / 10000, tel % 10000, it->second);
		}
	}
	if (count == 0) {
		cout << "No duplicates." << endl;
	} 
	return 0;
}
