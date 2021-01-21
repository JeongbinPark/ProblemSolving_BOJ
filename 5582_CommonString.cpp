#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string str1, str2;
int maxi, pre[4001], common[4001];

int main() {
	cin >> str1 >> str2;
	for (int i = 1; i <= (int)str1.size(); i++) {
		for (int j = 1; j <= (int)str2.size(); j++) {
			if (str1[i-1] == str2[j-1]) common[j] = pre[j - 1] + 1;
			else common[j] = 0;
			maxi = max(maxi, common[j]);
		}
		memcpy(pre, common, ((int)str2.size() + 1)*sizeof(int));
	}
	cout << maxi;
}