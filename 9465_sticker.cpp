#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int r1[100001], r2[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		fill(r1, r1 + N + 1, 0);
		fill(r2, r2 + N + 1, 0);
		for (int i = 0; i < N; i++)
			cin >> r1[i];
		for (int i = 0; i < N; i++)
			cin >> r2[i];
		for (int i = N - 2; i >= 0; i--) {
			r1[i] += max(r2[i + 1], r2[i + 2]);
			r2[i] += max(r1[i + 1], r1[i + 2]);
		}
		cout << max(r1[0], r2[0]) << "\n";
	}
	return 0;
}
