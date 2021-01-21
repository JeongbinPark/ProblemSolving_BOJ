#include <iostream>
#include <algorithm>
using namespace std;

int N, K, nubmer, result;
int num[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}
	result = num[K];
	for (int i = K + 1; i <= N; i++)
		result = max(result, num[i] - num[i - K]);
	cout << result;
	return 0;
}
