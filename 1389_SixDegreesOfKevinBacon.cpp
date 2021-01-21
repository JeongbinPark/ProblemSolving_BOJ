#include <iostream>
#include <algorithm>
#define INF 1000
using namespace std;

int N, M, a, b, min_degrees = INF, min_index;
int degrees[102][101];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	fill(degrees[1], degrees[N + 1], INF);
	for (int i = 1; i <= N; i++)
		degrees[i][i] = 0;
	while (M--) {
		cin >> a >> b;
		degrees[a][b] = degrees[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				degrees[i][j] = min(degrees[i][j], degrees[i][k] + degrees[k][j]);

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += degrees[i][j];
		}
		if (sum < min_degrees) {
			min_degrees = sum;
			min_index = i;
		}
	}
	cout << min_index;
	return 0;
}