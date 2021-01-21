#include <iostream>
#include <algorithm>
using namespace std;

void find(int, int);

int N, M;
int num[8], result[8];
bool visited[8] = { false }, flag = false;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N);

	for (int i = 0; i < N; i++)
		find(i, 0);

	return 0;
}
void find(int n, int level) {
	if (!flag && level == M) {
		for (int i = 0; i < level; i++)
			cout << result[i] << " ";
		cout << "\n";
		flag = true;
		return;
	}
	if (flag || visited[n]) return;

	visited[n] = true;
	result[level] = num[n];

	for (int i = 0; i < N; i++)
		find(i, level + 1);

	visited[n] = false;
	flag = false;
	return;
}