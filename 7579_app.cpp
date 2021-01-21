/* 시간 초과 나올거 같다. 돌려 보진 않았음
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void calc(int);

vector< pair<int, int> > app;
int N, M, m, c;
int memories[100];
int memory, cost, min_cost = 10000001;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> memories[i];
	for (int i = 0; i < N; i++)
	{
		m = memories[i];
		cin >> c;
		app.push_back(make_pair(m, c));
	}
	sort(app.begin(), app.begin() + N);
	for (int i = 0; i < N; i++) {
		memory = cost = 0;
		calc(i);
	}
	cout << min_cost;
	return 0;
}
void calc(int n) {
	if (memory >= M) {
		min_cost = min(min_cost, cost);
	}
	if (n >= N) return;
	memory += app[n].first;
	cost += app[n].second;
	for (int i = n + 1; i <= N; i++)
		calc(i);
	return;
}
*/
//냅색
//cost를 index로 잡고, 더 큰 메모리가 있으면 업데이트
//해당 노드가 있고 없고에 따라 dp 진행
//ex) i==0일때 첫번째 노드가 포함되면 dp[30]에 포함되지 않으면 dp[0]
//		i==1, 30+10, 30, 10, 0
//노드 기준으로 1개->2개->4개->...->2^n개
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int memories[100], cost[100];
int dp[10001];
int min_m = 10000001;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> memories[i];
	for (int i = 0; i < N; i++)
		cin >> cost[i];
	fill(dp, dp + 10001, -1);
	dp[0] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 10000; j >= 0; j--)
			if (dp[j] != -1 && dp[j + cost[i]] < dp[j] + memories[i]) dp[j + cost[i]] = dp[j] + memories[i];
	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M && i < min_m) min_m = i;
	}
	cout << min_m;
	return 0;
}