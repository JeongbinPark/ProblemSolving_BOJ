#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, num, cnt = 0;
	bool isPrime;
	cin >> N;
	while (N--) {
		cin >> num;
		isPrime = true;
		for (int i = 2; i <= sqrt(num); i++)
			if (num%i == 0) {
				isPrime = false;
				break;
			}
		if (num != 1 && isPrime) cnt++;
	}
	cout << cnt;
	return 0;
}