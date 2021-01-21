#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, num, pre[5001], curr[5001];
vector<int> v1, v2;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v1.push_back(num);
		v2.push_back(num);
	}
	reverse(v2.begin(), v2.end());
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (v1[i - 1] == v2[j - 1]) {
				curr[j] = pre[j - 1] + 1;
			}
			else curr[j] = max(curr[j - 1], pre[j]);
		}
		if (curr[i] < 0)
			cout << "";
		memcpy(pre, curr, sizeof(int) * (N + 1));
	}
	cout << N - curr[N];
	return 0;
}