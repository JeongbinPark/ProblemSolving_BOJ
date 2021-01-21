/* 틀림
22, 33, 34, 37 등에서 틀림
-> 12(7) -> 11(8) -> 22(10) 되어야함.
#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int S, tmp, mini;
int cnts[1001];

int main() {
	cin >> S;
	for (int i = 2; i <= MAX; i++)
		cnts[i] = i;
	for (int i = 1; i <= MAX / 2; i++) {
		tmp = cnts[i] + 1;
		for (int j = 2 * i; j <= MAX; j += i) {
			cnts[j] = min(cnts[j], ++tmp);
		}
	}
	mini = cnts[S];
	for (int i = S + 1; i <= MAX; i++) {
		mini = min(mini, cnts[i] + i - S);
	}
	cout << mini;
	return 0;
}

*/

#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);

int S, screen, clipboard, time;
int times[1001][1001];
queue< pair< pair<int, int>, int> > q;

int main() {
	cin >> S;
	q.push(make_pair(make_pair(1, 0), 0));
	while (!q.empty()) {
		screen = q.front().first.first;
		clipboard = q.front().first.second;
		time = q.front().second;
		q.pop();

		if (screen == S) break;

		if (isPossible(screen, screen) && !times[screen][screen]) {
				times[screen][screen] = time + 1;
				q.push(make_pair(make_pair(screen, screen), time + 1));
		}
		if (isPossible(screen + clipboard, clipboard) && !times[screen + clipboard][clipboard]) {
			times[screen + clipboard][clipboard] = time + 1;
			q.push(make_pair(make_pair(screen + clipboard, clipboard), time + 1));
		}
		if (isPossible(screen - 1, clipboard) && !times[screen - 1][clipboard]) {
			times[screen - 1][clipboard] = time + 1;
			q.push(make_pair(make_pair(screen - 1, clipboard), time + 1));
		}
	}
	cout << time;
	return 0;
}
bool isPossible(int a, int b) {
	return a > 0 && a <= 1000 && b > 0 && b <= 1000;
}
