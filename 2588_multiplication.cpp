#include <iostream>
using namespace std;

int main() {
	int a, b;
	int sum = 0;
	
	cin >> a >> b;

	cout << a * (b % 10) << endl;
	sum += a * (b % 10);
	b /= 10;
	cout << a * (b % 10) << endl;
	sum += a * (b % 10) * 10;
	b /= 10;
	cout << a * (b % 10) << endl;
	sum += a * (b % 10) * 100;
	b /= 10;
	cout << sum << endl;

	return 0;
}