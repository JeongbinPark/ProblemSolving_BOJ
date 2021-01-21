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
//��� �߰��ϸ� ���̱� ������ dp �Ⱦ��� �ٷ� Ż���ؼ� �ش簪 ���ϸ��.