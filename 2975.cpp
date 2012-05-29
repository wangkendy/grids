#include <iostream>

using namespace std;

int main()
{
	char map[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	string start;
	string end;
	string input;
	
	getline(cin, start);
	while (start != "ENDOFINPUT") {
		getline(cin, input);
		for (int i = 0; i < input.length(); i++) {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				input[i] = map[input[i]-'A'];
			}
		}
		cout << input << endl;
		getline(cin, end);
		getline(cin, start);
	}
	return 0;
}
