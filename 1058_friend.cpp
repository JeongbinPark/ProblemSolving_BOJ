#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
char ch;
bool friends[50][50] = { false };
int visited_friends[50] = { 0 };
int max_cnt = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			if (ch == 'Y') friends[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visited_friends, 0, N * sizeof(int));
		visited_friends[i] = -1;
		int cnt = 0;
		queue<int> q;
		for (int j = 0; j < N; j++) {
			if (friends[i][j]) {
				q.push(j);
				visited_friends[j] = 1;
				cnt++;
			}
		}
		while (!q.empty()) {
			int front = q.front();
			q.pop();

			for (int j = 0; j < N; j++) {
				if (friends[front][j] && !visited_friends[j]) {
					visited_friends[j] = 1;
					cnt++;
				}
			}
		}
		max_cnt = max_cnt < cnt ? cnt : max_cnt;
	}
	cout << max_cnt;
	return 0;
}


/*
#include <iostream>
#include <cstring>
using namespace std;

int N;
char ch;
bool friends[50][50] = { false };
int visited_friends[50] = { 0 };
int max_cnt = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			if (ch == 'Y') friends[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visited_friends, 0, N*sizeof(int));
		visited_friends[i] = -1;
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (friends[i][j] && !visited_friends[j]) {
				cnt++;
				visited_friends[j] = 1;
				for (int k = 0; k < N; k++) {
					if (friends[j][k] && !visited_friends[k]) {
						cnt++;
						visited_friends[k] = 1;
					}
				}
			}
		}
		max_cnt = max_cnt < cnt ? cnt : max_cnt;
	}
	cout << max_cnt;
	return 0;
}
*/