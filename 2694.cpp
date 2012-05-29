#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

double exp() {
	string s;
	cin >> s;
	switch(s[0]) {
		case '+': return exp() + exp();
		case '-': return exp() - exp();
		case '*': return exp() * exp();
		case '/': return exp() / exp();
		default: return atof(s.c_str());
	}
}

int main()
{
	printf("%f\n", exp());
	return 0;
}
