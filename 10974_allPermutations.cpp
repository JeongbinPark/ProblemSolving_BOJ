#include <iostream>
using namespace std;

void findNext(int num);

int N;
bool visited[9];
int arr[8];

int main() {
	cin >> N;
	findNext(0);
	return 0;
}

void findNext(int num) {
	if (num == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[num] = i;
			findNext(num + 1);
			visited[i] = false;
		}
	}
	return;
}