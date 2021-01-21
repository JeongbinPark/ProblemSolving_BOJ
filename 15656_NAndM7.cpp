#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int, int);

int N, M;
int numbers[7], tmp[7];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	sort(numbers, numbers + N);
	dfs(0, 0);
	return 0;
}

void dfs(int n, int level) {
	if (level == M) {
		for (int i = 0; i < M; i++)
			cout << tmp[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		tmp[level] = numbers[i];
		dfs(i + 1, level + 1);
	}
	return;
}