#include <iostream>
using namespace std;

int main() {
	int friends[1000] = { 0 };
	int N, M, L;
	int turn = 0;

	cin >> N >> M >> L;

	while (1) {
		friends[turn]++;
		if (friends[turn] == M) break;
		if (friends[turn] % 2) turn += L;
		else turn -= L;
		turn %= N;
		if (turn < 0) turn += N;
	}

	int count = 0;
	for (int i = 0; i < N; i++)
		count += friends[i];
	cout << count - 1;

	return 0;
}