/* LCS는 '가장 긴' 공통 부분 문자열을 만들기 때문에 tmp와 str3를 계산하면 잘못된 답을 도출할 수 있다.
예 (abcd, abcd, d)의 경우

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void getLCS(string, string);
void getString(int, int);

string str1, str2, str3, tmp;
int lcs[101][101];

int main() {
	cin >> str1 >> str2 >> str3;
	getLCS(str1, str2);
	getString((int)str1.size(), (int)str2.size());
	getLCS(tmp, str3);
	cout << lcs[(int)tmp.size()][(int)str3.size()];
	return 0;
}

void getLCS(string s1, string s2) {
	for (int i = 1; i <= (int)s1.size(); i++)
	{
		for (int j = 1; j <= (int)s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
}

void getString(int i, int j) {
	if (!i || !j) return;
	if (str1[i - 1] == str2[j - 1]) {
		getString(i - 1, j - 1);
		tmp += str1[i - 1];
	}
	else if (lcs[i - 1][j] > lcs[i][j - 1]) getString(i - 1, j);
	else getString(i, j - 1);
}
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2, str3;
int lcs[101][101][101];

int main() {
	cin >> str1 >> str2 >> str3;
	for (int i = 1; i <= (int) str1.size(); i++)
	{
		for (int j = 1; j <= (int)str2.size(); j++)
		{
			for (int k = 1; k <= (int)str3.size(); k++)
			{
				if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
					lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
				else
					lcs[i][j][k] = max(lcs[i - 1][j][k], max(lcs[i][j - 1][k], lcs[i][j][k - 1]));
			}
		}
	}
	cout << lcs[(int)str1.size()][(int)str2.size()][(int)str3.size()];
	return 0;
}