#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findPW(int, int);
bool isPossible(string);
int L, C;
char alph[15];
string str;
string vowel = "aeiou";

int main() {
	cin >> L >> C;
	for (int i = 0; i< C; i++)
		cin >> alph[i];
	sort(alph, alph + C);
	findPW(0, 0);
	return 0;
}
void findPW(int level, int index) {
	if (level == L && isPossible(str)){
		cout << str << "\n";
		return;
	}
	if (level == L) return;
	for (int i = index; i <= C - L + level; i++) {
		str += alph[i];
		findPW(level + 1, i + 1);
		str.pop_back();
	}
}
bool isPossible(string s) {
	int v = 0, c = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (vowel.find_first_of(s[i]) != string::npos) v++;
		else c++;
		if (v > 0 && c > 1) return true;
	}
	return false;
}