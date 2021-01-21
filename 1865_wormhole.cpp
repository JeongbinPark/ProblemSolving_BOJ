#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int TC, N, M, W, S, E, T;
int node[502][501];
bool YES;

int main() {
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		fill(node[0], node[N + 1], 100000);
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			node[S][E] = min(node[S][E], T);
			node[E][S] = min(node[E][S], T);
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			node[S][E] = min(node[S][E], -T);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					node[i][j] = min(node[i][j], node[i][k] + node[k][j]);
				}
			}
		}
		YES = false;
		for (int i = 1; i <= N; i++) {
			if (node[i][i] < 0) {
				YES = true;
				break;
			}
		}
		if (YES) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}

