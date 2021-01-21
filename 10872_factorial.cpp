#include <iostream>
using namespace std;

int facto(int);

int main() {
	int n;
	cin >> n;
	cout << facto(n);
	return 0;
}

int facto(int n) {
	if (n == 0 || n == 1) return 1;
	else return n * facto(n - 1);
}