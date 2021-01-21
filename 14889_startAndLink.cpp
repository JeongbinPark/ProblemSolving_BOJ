/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void findMember(int, int);
int calc();

int N, cnt = 0, mini = 10000;
int table[20][20], team1[20];
vector<int> team2;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> table[i][j];
	team1[0] = 1;
	findMember(2, 1);
	cout << mini;
	return 0;
}

void findMember(int n, int level) {
	if (level == N / 2) {
		int index = 0;
		for (int i = 1; i <= N; i++) {
			if (i == team1[index]) index++;
			else team2.push_back(i);
		}
		mini = min(mini, calc());
		team2.clear();
		return;
	}
	for (int i = n; i <= N/2 + level + 1; i++) {
		team1[level] = i;
		findMember(i + 1, level + 1);
	}
	return;
}
int calc() {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N / 2; j++)
			if (i != j) sum1 += table[team1[i] - 1][team1[j] - 1];
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < N / 2; j++)
			if (i != j) sum2 += table[team2[i] - 1][team2[j] - 1];
	return abs(sum1 - sum2);
}
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

void dfs(int, int);

int N, mini = 10000;
int sum1 = 0, sum2 = 0;
int table[20][20];
bool visited[20] = { false };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> table[i][j];
	dfs(0, 0);
	cout << mini;
	return 0;
}
void dfs(int n, int level) {
	if (level == N / 2) {
		sum1 = sum2 = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (visited[i] && visited[j]) sum1 += table[i][j];
				else if (!visited[i] && !visited[j]) sum2 += table[i][j];
			}
		mini = min(mini, abs(sum1 - sum2));
		return;
	}
	visited[n] = true;
	for (int i = n + 1; i <= N; i++) {
		dfs(i, level + 1);
	}
	visited[n] = false;
	return;
}