#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string str1, string str2);

int N;
string str;
vector<string> serialNumbers;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		serialNumbers.push_back(str);
	}
	sort(serialNumbers.begin(), serialNumbers.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << serialNumbers[i] << "\n";
	}
	return 0;
}
bool compare(string str1, string str2) {
	if ((int)str1.length() < (int)str2.length()) return true;
	else if ((int)str1.length() > (int)str2.length()) return false;
	
	int sum_str1 = 0, sum_str2 = 0;
	for (int i = 0; i < (int)str1.length(); i++) {
		if (str1[i] >= '0' && str1[i] <= '9') sum_str1 += str1[i] - '0';
	}
	for (int i = 0; i < (int)str2.length(); i++) {
		if (str2[i] >= '0' && str2[i] <= '9') sum_str2 += str2[i] - '0';
	}

	if (sum_str1 < sum_str2) return true;
	else if (sum_str1 > sum_str2) return false;


	for (int i = 0; i < (int)str1.length(); i++) {
		if (str1[i] < str2[i]) return true;
		if (str1[i] > str2[i]) return false;
	}
	return true;
}