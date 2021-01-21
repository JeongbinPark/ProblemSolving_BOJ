#include <iostream>
#include <algorithm>
using namespace std;

int N, sum, tmp;
int dp[1000001];

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		sum = tmp = i;
		while (sum >9 && tmp) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (!dp[sum] || i < dp[sum]) dp[sum] = i;
	}
	cout << dp[N];
	return 0;
}
//사실 발견하면 끝이기 때문에 dp 안쓰고 바로 탈출해서 해당값 비교하면됨.