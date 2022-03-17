#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;

int N, S, minCnt = INF;
int p_s, p_e;
int num[100000];

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int sum = num[0];
	int cnt = 1;

	while (p_s < N && p_e < N) {
		if (sum >= S) {
			minCnt = min(minCnt, cnt);
			sum -= num[p_s];
			p_s++;
			cnt--;
		}
		else {
			p_e++;
			sum += num[p_e];
			cnt++;
		}
	}
	cout << (minCnt == INF ? 0 : minCnt);
	return 0;
}