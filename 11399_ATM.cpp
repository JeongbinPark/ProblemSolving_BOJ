#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> P;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		P.push_back(tmp);
	}

	sort(P.begin(), P.end());

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (N - i) * P[i];
	}
	cout << sum;
	return 0;
}