#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int r, int c);

struct Virus {
	int time;
	int virusNumber;
	int r, c;
};

bool operator< (Virus v1, Virus v2) {
	if (v1.time == v2.time) {
		return v1.virusNumber > v2.virusNumber;
	}
	return v1.time > v2.time;
}

int N, K, S, X, Y, num;
bool visited[200][200];
priority_queue<Virus> pq;
int dR[] = { 0, 1, 0, -1 }, dC[] = { 1, 0, -1, 0 };

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num) {
				Virus virus;
				virus.r = i;
				virus.c = j;
				virus.time = 0;
				virus.virusNumber = num;
				pq.push(virus);
				visited[i][j] = true;
			}
		}
	}
	cin >> S >> X >> Y;
	while (!pq.empty()) {
		int currTime = pq.top().time;
		int currVirusNum = pq.top().virusNumber;
		int currR = pq.top().r;
		int currC = pq.top().c;
		pq.pop();

		if (currTime <= S && currR == X - 1&& currC == Y - 1) {
			cout << currVirusNum;
			return 0;
		}
		if (currTime > S) break;

		for (int d = 0; d < 4; d++) {
			int nextTime = currTime + 1;
			int nextR = currR + dR[d];
			int nextC = currC + dC[d];
			if (isPossible(nextR, nextC) && !visited[nextR][nextC]) {
				visited[nextR][nextC] = true;
				Virus virus;
				virus.time = nextTime;
				virus.virusNumber = currVirusNum;
				virus.r = nextR;
				virus.c = nextC;
				pq.push(virus);
			}
		}
	}
	cout << 0;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}