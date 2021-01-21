#include <iostream>
using namespace std;

int N, M, a, b;
int num[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}
	cin >> M;
	while (M--) {
		cin >> a >> b;
		cout << num[b] - num[a - 1] << "\n";
	}
	return 0;
}