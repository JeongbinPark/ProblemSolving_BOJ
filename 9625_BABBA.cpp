#include <iostream>
using namespace std;

int main() {
	int A = 0, B = 1;
	int c;

	cin >> c;

	for (int i = 2; i <= c; i++) {
		swap(B, A);
		B += A;
	}

	cout << A << " " << B;
	return 0;
}