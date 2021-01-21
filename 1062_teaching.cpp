/*
//backtracking
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void learning(int, int);

int N, K, cnt, maxi = 0;
string word, tmp;
vector<string> words;
bool alph[26] = { false };

int main() {
	cin >> N >> K;
	if (K < 5) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		word.assign(tmp, 4, (int) tmp.size() - 8);
		words.push_back(word);
	}
	
	alph['a' - 'a'] = alph['n' - 'a'] = alph['t' - 'a'] = alph['i' - 'a'] = alph['c' - 'a'] = true;

	learning(0, 0);
	cout << maxi;
	return 0;
}

void learning(int index, int level) {
	if (level == K-5) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < (int) words[i].size(); j++) {
				if (!alph[words[i][j]-'a']) {
					cnt--;
					break;
				}
			}
			cnt++;
		}
		maxi = max(maxi, cnt);
		return;
	}
	for (int i = index; i < 26; i++) {
		if (!alph[i]) {
			alph[i] = true;
			learning(i + 1, level + 1);
			alph[i] = false;
		}
	}
	return;
}
*/

//bitmask
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void learning(int, int);

int N, K, cnt, maxi = 0;
string word;
int words[50] = { 0 };
int alph = 0;

int main() {
	cin >> N >> K;
	if (K < 5) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> word;
		for (int j = 4; j < (int) word.size() - 4; j++)
			words[i] |= 1 << (word[j] - 'a');
	}
	alph |= 1 << ('a' - 'a'), alph |= 1 << ('n' - 'a'), alph |= 1 << ('t' - 'a'), alph |= 1 << ('i' - 'a'), alph |= 1 << ('c' - 'a');
	
	learning(0, 0);
	cout << maxi;
	return 0;
}

void learning(int index, int level) {
	if (level == K - 5) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			if ((words[i] & alph) == words[i]) cnt++;
		}
		maxi = max(maxi, cnt);
		return;
	}
	for (int i = index; i < 26; i++) {
		if ((alph & (1 << i)) == 0) {
			alph |= 1 << i;
			learning(i + 1, level + 1);
			alph &= ~(1 << i);
		}
	}
	return;
}
