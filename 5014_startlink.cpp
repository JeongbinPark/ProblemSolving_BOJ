#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D, curr_floor, curr_times;
bool visited[1000001];
queue<pair<int, int> > q;

int main() {
	cin >> F >> S >> G >> U >> D;
	q.push(make_pair(S, 0));
	visited[S] = true;
	while (!q.empty()) {
		curr_floor = q.front().first;
		curr_times = q.front().second;
		q.pop();
		if (curr_floor == G) {
			cout << curr_times;
			return 0;
		}
		if (curr_floor + U > 0 && curr_floor + U <= F && !visited[curr_floor + U]) {
			visited[curr_floor + U] = true;
			q.push(make_pair(curr_floor + U, curr_times + 1));
		}
		if (curr_floor - D > 0 && curr_floor - D <= F && !visited[curr_floor - D]) {
			visited[curr_floor - D] = true;
			q.push(make_pair(curr_floor - D, curr_times + 1));
		}
	}
	cout << "use the stairs";
	return 0;
}