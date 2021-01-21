#include <iostream>
using namespace std;

long long fast(int, int);

long long A, B, C;

int main() {
	cin >> A >> B >> C;
	cout << fast(A, B) % C;
	return 0;
}

long long fast(int base, int exponent) {
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
	if (exponent % 2 == 0){
		long long half = fast(base, exponent / 2);
		return (half * half) % C;
	}
	else return (base * fast(base, exponent - 1)) % C;
}

//repeated squaring algorithm

