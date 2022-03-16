#include <iostream>
using namespace std;

int N, M;
char c;
bool input_matrix[50][50];
bool output_matrix[50][50];
int cnt;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			input_matrix[i][j] = c == '1' ? true : false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			output_matrix[i][j] = c == '1' ? true : false;
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (input_matrix[i][j] != output_matrix[i][j]) {
				cnt++;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						input_matrix[i + k][j + l] = !input_matrix[i + k][j + l];
					}
				}
			}
		}
	}
	if (cnt && (N < 3 || M < 3)){
		cout << -1;
		return 0;
	}

	bool isPossible = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (input_matrix[i][j] != output_matrix[i][j]) {
				isPossible = false;
				break;
			}
		}
	}

	cout << (isPossible ? cnt : -1);
	return 0;
}