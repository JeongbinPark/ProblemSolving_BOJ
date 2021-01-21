/*
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int find(int);

int N, sum;
int s[1001], ss[1001][1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++) {
			ss[i][j] = abs(s[i] - s[j]);
		}
	cout << find(0);
	return 0;
}

int find(int n) {
	int maxi = 0;
	for (int i = n; i < N; i++) {
		maxi = max(maxi, ss[n][i] + find(i + 1));
	}
	return maxi;
}
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int find(int);

int N, sum;
int s[1001], ss[1001][1001], dp[1001];

int main() {
	cin >> N;
	fill(dp, dp + N, -1);
	for (int i = 0; i < N; i++)
		cin >> s[i];
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++) {
			ss[i][j] = abs(s[i] - s[j]);
		}
	cout << find(0);
	return 0;
}

int find(int n) {
	if (dp[n] != -1) return dp[n];
	int maxi = 0;
	for (int i = n; i < N; i++) {
		maxi = max(maxi, ss[n][i] + find(i + 1));
	}
	dp[n] = maxi;
	return maxi;
}
