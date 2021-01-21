#include <iostream>
using namespace std;

int main() {
	int T, H, W, N;
	int x, y;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		y = (N - 1) / H;
		x = (N - 1) % H;
		cout << (x + 1) * 100 + y + 1 << "\n";
	}
	return 0;
}