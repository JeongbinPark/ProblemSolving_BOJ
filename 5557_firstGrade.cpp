#include <iostream>
using namespace std;

int N, num;
long long counter[100][21];

int main() {
	cin >> N;
	cin >> num;
	counter[0][num] = 1;
	for (int i = 0; i < N - 2; i++) {
		cin >> num;
		for (int j = 0; j <= 20; j++) {
			if (counter[i][j]) {
				if (j + num <= 20) counter[i + 1][j + num] += counter[i][j];
				if (j - num >= 0) counter[i + 1][j - num] += counter[i][j];
			}
		}
	}
	cin >> num;
	cout << counter[N - 2][num];
	return 0;
}