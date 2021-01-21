//16�ٿ� min �� ���� dp[i][j] = dp[i][j - (i*i)] + 1; ��� �� ��,
//Greedy�� ������� 43�̸� 25+9+9�� 3�̾ƴ� 36+4+1+1+1�� ����.
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[317][100001] = { 0 };
int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++)
		dp[1][i] = i;
	for (int i = 2; i <= (int)sqrt(N); i++)
		for (int j = 0; j <= N; j++) {
			if (i*i > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = min(dp[i - 1][j], dp[i][j - (i*i)] + 1);
		}
	cout << dp[(int)sqrt(N)][N];
	return 0;
}