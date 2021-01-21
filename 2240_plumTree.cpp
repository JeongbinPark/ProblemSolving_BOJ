#include <iostream>
#include <algorithm>
using namespace std;

int T, W, tree, maxi;
int plum[1002][31];

int main() {
	cin >> T >> W;
	fill(plum[0], plum[T + 1], -1);
	plum[0][0] = 0;

	for (int i = 1; i <= T; i++) {
		cin >> tree;
		plum[i][0] = plum[i - 1][0] + (tree % 2);
		for (int j = 1; j <= W; j++) {
			if (plum[i - 1][j - 1] != -1) {
				plum[i][j] = max(plum[i - 1][j], plum[i - 1][j - 1]);
				if (tree % 2 == (j+1) % 2) plum[i][j]++;
			}
		}
	}
	for (int i = 0; i <= W; i++)
		maxi = max(maxi, plum[T][i]);
	cout << maxi;
	return 0;
}
