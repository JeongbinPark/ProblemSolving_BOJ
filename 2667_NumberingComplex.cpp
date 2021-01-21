/* visited �迭�� ���� ����
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

//visited�� board�� 0���� ó��
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

//���ڷ� ���� �ȹٲ㵵 ��. '0', '1' ���ڷ� ó�� ����
//�׷��� char �����迭�� ���� �� �� ù �ּҷ� string ������ ��.
//�����¿� 4�����̴� find �Լ� return type�� int�� �ؼ� return find(x+1, y) + find(x-1, y) + find(x, y+1) + find(x+1, y-1) + 1;
