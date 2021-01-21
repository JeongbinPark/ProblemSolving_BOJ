#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string, string);

string words[20000];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> words[i];
	sort(words, words + N, cmp);
	cout << words[0] << "\n";
	for (int i = 1; i < N; i++)
		if (words[i - 1].compare(words[i])) cout << words[i] << "\n";
	return 0;
}
bool cmp(string a, string b) {
	if (a.size() < b.size() || (a.size() == b.size()) && a.compare(b) < 0) return true;
	return false;
}