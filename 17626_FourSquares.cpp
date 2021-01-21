#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
bool dp[50010][4] = { false };

int main() {
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++) {
		dp[i*i][0] = true;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k <= 50000; k++) {
				if (dp[k][j] && i*i + k <= 50000) dp[i*i + k][j + 1] = true;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (dp[n][i]) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}
//�׳� ���� 0~50000 for�� 4�� �����°� ����
//���� n�̸� ����ϰ� return