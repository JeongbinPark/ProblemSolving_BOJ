#include <iostream>
#include <string>
using namespace std;

string str;
int cnt[26] = { 0 };
int maximum, index, max_cnt = 1;
char tmp;


int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a') cnt[str[i] - 'a']++;
		else cnt[str[i] - 'A']++;
	}
	index = 0;
	maximum = cnt[0];
	for (int i = 1; i < 26; i++)
	{
		if (maximum == cnt[i]) max_cnt++;
		if (maximum < cnt[i]) {
			maximum = cnt[i];
			index = i;
			max_cnt = 1;
		}
	}
	tmp = 'A' + index;
	if (max_cnt > 1) cout << "?";
	else cout << tmp;

	return 0;
}
