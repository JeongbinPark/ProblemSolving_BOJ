#include <iostream>
using namespace std;

double goRobot(int, int, int);

int N;
int prob[4];
bool visited[29][29];
int d_r[4] = { 0, 0, 1 ,-1 };
int d_c[4] = { 1, -1, 0 , 0 };
double sum;

int main() {
	cin >> N;
	for(int d = 0; d < 4; d++) cin >> prob[d];

	visited[14][14] = true;

	cout.precision(9);
	cout << goRobot(14, 14, N);
	return 0;
}

double goRobot(int r, int c, int n) {
	if (n == 0) {
		return 1.0;
	}

	double thisSum = 0.0;
	for (int d = 0; d < 4; d++) {
		int next_r = r + d_r[d];
		int next_c = c + d_c[d];

		if (!visited[next_r][next_c]) {
			visited[next_r][next_c] = true;
			thisSum += 0.01 * prob[d] * goRobot(next_r, next_c, n - 1);
			visited[next_r][next_c] = false;
		}
	}
	return thisSum;
}