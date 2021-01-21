/*
#include <iostream>
#include <algorithm>
using namespace std;

int N, T, K, S, max_score;
int score[10002];

int main() {
	fill(score, score + 10001, -1);
	score[0] = 0;
	cin >> N >> T;
	while (N--) {
		cin >> K >> S;
		for (int i = 10000; i >= 0; i--) {
			if (score[i] != -1 && i + K <= 10000) 
				score[i + K] = max(score[i + K], score[i] + S);
		}
	}
	for (int i = 0; i <= T; i++) {
		if (score[i] != -1) max_score = max(max_score, score[i]);
	}
	cout << max_score;
	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, T, K, S, max_score;
int score[10001];

int main() {
	cin >> N >> T;
	while (N--) {
		cin >> K >> S;
		for (int i = T; i >= K; i--) {
				score[i] = max(score[i], score[i - K] + S);
		}
	}
	cout << score[T];
	return 0;
}