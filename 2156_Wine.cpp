#include <iostream>
#include <algorithm>
using namespace std;

int n;
int wine;
int sum[10001][4];

int main() {
	cin >> n;
	cin >> wine;
	sum[1][1] = wine;
	for (int i = 2; i <= n; i++) {
		cin >> wine;
		for (int j = 0; j < 3; j++) {
			sum[i][0] = max(sum[i][0], sum[i - 1][j]);
			sum[i][j + 1] = max(sum[i][j + 1], sum[i - 1][j] + wine);
		}
	}
	cout << max(sum[n][0], max(sum[n][1], sum[n][2]));
	return 0;
}