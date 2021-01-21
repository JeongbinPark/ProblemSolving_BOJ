#include <iostream>
#include <algorithm>
using namespace std;

int N;
int cost[1001][3];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	for (int i = N - 2; i >= 0; i--) {
		cost[i][0] += min(cost[i + 1][1], cost[i + 1][2]);
		cost[i][1] += min(cost[i + 1][0], cost[i + 1][2]);
		cost[i][2] += min(cost[i + 1][0], cost[i + 1][1]);
	}
	cout << min(cost[0][0], min(cost[0][1], cost[0][2]));
	return 0;
}