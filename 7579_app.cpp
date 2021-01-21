/* �ð� �ʰ� ���ð� ����. ���� ���� �ʾ���
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
//����
//cost�� index�� ���, �� ū �޸𸮰� ������ ������Ʈ
//�ش� ��尡 �ְ� ���� ���� dp ����
//ex) i==0�϶� ù��° ��尡 ���ԵǸ� dp[30]�� ���Ե��� ������ dp[0]
//		i==1, 30+10, 30, 10, 0
//��� �������� 1��->2��->4��->...->2^n��
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