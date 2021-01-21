#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, n;
	cin >> N;
	cin >> n;
	int minimum = n, maximum = n;
	while (--N) {
		cin >> n;
		minimum = min(n, minimum);
		maximum = max(n, maximum);
	}
	cout << minimum << " " << maximum;
	return 0;
}