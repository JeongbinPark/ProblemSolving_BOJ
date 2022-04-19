#include <iostream>
using namespace std;

void findNext(int, int);

int N, M, num;
bool numbers[10001];
int result[8];

int main() {
	cin >> N >> M;
	while (N--) {
		cin >> num;
		numbers[num] = true;
	}
	findNext(0, 0);
	return 0;
}
void findNext(int prev, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = prev; i < 10001; i++) {
		if (numbers[i]) {
			result[cnt] = i;
			findNext(i, cnt + 1);
		}
	}
	return;
}