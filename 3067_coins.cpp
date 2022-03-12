#include <iostream>
#include <cstring>
using namespace std;

int T;

int main() {
	cin >> T;
	while (T--) {
		int N = 0, M = 0;
		int costs[20];
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> costs[i];
		}
		cin >> M;

		int nums[21][10001];
		memset(nums, 0, sizeof(nums));

		for (int i = 1; i <= N; i++) {
			int cost = costs[i-1];
			nums[i][0] = 1;
			for (int j = 1; j <= M; j++) {
				nums[i][j] = nums[i - 1][j];
				if(j - cost >= 0) nums[i][j] += nums[i][j - cost];
			}
		}
		cout << nums[N][M] << "\n";

	}
	return 0;
}