/* 시간 초과.. 왜?
#include <iostream>
using namespace std;

int main() {
	int cnt[20000001] = { 0 };
	int N, M, tmp;
	cin >> N;
	while (N--) {
		cin >> tmp;
		cnt[tmp + 10000000]++;
	}
	cin >> M;
	while (M--) {
		cin >> tmp;
		cout << cnt[tmp + 10000000] << " ";
	}
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, tmp, cnt;
vector<int> cards;
vector<int>::iterator iter_l , iter_u;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		cin >> tmp;
		cards.push_back(tmp);
	}
	sort(cards.begin(), cards.end());
	cin >> M;
	while (M--) {
		cnt = 0;
		cin >> tmp;
		iter_l = lower_bound(cards.begin(), cards.end(), tmp);
		iter_u = upper_bound(cards.begin(), cards.end(), tmp);
		if (cards[iter_l - cards.begin()] == tmp) cout << iter_u - iter_l;
		else cout << 0;
		cout << " ";
	}
	return 0;
}