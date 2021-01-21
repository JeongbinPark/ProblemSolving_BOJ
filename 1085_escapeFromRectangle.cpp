#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	x = x > (w - x) ? w - x : x;
	y = y > (h - y) ? h - y : y;
	cout << (x > y ? y : x);
	return 0;
}