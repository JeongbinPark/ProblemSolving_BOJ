#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs[5001][5001];

int main() {
	int N;
	string str1, str2;
	cin >> N >> str2;
	str1 = str2;
	reverse(str2.begin(), str2.end());
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (str1[i-1] == str2[j-1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << N - lcs[N][N];
	return 0;
}