#include <iostream>
using namespace std;

int main() {
	int C, N;
	int score[1000];
	int sum = 0, cnt = 0;
	double avg;

	cin >> C;
	while (C-->0) {
		sum = cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> score[i];
			sum += score[i];
		}
		avg = 1.0 * sum / N;
		for (int i = 0; i < N; i++)
			if (score[i]>avg) cnt++;
		cout << fixed;
		cout.precision(3);
		cout << 100.0 * cnt / N << "%\n";
	}
	return 0;
}
