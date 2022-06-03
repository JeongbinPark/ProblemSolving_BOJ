#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
string str;
map<string, int> m;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int dotIndex = str.find(".");
		string extension = str.substr(dotIndex + 1, (int)str.length());
		m[extension]++;
	}
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}
	return 0;
}