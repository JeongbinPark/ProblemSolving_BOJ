#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define END 1000001
using namespace std;

int T, N, M, a, b;
long long result, a_cnt, b_cnt;
int sum[1001];
vector<int> A, B;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			A.push_back(sum[j] - sum[i]);
	sort(A.begin(), A.end());
	A.push_back(END);

	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j <= M; j++)
			B.push_back(sum[j] - sum[i]);
	sort(B.begin(), B.end(), greater<int>());
	B.push_back(END);

	a = b = 0;
	a_cnt = b_cnt = 1;
	while (a < (int) A.size() - 1 && b < (int) B.size() - 1) {
		if (A[a] == A[a + 1]) a_cnt++, a++;
		if (B[b] == B[b + 1]) b_cnt++, b++;
		if (A[a] != A[a + 1] && B[b] != B[b + 1]) {
			if (A[a] + B[b] < T) a_cnt = 1, a++;
			else if (A[a] + B[b] > T) b_cnt = 1, b++;
			else {
				result += a_cnt * b_cnt;
				a_cnt = b_cnt = 1;
				a++, b++;
			}
		}
	}
	cout << result;
	return 0;
}

//map�� �̿��Ͽ� A�迭�� �������� key��, ������ value�� ���� ��,
//B�迭�� �������� ����� �� map[T-���籸����]�� ���ذ��� ���� ã�� �� �ִ�.
//�ڵ�� ª���� �޸𸮸� ���� �����ϰ� �ð��� �� �����ɸ�