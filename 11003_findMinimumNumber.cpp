/* 시간초과 => min_element가 매번 O(window 갯수)이기 때문에 O(N * L)임.
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, L, num;
deque<int> window;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> L;
	while (N--) {
		cin >> num;
		window.push_back(num);
		if ((int) window.size() > L) window.pop_front();
		cout << *min_element(window.begin(), window.end()) << " ";
	}
}
*/
/* 통과, 하지만 메모리 너무 많이 씀
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, L, min_pos, curr_pos, mini, num;
priority_queue< pair<int, int> > pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> L;
	cin >> mini;
	pq.push(make_pair(-mini, 0));
	cout << mini << " ";
	for (curr_pos = 1; curr_pos < N; curr_pos++) {
		cin >> num;
		if (num <= mini) {
			while (!pq.empty()) pq.pop();
			mini = num;
			min_pos = curr_pos;
		}
		pq.push(make_pair(-num, curr_pos));
		if (min_pos + L == curr_pos) {
			pq.pop();
			while(pq.top().second < curr_pos - L + 1) pq.pop();
			mini = -pq.top().first;
			min_pos = pq.top().second;
		}
		cout << mini << " ";
	}
	return 0;
}
*/
#include <iostream>
#include <deque>
using namespace std;

int N, L, curr_pos, num;
deque< pair<int, int> > window;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> L;
	for (curr_pos = 0; curr_pos < N; curr_pos++) {
		cin >> num;

		while (!window.empty() && window.back().first >= num) window.pop_back();
		while (!window.empty() && window.front().second <= curr_pos - L) window.pop_front();
		window.push_back(make_pair(num, curr_pos));

		cout << window.front().first << " ";
	}
	return 0;
}