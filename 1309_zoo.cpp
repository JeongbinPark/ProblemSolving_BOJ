#include <iostream>
#define MOD 9901
using namespace std;

int N;
int pre = 1, curr = 3, nex;

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		nex = 2 * curr + pre;
		nex %= MOD;
		pre = curr;
		curr = nex;
	}
	cout << curr;
	return 0;
}