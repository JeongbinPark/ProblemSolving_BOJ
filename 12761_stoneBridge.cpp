#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, A, B;
int visited[100001] = { 0 };
priority_queue< pair <int, int> > pq;

int main() {
	cin >> A >> B >> N >> M;

	pq.push(make_pair(0, N));
	visited[N] = true;
	
	while (!pq.empty()) {
		int curr_time = -pq.top().first;
		int curr_loc = pq.top().second;
		pq.pop();
		if (curr_loc == M) {
			cout << curr_time;
			return 0;
		}

		for (int d = 1; d <= 8; d++) {
			int next_loc = curr_loc;
			switch (d)
			{
			case 1: next_loc += 1;
				break;
			case 2: next_loc -= 1;
				break;
			case 3: next_loc += A;
				break;
			case 4: next_loc -= A;
				break;
			case 5: next_loc += B;
				break;
			case 6: next_loc -= B;
				break;
			case 7: next_loc *= A;
				break;
			case 8: next_loc *= B;
				break;
			default: next_loc = curr_loc;
				break;
			}

			if (next_loc >= 0 && next_loc < 100001 && !visited[next_loc]) {
				visited[next_loc] = true;
				pq.push(make_pair(-(curr_time + 1), next_loc));
			}
		}
	}

	return 0;
}