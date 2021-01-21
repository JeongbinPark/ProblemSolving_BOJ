#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, w, v, max_v = 0;
vector< pair<int, int> > product;
int dp[100001];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		product.push_back(make_pair(w, v));
	}
	fill(dp, dp + 100001, -1);
	dp[0] = 0;
	for (int i = 0; i < N; i++)
		for (int j = K; j >= 0; j--) {
			if (dp[j] != -1 && j + product[i].first <= K && dp[j + product[i].first] < dp[j] + product[i].second)
				dp[j + product[i].first] = dp[j] + product[i].second;
		}
	for (int i = 0; i <= K; i++)
		max_v = max(dp[i], max_v);

	cout << max_v;
	return 0;
}