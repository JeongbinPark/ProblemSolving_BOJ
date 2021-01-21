/*
pal[i] + i 이걸 pal[i] + 1 로 써서 틀림...
pal[2 * p - i] 이걸 pal[2 * p - 1]로 써서 6번 런타임에러.....
cin.tie(NULL), ios::sync_with_stdio(false); 이거 안써서 시간초과......
아오.......
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, S, E, num, idx, p, r;
int pal[2000002], seq[2000002];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	seq[idx++] = -1;
	while (N--) {
		cin >> seq[idx++];
		seq[idx++] = -1;
	}
	for (int i = 0; i < idx; i++) {
		if (i <= r) pal[i] = min(pal[2 * p - i], r - i);
		else pal[i] = 0;

		while (i - pal[i] - 1 >= 0 && i + pal[i] + 1 < idx && seq[i - pal[i] - 1] == seq[i + pal[i] + 1])
			pal[i]++;

		if (pal[i] + i > r) {
			r = pal[i] + i;
			p = i;
		}
	}
	cin >> M;
	while (M--) {
		cin >> S >> E;
		if (pal[S + E - 1] >= E - S) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}