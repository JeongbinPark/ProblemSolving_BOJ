//16줄에 min 비교 없이 dp[i][j] = dp[i][j - (i*i)] + 1; 라고 할 시,
//Greedy한 방법으로 43이면 25+9+9로 3이아닌 36+4+1+1+1이 나옴.
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