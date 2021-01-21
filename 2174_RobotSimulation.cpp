//으아.....!!! 오타내지말라고!!!!!!!
#include <iostream>
using namespace std;

int A, B, N, M, x, y, robot, repeat;
int curr_r, curr_c, curr_d;
char dir, command;
int board[101][101], robots[101][3];
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };

int main() {
	cin >> A >> B >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> dir;
		board[x][y] = i;
		robots[i][0] = x, robots[i][1] = y;
		if (dir == 'N') robots[i][2] = 0;
		else if (dir == 'E') robots[i][2] = 1;
		else if (dir == 'S') robots[i][2] = 2;
		else robots[i][2] = 3;
	}
	while (M--) {
		cin >> robot >> command >> repeat;
		curr_r = robots[robot][0];
		curr_c = robots[robot][1];
		curr_d = robots[robot][2];
		board[curr_r][curr_c] = 0;
		while (repeat--) {
			if (command == 'F') {
				curr_r += dr[curr_d];
				curr_c += dc[curr_d];
				if (curr_r<1 || curr_r>A || curr_c<1 || curr_c>B) {
					cout << "Robot " << robot << " crashes into the wall";
					return 0;
				}
				else if (board[curr_r][curr_c]) {
					cout << "Robot " << robot << " crashes into robot " << board[curr_r][curr_c];
					return 0;
				}
			}
			else if (command == 'L') {
				curr_d = (4 + curr_d - 1) % 4;
			}
			else {
				curr_d = (4 + curr_d + 1) % 4;
			}
		}
		robots[robot][0] = curr_r;
		robots[robot][1] = curr_c;
		robots[robot][2] = curr_d;
		board[curr_r][curr_c] = robot;
	}
	cout << "OK";
	return 0;
}