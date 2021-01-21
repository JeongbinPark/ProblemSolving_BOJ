#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, tmp, two = 0, five = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		tmp = i;
		while (tmp && tmp % 2 == 0) {
			two++;
			tmp /= 2;
		}
		while (tmp && tmp % 5 == 0) {
			five++;
			tmp /= 5;
		}
	}
	cout << min(two, five);
	return 0;
}