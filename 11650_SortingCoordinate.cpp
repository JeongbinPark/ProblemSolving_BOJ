#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	pair<int, int> coor[100000];

	for (int i = 0; i < N; i++)
		cin >> coor[i].first >> coor[i].second;

	sort(coor, coor + N);

	for (int i = 0; i < N; i++)
		cout << coor[i].first << " " << coor[i].second << "\n";
	return 0;
}