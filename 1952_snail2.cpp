/*제출은 안했지만 이 방법.. 시간초과 날거같음.
test 기준 70 70 만해도 안나옴.
#include <iostream>
using namespace std;

void find(int, int);

int N, M, cnt = 0;
int possible[100][100];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			possible[i][j] = 1;
	find(0, 0);
	cout << cnt - 1;
	return 0;
}
void find(int x, int y) {
	if (!possible[x][y]) return;
	possible[x][y] = 0;
	if (!possible[x + dx[cnt % 4]][y + dy[cnt % 4]]) 
		cnt++;
	find(x + dx[cnt % 4], y + dy[cnt % 4]);
	return;
}
*/
/*
이동 칸이 N(R), M-1(D), N-1(L), M-2(U), N-2(R) ..으로 하나가 1이되면 종료
#include <iostream>
using namespace std;

int main() {
	int N, M, cnt = 0;
	cin >> M >> N;
	M--;
	while (N && M)
		cnt++ % 2 ? M-- : N--;
	cout << cnt;
	return 0;
}
*/

//위 식을 계산으로만 한다면
#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> M >> N;
	cout << (M > N ? (N - 1) * 2 + 1 : (M - 1) * 2);
	return 0;
}
