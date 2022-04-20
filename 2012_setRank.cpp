#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N, num;
vector<int> inputRank;
long long result = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		inputRank.push_back(num);
	}
	inputRank.push_back(0);
	sort(inputRank.begin(), inputRank.end());
	
	for (int i = 1; i <= N; i++) {
		result += abs(i - inputRank[i]);
	}

	cout << result;
	return 0;
}