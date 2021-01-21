//뤼카의 정리 이용

/*
#include <iostream>
#include <vector>
using namespace std;

long long N, K;
int M, result = 1;
long long BC[2001][2001];
vector<int> remainder_N, remainder_K;

int main() {
	cin >> N >> K >> M;

	for (int i = 0; i < M; i++) BC[i][0] = 1;
	for (int i = 1; i < M; i++)
		for (int j = 1; j <= i; j++) {
			BC[i][j] = BC[i - 1][j - 1] + BC[i - 1][j];
			BC[i][j] %= M;
		}

	long long tmp = N;
	while (tmp > 0) {
		remainder_N.push_back(tmp%M);
		tmp /= M;
	}
	tmp = K;
	while (tmp > 0) {
		remainder_K.push_back(tmp%M);
		tmp /= M;
	}

	for (int i = 0; i < (int)remainder_N.size(); i++) {
		int n = remainder_N[i], k;
		if (i >= (int)remainder_K.size()) k = 0;
		else k = remainder_K[i];

		result *= BC[n][k];
		result %= M;
	}
	cout << result;
	return 0;
}
*/

#include <iostream>
using namespace std;

int BC[2001][2001];
long long N, K;
int M;

int main(){ 
	cin >> N >> K >> M; 
	for(int i = 0; i < M; i++){
		BC[i][0] = 1;
		for(int j=1; j<=i; j++) 
			BC[i][j] = (BC[i-1][j-1] + BC[i-1][j])%M;
	} 
	int result = 1;
	while(N || K){ 
		result *= BC[N%M][K%M];
		result %= M;
		N /= M, K /= M;
	} 
	cout << result;
	return 0;
}
