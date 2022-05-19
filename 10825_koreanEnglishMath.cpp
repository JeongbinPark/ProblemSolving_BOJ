#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Score {
	string name;
	int korean, english, math;
} scores[100000];

bool compare(const Score& s1, const Score& s2);

int N;
string name;
int korean, english, math;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		Score& s = scores[i];
		cin >> s.name >> s.korean >> s.english >> s.math;
	}

	sort(scores, scores + N, compare);

	for (int i = 0; i < N; i++) {
		cout << scores[i].name << "\n";
	}
	return 0;
}

bool compare(const Score& s1, const Score& s2) {
	if (s1.korean == s2.korean) {
		if (s1.english == s2.english) {
			if (s1.math == s2.math) {
				return s1.name < s2.name;
			} 
			else return s1.math > s2.math;
		}
		else return s1.english < s2.english;
	}
	else return s1.korean > s2.korean;
}
