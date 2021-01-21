#include <iostream>
using namespace std;

int main() {
	int T, N, M;
	int data[30][30];
	for (int i = 0; i < 30; i++)
		data[1][i] = i;
	for (int i = 2; i < 30; i++) {
		for (int j = i; j < 30; j++) {
			int sum = 0;
			for (int k = i - 1; k < j; k++)
				sum += data[i-1][k];
			data[i][j] = sum;
		}
	}

	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << data[N][M] << "\n";
	}
	return 0;
}