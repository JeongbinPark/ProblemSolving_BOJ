#include <iostream>
using namespace std;

int N, A, B;
int result = -1;

int main() {
	cin >> N >> A >> B;
	A--, B--;

	int unit = 1;
	int cnt = 0;
	while (unit < N) {
		unit *= 2;
		cnt++;
		if (A / unit == B / unit) {
			result = cnt;
			break;
		}
	}
	cout << result;
	return 0;
}