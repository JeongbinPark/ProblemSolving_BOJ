#include <iostream>
#include <algorithm>
using namespace std;

int N, S, M, V;
bool vol[51][1001];

int main() {
	cin >> N >> S >> M;
	vol[0][S] = true;

	for (int i = 1; i <= N; i++) {
		cin >> V;
		for (int j = 0; j <= M; j++) {
			if (vol[i - 1][j]) {
				if (j + V >= 0 && j + V <= M) vol[i][j + V] = true;
				if (j - V >= 0 && j - V <= M) vol[i][j - V] = true;
			}
		}
	}
	for (int i = M; i >= 0; i--) {
		if (vol[N][i]) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}