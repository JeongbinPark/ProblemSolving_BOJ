//카탈란(카탈랑) 수 
/*
//일반항이용
#include <iostream>
using namespace std;

long long gcd(long long a, long long b);

int n;
long long tmp1, tmp2, tmp3;

int main(){
	while (true) {
		cin >> n;
		if (n == 0) break;
		tmp1 = tmp2 = 1;
		for (int i = 2 * n; i > n; i--) {
			tmp1 *= i;
			tmp2 *= i - n;
			tmp3 = gcd(tmp1, tmp2);
			tmp1 /= tmp3;
			tmp2 /= tmp3;
		}
		cout << tmp1 / (n + 1) << "\n";
	}
	return 0; 
}

long long gcd(long long a, long long b) {
	long long tmp;
	if (a < b) swap(a, b);
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

*/

//점화식 이용
#include <iostream>
using namespace std;

int n;
long long c[31] = { 1, };

int main() {
	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j < i; j++) {
			c[i] += c[j] * c[i - 1 - j];
		}
	}
	while (true) {
		cin >> n;
		if (n == 0) break;
		cout << c[n] << "\n";
	}
	return 0;
}
