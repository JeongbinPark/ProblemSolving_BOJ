#include <iostream>
#define MOD 10007
using namespace std;

int N, K;
int bc[1001][1001] = { 1 };

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		bc[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
			bc[i][j] %= MOD;
		}
	}
	cout << bc[N][K];
	return 0;
}