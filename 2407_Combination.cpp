#include <iostream>
#define MAX 1000000000000000000
using namespace std;

int n, m;
long long high[101][101], low[101][101] = { 1 };
long long tmp;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		low[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			low[i][j] = low[i - 1][j - 1] + low[i - 1][j];
			high[i][j] = high[i - 1][j - 1] + high[i - 1][j] + low[i][j] / MAX;
			low[i][j] %= MAX;
		}
	}
	if (high[n][m]) {
		cout << high[n][m];
		cout.width(18);
		cout.fill('0');
		cout << low[n][m];
	}
	else cout << low[n][m];
	return 0;
}
