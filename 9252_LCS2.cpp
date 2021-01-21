#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int lcs[1001][1001];
stack<int> indexes;
char c;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= (int)str1.size(); i++)
	{
		for (int j = 1; j <= (int)str2.size(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	int index1 = (int)str1.size(), index2 = (int)str2.size();
	cout << lcs[index1][index2]<<"\n";

	while (index1 >= 0 && index2 >= 0) {

		if (lcs[index1 - 1][index2] == lcs[index1][index2]) index1--;
		else if (lcs[index1][index2 - 1] == lcs[index1][index2]) index2--; 
		else if (lcs[index1 - 1][index2 - 1] == lcs[index1][index2] - 1) {
			indexes.push(index1 - 1);
			index1--, index2--;
		}
	}
	while(!indexes.empty()) {
		c = str1[indexes.top()];
		cout << c;
		indexes.pop();
	}
	return 0;
}

/*
스택 이용안하고 재귀로 쓸 수 있음.
void print(int i, int j) {
	if (!i || !j) return;
	if (str1[i] == str2[j]{
		print(i - 1, j - 1);
		cout << str[i];
		}
	else if (lcs[i - 1][j] > lcs[i][j - 1]) print(i - 1, j);
	else print(i, j - 1);
}
*/