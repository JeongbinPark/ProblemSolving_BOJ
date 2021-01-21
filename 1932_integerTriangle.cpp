#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[501][501];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> num[i][j];
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++)
			num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);
	}
	cout << num[0][0];
	return 0;
}
