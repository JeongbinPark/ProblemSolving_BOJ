#include <iostream>
using namespace std;

int X1, Y1, X2, Y2, X3, Y3;

int main() {
	cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
	int ccw = X1 * Y2 + X2 * Y3 + X3 * Y1;
	ccw -= X1 * Y3 + X2 * Y1 + X3 * Y2;

	int result = 0;
	if (ccw > 0) result = 1;
	else if (ccw < 0) result = -1;
	else result = 0;

	cout << result;
	return 0;
}