#include <iostream>
#include <algorithm>
#define INF 100
using namespace std;

int N, member1, member2;
int members[51][52];

int main() {
	cin >> N;
	fill(members[0], members[N + 1], INF);
	for (int i = 1; i <= N; i++) members[i][i] = 0;
	while (true) {
		cin >> member1 >> member2;
		if (member1 == -1 && member2 == -1) break;
		members[member1][member2] = members[member2][member1] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				 members[i][j] = min(members[i][j], members[i][k] + members[k][j]);
			}
		}
	}

	int score, min_score = -1, cnt = 1;
	int candidate[50];
	for (int i = 1; i <= N; i++) {
		score = 0;
		for (int j = 1; j <= N; j++) {
			score = max(score, members[i][j]);
		}
		if (min_score == -1 || min_score > score) {
			min_score = score;
			candidate[0] = i;
			cnt = 1;
		}
		else if (min_score == score) {
			candidate[cnt] = i;
			cnt++;
		}
	}

	cout << min_score << " " << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << candidate[i] << " ";
	}

	return 0;
}