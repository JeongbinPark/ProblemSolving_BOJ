#include <iostream>
#include <algorithm>
using namespace std;

void print(int);

int N, M;
int input[7], arr[7], result[7];
int idx;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);

	arr[0] = input[0];
	idx = 1;
	for (int i = 1; i < N; i++) {
		if (input[i] == input[i - 1]) continue;
		arr[idx++] = input[i];
	}

	print(0);
	return 0;
}

void print(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < idx; i++) {
		result[cnt] = arr[i];
		print(cnt + 1);
	}
	return;
}