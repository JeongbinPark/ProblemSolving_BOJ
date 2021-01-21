#include <iostream>
#include <algorithm>
#define INF 100000
using namespace std;

int n, k, c;
int min_coin[10002];

int main() {
	cin >> n >> k;
	fill(min_coin + 1, min_coin + k + 1, INF);
	while (n--) {
		cin >> c;
		for (int i = c; i <= 10000; i++) {
			min_coin[i] = min(min_coin[i], min_coin[i - c] + 1);
		}
	}
	cout << (min_coin[k] == INF ? -1 : min_coin[k]);
	return 0;
}