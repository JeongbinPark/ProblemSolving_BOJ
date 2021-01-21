#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N * M; i++) {
		cout << i;
		if (!(i % M)) cout << '\n';
		else cout << ' ';
	}
	return 0;
}