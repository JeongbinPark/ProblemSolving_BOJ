// 시간 초과
/*
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int boys[3], girls[3];
int result[3][2];

bool dfs(int, int, int);

int main() {
	cin >> N;
	for (int i = 0; i < 3; i++) {
		cin >> boys[i] >> girls[i];
	}
	if (dfs(0, 1, 0)) {
		cout << 1 << "\n";
		for (int i = 0; i < 3; i++)
			cout << result[i][0] << " " << result[i][1] << "\n";
	}
	else cout << 0 << "\n";

	return 0;
}

bool dfs(int idx_boy, int idx_girl, int level) {
	if (level == 6) {
		for (int i = 0; i < 3; i++) {
			if (boys[i] || girls[i]) return false;
		}
		return true;
	}
	int next_idx_boy = idx_boy + (idx_girl + 1) / 3;
	int next_idx_girl = (idx_girl + 1) % 3;
	if (next_idx_boy == next_idx_girl) next_idx_girl++;
	

	int min_val = min(boys[idx_boy], girls[idx_girl]);
	
	for (int i = min_val; i >= 0; i--) {
		boys[idx_boy] -= i;
		girls[idx_girl] -= i;
		result[idx_boy][level%2] = i;

		if(dfs(next_idx_boy, next_idx_girl, level + 1)) return true;

		boys[idx_boy] += i;
		girls[idx_girl] += i;
		result[idx_boy][level%2] = 0;
	}

	return false;
}*/


#include <iostream>
using namespace std;

int N;
int boys[3], girls[3];
int result[6];
bool found = false;

int main() {
	cin >> N;
	for (int i = 0; i < 3; i++)
		cin >> boys[i] >> girls[i];
	for (int i = 0; i <= boys[0]; i++) {
		result[0] = i;
		result[1] = boys[0] - i;
		result[3] = girls[2] - result[1];
		result[2] = boys[1] - result[3];
		result[4] = girls[0] - result[2];
		result[5] = boys[2] - result[4];
		if (result[0] >= 0 && result[1] >= 0 && result[2] >= 0 && result[3] >= 0 && result[4] >= 0 && result[5] >= 0 && result[6] >= 0) {
			found = true;
			break;
		}
	}
	if (found) {
		cout << 1 << "\n";
		for (int i = 0; i < 6; i += 2) {
			cout << result[i] << " " << result[i + 1] << "\n";
		}
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}