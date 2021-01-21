#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	if (str1.size()<str2.size()) swap(str1, str2);

	int n = str1.size() - str2.size();
	int mini, cnt;
	for (int i = 0; i <= n; i++) {
		cnt = 0;
		for (int j = 0; j <str2.size(); j++) {
			if (str1[j + i] != str2[j]) cnt++;
		}
		if (!i) mini = cnt;
		else mini = min(mini, cnt);
	}
	cout << mini;
	return 0;
}