#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int find(int, int);

int n;
int arr[MAX], dp[MAX];
int lis = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		lis = max(lis, find(i, 0));
	cout << lis;
	return 0;
}
int find(int index, int level) {
	if (index >= n) return 0;
	if (dp[index]) return dp[index];
	dp[index]++;
	for (int i = index + 1; i <= n; i++) {
		if (arr[index] < arr[i] || i == n) dp[index] = max(dp[index], 1 + find(i, level + 1));
	}
	return dp[index];
}