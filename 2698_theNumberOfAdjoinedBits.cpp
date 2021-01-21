/* �������� ��� ����  2,147,483,647���� �۰ų� ���ٰ� ������...
���������� ������ ���� �� ������ bigInt �����.
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

//��� ���� ������ 2,147,483,647 �����̴�
//���� Ư���� row�� Ŭ ����, col�� ���� ���� dp�� ���� Ŀ���Ƿ�
//��� ���� ������ ����� ���� �����ص� �������.
//�׷��Ƿ� integer������ �ذᰡ���ϴ�.
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
