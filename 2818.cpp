#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int val;
	int loop;
	struct Node *next;
};

int main()
{
	int n, k;
	string msg;
	cin >> n;
	while (n) {
		vector<int> perm(n);
		vector<struct Node> state(n);
		for (int i = 0; i < n; i++) {
			cin >> perm[i];
			state[i].val = i + 1;
			state[i].loop = 0;
			state[i].next = &state[perm[i]-1];
		}
		
		for (int i = 0; i < n; i++) {
			if (state[i].loop == 0) {
				int val = state[i].val;
				struct Node *p = &state[i];
				int loop = 1;
				while (p->next->val != val) {
					p = p->next;
					loop++;
				}
				p = &state[i];
				while (p->next->val != val) {
					p->loop = loop;
					p = p->next;
				}
				p->loop = loop;
			}
		}
		
		cin >> k;
		while (k) {
			getline(cin, msg);
			msg.erase(0, 1);
			int length = msg.length();
			for (int i = 0; i < n - length; i++) {
				msg.push_back(' ');
			}
			
			vector<int> new_perm(n);
			for (int i = 0; i < n; i++) {
				int loop = state[i].loop;
				int walk = k % loop;
				struct Node *p = &state[i];
				while (walk--) {
					p = p->next;
				}
				new_perm[i] = p->val;
			}

			string new_msg(msg.size(), '0');
			for (int j = 0; j < n; j++) {
				new_msg[new_perm[j]-1] = msg[j];	
			}
			cout << new_msg << endl;
			cin >> k;
		}
		cout << endl;
		cin >> n;
	}
}
