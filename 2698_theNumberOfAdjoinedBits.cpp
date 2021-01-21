/* 문제에서 출력 값은  2,147,483,647보다 작거나 같다고 했지만...
계산과정에서 문제가 생길 수 있으니 bigInt 사용함.
#include <iostream>
#define MAX 1000000000000	//12
using namespace std;

int t, n, k;
long long cnt_low[101][101], cnt_high[101][101], potential_low[101][101], potential_high[101][101];

int main() {
	potential_low[1][0] = 1;
	for (int i = 2; i <= 100; i++) {
		potential_low[i][0] = potential_low[i - 1][0] + potential_low[i - 2][0];
		potential_high[i][0] = potential_high[i - 1][0] + potential_high[i - 2][0] + potential_low[i][0] / MAX;
		potential_low[i][0] %= MAX;
		for (int j = 1; j <= 100; j++) {

			if (potential_high[i - 1][j - 1]) {
				cnt_low[i][j] = 2 * cnt_low[i - 1][j] + potential_low[i - 1][j - 1] - potential_low[i - 1][j] + MAX;
				cnt_high[i][j] = 2 * cnt_high[i - 1][j] + potential_high[i - 1][j - 1] - potential_high[i - 1][j] + cnt_low[i][j] / MAX - 1;
				cnt_low[i][j] %= MAX;
			}
			else {
				cnt_low[i][j] = 2 * cnt_low[i - 1][j] + potential_low[i - 1][j - 1] - potential_low[i - 1][j];
				cnt_high[i][j] = 2 * cnt_high[i - 1][j] + potential_high[i - 1][j - 1] - potential_high[i - 1][j] + cnt_low[i][j] / MAX;
				cnt_low[i][j] %= MAX;
			}

			if (cnt_high[i][j]) {
				potential_high[i][j] = cnt_high[i][j] - cnt_high[i - 1][j] - 1;
				potential_low[i][j] = MAX +  cnt_low[i][j] - cnt_low[i - 1][j];
				potential_high[i][j] += potential_low[i][j] / MAX;
				potential_low[i][j] %= MAX;
			}
			else potential_low[i][j] = cnt_low[i][j] - cnt_low[i - 1][j];
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (cnt_high[n][k]) {
			cout << cnt_high[n][k];
			cout.width(12);
			cout.fill('0');
			cout << cnt_low[n][k] << "\n";
		}
		else cout << cnt_low[n][k] << "\n";
	}
	return 0;
}
*/

//출력 값의 범위가 2,147,483,647 이하이다
//문제 특성상 row가 클 수록, col이 작을 수록 dp의 수가 커지므로
//출력 값의 범위를 벗어나는 수는 무시해도 상관없다.
//그러므로 integer만으로 해결가능하다.
#include <iostream>
using namespace std;

int t, n, k;
int dp[101][101][2] = { 1 };

int main() {
	for(int i = 1; i <= 100; i++)
		for (int j = 0; j < i; j++) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];
		}
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << "\n";
	}
	return 0;
}
