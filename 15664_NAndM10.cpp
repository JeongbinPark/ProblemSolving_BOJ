#include <iostream>
#include <algorithm>
using namespace std;

void findNext(int, int);

int N, M;
int numbers[9];
int result[8];
bool visited[9];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> numbers[i];
	}
	sort(numbers, numbers + N + 1);

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
	result[cnt] = 0;
	for (int i = prev + 1; i <= N; i++) {
		if (!visited[i] && numbers[i] != result[cnt]) {
			visited[i] = true;
			result[cnt] = numbers[i];
			findNext(i, cnt + 1);
			visited[i] = false;
		}
	}
	return;
}