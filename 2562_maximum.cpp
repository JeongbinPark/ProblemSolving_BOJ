#include <iostream>
using namespace std;

int main() {
	int n, max, index = 1;
	cin >> max;
	for (int i = 2; i <= 9; i++) {
		cin >> n;
		if (n>max) {
			max = n;
			index = i;
		}
	}
	cout << max << "\n" << index;
	return 0;
}