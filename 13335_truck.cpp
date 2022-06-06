#include <iostream>
#include <queue>
using namespace std;

int N, W, L;
int trucks[1000];

int main() {
	cin >> N >> W >> L;
	for (int i = 0; i < N; i++) {
		cin >> trucks[i];
	}
	int truckIdx = 0 , sum = 0;
	int times = 0;
	queue<int> q;
	while (++times) {
		if (truckIdx == N) {
			break;
		}
		if ((int)q.size() == W) {
			sum -= q.front();
			q.pop();
		}
		if (sum + trucks[truckIdx] <= L) {
			sum += trucks[truckIdx];
			q.push(trucks[truckIdx++]);
		}
		else {
			q.push(0);
		}
	}
	cout << times + W - 1;
	return 0;
}