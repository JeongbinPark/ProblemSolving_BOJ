//manacher
#include <iostream>
#include <algorithm>
using namespace std;

char c, str[4000010];
int P, R, A[4000010], len, tmp;
long long sum;

int main() {
	str[len++] = '#';
	while (cin >> c) {
		str[len++] = c;
		str[len++] = '#';
	}
	for (int i = 0; i < len; i++) {
		if (i <= R)
			A[i] = min(A[2 * P - i], R - i);
		else A[i] = 0;

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < len && str[i - A[i] - 1] == str[i + A[i] + 1]) A[i]++;

		if (R < i + A[i]) {
			R = i + A[i];
			P = i;
		}
	}

	for (int i = 0; i < len; i++) {
		sum += (A[i] + 1) / 2;
	}
	cout << sum;
	return 0;
}