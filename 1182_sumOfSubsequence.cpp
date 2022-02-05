#include <iostream>
using namespace std;

void recursion(int, int);

int N, S;
int seq[20] = { 0 };
int cnt = 0;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	recursion(0, 0);

	if (S == 0 && cnt > 0) cnt--;
	cout << cnt;
	return 0;
}

void recursion(int index, int sum) {
	if (index == N) {
		if (sum == S) cnt++;
		return;
	}
	recursion(index + 1, sum);
	recursion(index + 1, sum + seq[index]);
}

/*
//문제 잘못 이해함.
#include <iostream>
using namespace std;

int N, S;
int seq[20] = { 0 };
int cnt = 0;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int s = 0; s < N; s++) {
		int sum = 0;
		for (int e = s; e < N; e++) {
			sum += seq[e];
			if (sum == S) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
*/