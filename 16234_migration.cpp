#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void findUnionNation(int r, int c, int union_id);
void setUnionNationPopulation(int r, int c, int union_id, int population);
bool isPossible(int r, int c);

int N, L, R;
int board[50][50];
int d_r[4] = { 0 ,1, 0, -1 }, d_c[4] = { 1, 0, -1, 0 };
int union_ids[50][50];
int sum_population[2501], union_nations_cnt[2501];
int nations_cnt;
int days;

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		int union_cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!union_ids[i][j]) {
					union_cnt++;
					findUnionNation(i, j, union_cnt);
				}
			}
		}
		if (union_cnt == N * N) break;
		days++;

		int union_id = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (union_ids[i][j] == union_id) {
					setUnionNationPopulation(i, j, union_id, sum_population[union_id] / union_nations_cnt[union_id]);
					sum_population[union_id] = 0;
					union_nations_cnt[union_id] = 0;
					union_id++;
				}
			}
		}
	}
	cout << days;
	return 0;
}

void findUnionNation(int r, int c, int union_id) {
	union_ids[r][c] = union_id;
	union_nations_cnt[union_id]++;
	sum_population[union_id] += board[r][c];

	for (int d = 0; d < 4; d++) {
		int next_r = r + d_r[d];
		int next_c = c + d_c[d];

		if (isPossible(next_r, next_c) && !union_ids[next_r][next_c]){
			int diff = abs(board[r][c] - board[next_r][next_c]);
			if (diff >= L && diff <= R) {
				findUnionNation(next_r, next_c, union_id);
			}
		}
	}
	return;
}

void setUnionNationPopulation(int r, int c, int union_id, int population) {
	board[r][c] = population;
	union_ids[r][c] = 0;

	for (int d = 0; d < 4; d++) {
		int next_r = r + d_r[d];
		int next_c = c + d_c[d];
		if (isPossible(next_r, next_c) && union_ids[next_r][next_c] == union_id) {
			setUnionNationPopulation(next_r, next_c, union_id, population);
		}
	}
	return;
}


bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}