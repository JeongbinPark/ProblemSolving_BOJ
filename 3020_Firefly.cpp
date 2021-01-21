//prefix sum 이용
#include <iostream>
using namespace std;

int N, H, a, b, mini, cnt;
int up[500001], down[500001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		cin >> a >> b;
		up[a]++, down[b]++;
	}
	for (int i = H - 1; i > 0; i--) {
		up[i] += up[i + 1];
		down[i] += down[i + 1];
	}
	mini = up[1] + down[H];
	cnt = 1;
	for (int i = 2; i <= H; i++) {
		if (mini > up[i] + down[H - i + 1]) {
			mini = up[i] + down[H - i + 1];
			cnt = 1;
		}
		else if (mini == up[i] + down[H - i + 1])
			cnt++;
	}
	cout << mini << " " << cnt;
	return 0;
}

//binary search를 이용하는 방법도 있음