#include <iostream>
using namespace std;

void move(int, int, int, int);

int main() {
	int K;
	cin >> K;

	int moves = 0;
	for (int i = 0; i < K; i++)
		moves = 2 * moves + 1;
	cout << moves << "\n";

	move(K, 1, 3, 2);

	return 0;
}
void move(int n, int dep, int des, int left) {
	if (n != 1) move(n - 1, dep, left, des);
	cout << dep << " " << des << "\n";
	if (n != 1) move(n - 1, left, des, dep);
}