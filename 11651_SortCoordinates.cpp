#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y;
vector< pair<int, int> > coor;

bool cmp(pair<int, int> c1, pair<int, int> c2) {
	return (c1.second < c2.second || (c1.second == c2.second) && c1.first < c2.first);
}

int main() {
	cin >> n;
	while (n--) {
		cin >> x >> y;
		coor.push_back(make_pair(x, y));
	}
	sort(coor.begin(), coor.end(), cmp);
	for (int i = 0; i < coor.size(); i++)
		cout << coor[i].first << " " << coor[i].second << "\n";
	return 0;
}
