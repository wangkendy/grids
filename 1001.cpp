#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& vec, int dot)
{
	int i = 0;
	dot = vec.size() - dot - 1;
	while (vec[i++] == 0);
	i--; // The first none zero index
	int j = vec.size() - 1;
	while (vec[j--] == 0);
	j++; // The last none zero index
	if (i > dot) {
		cout << '.';
		i = dot + 1;
	}
	if (j <= dot) {
		j = dot;
	}
	for(; i <= j; i++) {
		cout << vec[i];
		if (dot == i && i != j)
			cout << '.';
	}
	cout << endl;
}

vector<int> multiply(const vector<int>& num1, const vector<int>& num2)
{
	vector<int> raw(num1.size() + num2.size() - 1, 0);
	for(int i = 0; i < num1.size(); i++) {
		for(int j = 0; j < num2.size(); j++) {
			raw[i+j] += num1[i] * num2[j];
		}
	}
	vector<int> res(raw.size() + 1);
	int c = 0;
	for (int i = res.size() - 1; i >= 1; i--) {
		res[i] = (raw[i-1] + c) % 10;
		c = (raw[i-1] + c) / 10;
	}
	res[0] = c;
	return res;
}

int main()
{
	string R;
	int n;
	int dot;
	while (cin >> R >> n) {
		dot = 5 - R.find('.');
		dot *= n;
		vector<int> num;
		vector<int> product;
		for (int i = 0; i < 6; i++) {
			if (R[i] != '.')
				num.push_back(R[i] - '0');
		}
		product.push_back(1);
		while (n) {
			if (n&1) {
				product = multiply(product, num);
			}
			n >>= 1;
			num = multiply(num, num);
		}
		print_vector(product, dot);
	}
	return 0;
}
