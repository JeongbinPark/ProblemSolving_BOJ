#include <iostream>
using namespace std;

int T, N;
long long dp[50] = { 1, 1 };

int main() {
	for (int i = 2; i < 50; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		for (int j = i - 2; j >= 0; j--)
			dp[i] += 2 * dp[j];
		for (int j = i - 2; j >= 0; j -= 2)
			dp[i] += dp[j];
	}

	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}
/*
���� ����� �������� 5���� ����
|
|

��
��
��
��

��
��
|

|
��
��

��
|
��

�׷��� ���� dp �̿��ؼ� ���

*/
