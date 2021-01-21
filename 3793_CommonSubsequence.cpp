#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs[201][201];

int main() {
	string str1, str2;
	while (1) {
		cin >> str1 >> str2;
		if (cin.eof()) break;
		for (int i = 1; i <= (int) str1.size(); i++)
		{
			for (int j = 1; j <= (int) str2.size(); j++)
			{
				if (str1[i - 1] == str2[j - 1])
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
		cout << lcs[(int)str1.size()][(int)str2.size()] << "\n";
	}

	return 0;
}
