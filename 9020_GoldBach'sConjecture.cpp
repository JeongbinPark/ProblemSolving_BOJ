#include <iostream>
using namespace std;


bool notPrime[10001];
int goldbach[5001][2];
int primeNum[1229];

int main() {
	int cnt_primeNum = 0;
	for (int i = 2; i <= 10000; i++) {
		if (notPrime[i]) continue;
		primeNum[cnt_primeNum++] = i;
		for (int j = i + i; j <= 10000; j+=i) {
			notPrime[j] = true;
		}
	}

	for (int i = 0; i < cnt_primeNum; i++) {
		for (int j = i; j < cnt_primeNum; j++) {
			int halfSum = (primeNum[i] + primeNum[j]) / 2;
			if (halfSum > 5000) continue;
			if (!goldbach[halfSum][0] || goldbach[halfSum][1] - goldbach[halfSum][0] > primeNum[j] - primeNum[i]) {
				goldbach[halfSum][0] = primeNum[i];
				goldbach[halfSum][1] = primeNum[j];
			}
		}
	}

	int n;
	int evenNum;
	cin >> n;
	while (n--) {
		cin >> evenNum;
		cout << goldbach[evenNum/2][0] << " " << goldbach[evenNum/2][1] << "\n";
	}
	return 0;
}