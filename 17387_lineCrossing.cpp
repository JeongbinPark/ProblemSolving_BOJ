#include <iostream>
#include <algorithm>
using namespace std;

int ccw(int, int, int);
bool overlap();

int x[4], y[4];

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> x[i] >> y[i];
	}

	int ccw0 = ccw(0, 1, 2);
	int ccw1 = ccw(0, 1, 3);
	int ccw2 = ccw(2, 3, 0);
	int ccw3 = ccw(2, 3, 1);

	if (ccw0 * ccw1 == 0 && ccw2 * ccw3 == 0) {
		if (overlap()) cout << 1;
		else cout << 0;
		return 0;
	}
	if (ccw0 * ccw1 <= 0 && ccw2 * ccw3 <= 0) {
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}

int ccw(int line_idx0, int line_idx1, int dot_idx) {
	long long X1 = x[line_idx0], Y1 = y[line_idx0];
	long long X2 = x[line_idx1], Y2 = y[line_idx1];
	long long X3 = x[dot_idx], Y3 = y[dot_idx];

	long long ccw = X1 * Y2 + X2 * Y3 + X3 * Y1;
	ccw -= X1 * Y3 + X2 * Y1 + X3 * Y2;

	if (ccw == 0) return 0;
	if (ccw > 0) return 1;
	if (ccw < 0) return -1;
}

bool overlap() {
	int left1, right1, left2, right2;
	if (x[0] != x[2]) {
		if (x[0] > x[1]) swap(x[0], x[1]);
		if (x[2] > x[3]) swap(x[2], x[3]);
		return x[1] >= x[2] && x[0] <= x[3];
	}
	else {
		if (y[0] > y[1]) swap(y[0], y[1]);
		if (y[2] > y[3]) swap(y[2], y[3]);
		return y[1] >= y[2] && y[0] <= y[3];
	}
	return 0;
}