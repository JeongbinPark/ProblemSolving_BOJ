//아오!!! cin 속도!!!
#include <iostream>
using namespace std;

int M, N, K, r1, c1, r2, c2, j, o, i;
int jungle[1001][1001], ocean[1001][1001], ice[1001][1001];
char c;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> M >> N >> K;
	for (int m = 1; m <= M; m++) {
		j = o = i = 0;
		for (int n = 1; n <= N; n++) {
			cin >> c;
			if (c == 'J')	j++;
			else if (c == 'O')	o++;
			else if (c == 'I')	i++;
			jungle[m][n] = jungle[m - 1][n] + j;
			ocean[m][n] = ocean[m - 1][n] + o;
			ice[m][n] = ice[m - 1][n] + i;
		}
	}

	while (K--) {
		cin >> r1 >> c1 >> r2 >> c2;
		j = jungle[r2][c2] + jungle[r1 - 1][c1 - 1] - jungle[r1 - 1][c2] - jungle[r2][c1 - 1];
		o = ocean[r2][c2] + ocean[r1 - 1][c1 - 1] - ocean[r1 - 1][c2] - ocean[r2][c1 - 1];
		i = ice[r2][c2] + ice[r1 - 1][c1 - 1] - ice[r1 - 1][c2] - ice[r2][c1 - 1];
		cout << j << " " << o << " " << i << "\n";
	}
}
