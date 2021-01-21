/* visited 배열로 따로 존재
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(int, int);

int N, cnt = 0;
char c;
int board[25][25];
bool visited[25][25] = { false };
vector<int> result;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> c;
			board[i][j] = c - '0';
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] && !visited[i][j]) {
				cnt = 0;
				find(i, j);
				result.push_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}
void find(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (!board[x][y] || visited[x][y]) return;
	cnt++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
		find(x + dx[i], y + dy[i]);
	return;
};

*/

//visited를 board의 0으로 처리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(int, int);

int N, cnt = 0;
char c;
int board[25][25];
vector<int> result;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> c;
			board[i][j] = c - '0';
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j]) {
				cnt = 0;
				find(i, j);
				result.push_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}
void find(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (!board[x][y]) return;
	cnt++;
	board[x][y] = 0;
	for (int i = 0; i < 4; i++)
		find(x + dx[i], y + dy[i]);
	return;
};

//숫자로 굳이 안바꿔도 됨. '0', '1' 문자로 처리 가능
//그러면 char 이차배열로 선언 후 각 첫 주소로 string 받으면 됨.
//상하좌우 4개뿐이니 find 함수 return type을 int로 해서 return find(x+1, y) + find(x-1, y) + find(x, y+1) + find(x+1, y-1) + 1;
