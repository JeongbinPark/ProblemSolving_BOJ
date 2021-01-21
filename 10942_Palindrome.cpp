/* LCS 방식 시간초과
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int N, M, S, E;
char c;
string numbers, str1, str2;
int lcs[2001][2001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		numbers += c;
	}
	cin >> M;

	while (M--) {
		str1.clear(), str2.clear();

		cin >> S >> E;
		for (int i = S - 1; i < E; i++)
			str1 += numbers[i];

		str2 = str1;
		reverse(str2.begin(), str2.end());

		for (int i = 1; i <= (int)str1.size(); i++) {
			for (int j = 1; j <= (int)str2.size(); j++) {
				if (str1[i - 1] == str2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
		
		cout << (E - S + 1 - lcs[(int)str1.size()][(int)str2.size()] ? 0 : 1) << "\n";
	}
	return 0;
}

*/

#include <iostream>
using namespace std;

int N, M, S, E;
int numbers[2001];
int dp[2001][2001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	//dp 계산
	for (int i = 0; i < N; i++)
		dp[i][i] = 1;
	for (int i = 0; i < N - 1; i++)
		if (numbers[i] == numbers[i + 1]) dp[i][i + 1] = 1;
	//맨 앞, 맨 뒤 숫자 같고, 안쪽이 팰린드롬이면 팰린드롬
	int s, e;
	for (int i = 2; i < N; i++) {
		for (int s = 0; s < N - i; s++) {
			if (numbers[s] == numbers[s + i] && dp[s + 1][s + 1] && dp[s + 1][s + i - 1]) dp[s][s + i] = 1;
			else dp[s][s + i] = 0;
		}
	}

	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << dp[S - 1][E - 1] << "\n";
	}
	return 0;
}