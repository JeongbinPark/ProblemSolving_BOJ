#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findNext(int);

int N, M, num;
vector<int> numbers;
bool visited[8];
int result[8];

int main() {
	cin >> N >> M;
	while (N--) {
		cin >> num;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	findNext(0);
	return 0;
}
void findNext(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	result[cnt] = 0;
	for (int i = 0; i < (int)numbers.size(); i++) {
		int number = numbers[i];
		if (result[cnt] != number && !visited[i]) {
			visited[i] = true;
			result[cnt] = number;
			findNext(cnt + 1);
			visited[i] = false;
		}
	}
	return;
}