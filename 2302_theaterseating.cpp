#include <iostream>
using namespace std;

int N, M, vip;
int nums[41][2] = { 1 };
int sum = 1;
int gap;

int main() {
	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		nums[i][0] = nums[i - 1][0] + nums[i - 1][1];
		nums[i][1] = nums[i - 1][0];
	}

	int prev = 0;
	for(int i = 0; i <= M; i++) {
		if (i == M) vip = N+1;
		else cin >> vip;
		gap = vip - prev - 1;
		if (gap > 0) sum *= (nums[gap - 1][0] + nums[gap - 1][1]);
		prev = vip;
	}
	cout << sum;
	return 0;
}