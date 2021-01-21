#include <iostream>
#include <algorithm>
using namespace std;

void LineUp(int);
int Play();

int N, out, curr_score, max_score, batter, curr_result;
int result[50][9], order[9], visited[9];
bool base[4];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 9; j++)
			cin >> result[i][j];
	order[3] = 0;
	visited[0] = true;
	LineUp(0);
	cout << max_score;
}
void LineUp(int o) {
	if (o == 9) {
		max_score = max(max_score, Play());
		return;
	}
	if (o == 3) {
		LineUp(4);
		return;
	}
	for (int i = 1; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			order[o] = i;
			LineUp(o + 1);
			visited[i] = false;
		}
	}
	return;
}
int Play() {
	curr_score = 0;
	batter = 0;
	for (int inning = 0; inning < N; inning++) {
		out = 0;
		fill(base, base + 5, false);
		while (true) {
			curr_result = result[inning][order[batter % 9]];
			batter++;

			if (curr_result == 0) {
				out++;
				if (out == 3) break;
			}
			else {
				for (int i = 3; i; i--) {
					if (base[i]) {
						if (i + curr_result > 3) curr_score++;
						else base[i + curr_result] = true;
						base[i] = false;
					}
				}
				if (curr_result == 4) curr_score++;
				else base[curr_result] = true;
			}
		}
	}
	return curr_score;
}