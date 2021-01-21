#include <iostream>
#include <algorithm>
using namespace std;

int idx, p, r, maxi;
int pal[200010];
char c, seq[200010];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	seq[idx++] = '#';
	while (cin >> c) {
		seq[idx++] = c;
		seq[idx++] = '#';
	}
	for (int i = 1; i < idx; i++) {
		if (i <= r) pal[i] = min(pal[2 * p - 1], r - i);
		else pal[i] = 0;

		while (i - pal[i] - 1 >= 0 && i + pal[i] + 1<idx && seq[i - pal[i] - 1] == seq[i + pal[i] + 1]) pal[i]++;

		if (pal[i] + i > r) {
			r = pal[i] + i;
			p = i;
		}
		maxi = max(maxi, pal[i]);
	}
	cout << maxi;
	return 0;
}
