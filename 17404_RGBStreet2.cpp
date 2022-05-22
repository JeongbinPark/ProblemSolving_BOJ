//vector 선언시 초기화를 위해 C++11
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000001
using namespace std;

int N;
int R, G, B;
int costs[1000][3][3];

int main() {
	cin >> N;

	cin >> R >> G >> B;
	fill(&costs[0][0][0], &costs[1][0][0], INF);
	costs[0][0][0] = R;
	costs[0][1][1] = G;
	costs[0][2][2] = B;

	for(int i = 1; i < N; i++) {
		cin >> R >> G >> B;
		for (int j = 0; j < 3; j++) {
			costs[i][j][0] = min(costs[i - 1][j][1], costs[i - 1][j][2]) + R;
			costs[i][j][1] = min(costs[i - 1][j][0], costs[i - 1][j][2]) + G;
			costs[i][j][2] = min(costs[i - 1][j][0], costs[i - 1][j][1]) + B;
		}
	}

	vector<int> v = {
		costs[N - 1][0][1], costs[N - 1][0][2],
		costs[N - 1][1][0], costs[N - 1][1][2],
		costs[N - 1][2][0], costs[N - 1][2][1] };
	sort(v.begin(), v.end());

	cout << v[0];
	return 0;
}