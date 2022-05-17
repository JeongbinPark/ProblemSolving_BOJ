#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int unit[20];
int money[10001];

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> unit[i];
		}
		cin >> M;
		memset(money, 0, sizeof(money));
		money[0] = 1;
		for (int i = 0; i < N; i++) {
			int currUnit = unit[i];
			for (int j = currUnit; j <= M; j++) {
				money[j] += money[j - currUnit];
			}
		}
		cout << money[M] << "\n";
	}
	return 0;
}