#include <iostream>
#include <string>
using namespace std;

int N;
int cnt = 0;
string word;

int main() {
	cin >> N;
	while (N--) {
		cin >> word;
		int times[26] = { 0 };
		bool isGroupWord = true;

		for (int i = 0; i < word.length(); i++) {
			if (i != 0 && word[i - 1] == word[i]) continue;
			times[word[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (times[i] > 1) {
				isGroupWord = false;
				break;
			}
		}
		if (isGroupWord) cnt++;
	}
	cout << cnt;
	return 0;
}