#include <iostream>
#include <cmath>
#define INF 100001
using namespace std;

struct Point {
	long long r, c;
};

int n;
Point p0, p1, p2;
double sum;

int main() {
	cin >> n;

	cin >> p0.r >> p0.c;
	cin >> p1.r >> p1.c;

	for (int i = 2; i < n; i++) {
		cin >> p2.r >> p2.c;
		double area = ((p1.r - p0.r) * (p2.c - p0.c) - (p2.r - p0.r) * (p1.c - p0.c)) / 2.0;
		sum += area;
		p1 = p2;
	}
	cout << fixed;
	cout.precision(1);
	cout << (sum >= 0 ? sum : -sum);
	return 0;
}