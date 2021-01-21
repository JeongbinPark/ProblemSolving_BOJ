#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[41][41];
vector<int> index;
char c;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= (int) str1.size(); i++)
		for (int j = 1; j <= (int) str2.size(); j++)
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int index1 = str1.size(), index2 = str2.size();
	while (dp[index1][index2] != 0){
		if (dp[index1][index2] == dp[index1][index2 - 1])	index2--;
		else if (dp[index1][index2] == dp[index1 - 1][index2])	index1--;
		else if (dp[index1][index2] - 1 == dp[index1 - 1][index2 - 1])
		{
			index.push_back(index1-1);
			index1--, index2--;
		}
	}
	int len = index.size();
	for (int i = 0; i < len; i++) {
		c = str1[index.back()];
		cout << c;
		index.pop_back();
	}
	return 0;
}
