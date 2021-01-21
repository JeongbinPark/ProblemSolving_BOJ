#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> name;
vector<int> index;
string tmp;
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> tmp;
		name.push_back(tmp);
	}
	sort(name.begin(), name.end());
	for (int i = 1; i < N + M; i++) {
		if (!name[i].compare(name[i - 1])) index.push_back(i);
	}
	cout << index.size() << "\n";
	for (int i = 0; i < index.size(); i++)
		cout << name[index[i]] << "\n";
	return 0;
}