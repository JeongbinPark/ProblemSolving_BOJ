#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int getDiffPow(int, int, int, int);

int T;
int X1, Y1, R1, X2, Y2, R2;

int main() {
	cin >> T;
	while (T--) {
		cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
		int diffPow = getDiffPow(X1, Y1, X2, Y2);
		int cnt = 0;

		int addPow = pow(R1 + R2, 2);
		int subPow = pow(R1 - R2, 2);

		if (subPow < diffPow && diffPow < addPow) {
			cnt = 2;
		}
		else if (diffPow == 0) {
			if (R1 == R2) {
				cnt = -1;
			}
			else {
				cnt = 0;
			}
		}
		else if (addPow == diffPow || subPow == diffPow) {
			cnt = 1;
		}
		else if (subPow > diffPow || diffPow > addPow){
			cnt = 0;
		}
		cout << cnt << "\n";
	}
	return 0;
}

int getDiffPow(int X1, int Y1, int X2, int Y2) {
	return pow(X1 - X2, 2) + pow(Y1 - Y2, 2);
}