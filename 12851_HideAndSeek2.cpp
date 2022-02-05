#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_VAL 100000
using namespace std;

bool isPossible(int);

int N, K;
int visited[100002] = { 0 };
priority_queue< pair<int, int> > pq;
int minTime = MAX_VAL;
int maxWays = 0;

int main() {
	fill_n(visited, 100001, MAX_VAL);

	cin >> N >> K;
	visited[N] = 0;
	pq.push(make_pair(0, N));

	while (!pq.empty()) {
		int currTime = -pq.top().first;
		int currLoc = pq.top().second;
		pq.pop();

		if (visited[K] < currTime) break;

		if (currLoc == K) {
			if (!maxWays) minTime = currTime;
			maxWays++;
		}

		for (int i = 0; i < 3; i++) {
			int nextTime = currTime + 1;
			int nextLoc = currLoc;
			if (i == 0) nextLoc++;
			else if (i == 1) nextLoc--;
			else nextLoc += currLoc;

			if (isPossible(nextLoc) && visited[nextLoc] >= nextTime) {
				visited[nextLoc] = nextTime;
				pq.push(make_pair(-nextTime, nextLoc));
			}

		}
	}
	cout << minTime << "\n" << maxWays;
}

bool isPossible(int x) {
	return x >= 0 && x <= MAX_VAL;
}