#include <iostream>
#include <cstring>
#define MAX 1000000000000000000
using namespace std;

int n, k;
long long tmp[200], pre1[200], pre2[200] = { 1 };
bool flag;
int main() {
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	while (++k < n) {
		memcpy(tmp, pre1, 200 * sizeof(long long));
		for (int i = 0; i < 200; i++) {
			tmp[i] += pre2[i];
			tmp[i + 1] += tmp[i] / MAX;
			tmp[i] %= MAX;
		}

		memcpy(pre1, pre2, 200 * sizeof(long long));
		memcpy(pre2, tmp, 200 * sizeof(long long));
	}
	for (int i = 199; i >= 0; i--) {
		if (!flag && !tmp[i]) continue;
		else if (!flag) {
			cout << tmp[i];
			flag = true;
			continue;
		}
		cout.width(18);
		cout.fill('0');
		cout << tmp[i];
	}
	return 0;
}