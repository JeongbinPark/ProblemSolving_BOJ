//7에서 배열 범위 안바꿔서 런타임에러
//test한다고 출력코드 썼다고 틀림

#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int, int);

int N, M;
int numbers[8], tmp[8];

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
	for (int i = n; i < N; i++) {
		tmp[level] = numbers[i];
		dfs(i, level + 1);
	}

	return;
}