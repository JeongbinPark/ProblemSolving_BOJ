#include <iostream>
#include <cstring>
using namespace std;

char word[27];
bool alpha[26] = { 0 };


int main() {
	cin >> word;
	int wordLength = strlen(word);
	for (int len = 0; len < wordLength; len++) {
		alpha[word[len] - 'a'] = true;
	}

	if (wordLength < 26) {
		for (int i = 0; i < 26; i++) {
			if (!alpha[i]) {
				word[wordLength] = i + 'a';
				word[wordLength + 1] = '\0';

				cout << word;
				return 0;
			}
		}
	}

	for (int currentIndex = 25; currentIndex > 0; currentIndex--) {
		if (currentIndex == 0)
			cout << "here";
		alpha[word[currentIndex] - 'a'] = false;
		for (int currentAlpha = word[currentIndex - 1] - 'a' + 1; currentAlpha < 26; currentAlpha++) {
			if (!alpha[currentAlpha]) {
				word[currentIndex - 1] = currentAlpha + 'a';
				word[currentIndex] = '\0';
				cout << word;
				return 0;
			}

		}
	}

	cout << -1;
	return 0;
}