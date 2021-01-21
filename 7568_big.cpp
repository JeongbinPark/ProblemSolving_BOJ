#include <iostream>
#include <vector>
using namespace std;

int N, x, y;
vector< pair<int, int> > v;
int counter[50];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < N; i++) {
		x = v[i].first;
		y = v[i].second;
		for (int j = 0; j < N; j++) {
			if (x < v[j].first && y < v[j].second)
				counter[i]++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << counter[i] + 1 << " ";
	}
	return 0;
}