#include <iostream>
#include <cmath>
using namespace std;

void dfs(int, int);

int n;
bool isPrime;

int main() {
	cin >> n;
	dfs(2, 1), dfs(3, 1), dfs(5, 1), dfs(7, 1);
	return 0;
}

void dfs(int number, int level) {
	if (level >= n) {
		cout << number << "\n";
		return;
	}
	for (int i = 0; i < 10; i++) {
		isPrime = true;
		for (int j = 2; j <= (int)sqrt(number * 10 + i); j++) {
			if ((number * 10 + i) % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) dfs(number * 10 + i, level + 1);
	}
	return;
}