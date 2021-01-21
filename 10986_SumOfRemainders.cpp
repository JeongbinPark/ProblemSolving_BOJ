/*
#include <iostream>
using namespace std;

int N, M;
long long cnt;
long long num[1000001], sum[1000001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
		num[i] %= M;

		sum[num[i]]++;
	}
	cnt += sum[0];
	for (int i = 0; i < M; i++) {
		cnt += sum[i] * (sum[i] - 1) / 2;
	}
	cout << cnt;
}
*/
#include <iostream>
using namespace std;

int N, M, num, sum;
long long remainders[1001], cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		sum += num;
		sum %= M;

		remainders[sum]++;
	}
	cnt += remainders[0];
	for (int i = 0; i < M; i++) {
		cnt += remainders[i] * (remainders[i] - 1) / 2;
	}
	cout << cnt;
}
