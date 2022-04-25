#include <iostream>
#include <vector>
using namespace std;

int N;
bool isNotPrime[4000001] = { 1, 1};
vector<int> primeNumbers;
int result;

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (isNotPrime[i]) continue;
		primeNumbers.push_back(i);
		for (int j = i + i; j <= N; j += i) {
			isNotPrime[j] = true;
		}
	}
	int cnt_PrimeNumbers = (int)primeNumbers.size();

	int s = 0;
	int e = -1;
	int sum = 0;
	while (true) {
		if (sum <= N) {
			e++;
			if (e == cnt_PrimeNumbers) break;
			sum += primeNumbers[e];
		}
		else {
			sum -= primeNumbers[s];
			s++;
		}
		if (sum == N) result++;
	}
	cout << result;
	return 0;
}