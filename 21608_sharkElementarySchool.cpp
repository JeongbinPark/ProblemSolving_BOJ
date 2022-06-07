#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int, int);
void setLikes(int);
void setStudent(int , int , int);
int getSumSatisfaction();

int N, students_num;
int students[400], liked_students[400][4];
int board[20][20], blanks[20][20], likes[20][20];
int student_row[401], student_col[401];
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };

int main() {
	cin >> N;
	students_num = N * N;

	fill(student_row, student_row + students_num + 1, -1);
	fill(student_col, student_col + students_num + 1, -1);

	fill(&blanks[0][0], &blanks[N - 1][N], 4);

	for (int i = 0; i < N; i++) {
		blanks[0][i]--;
		blanks[N - 1][i]--;
		blanks[i][0]--;
		blanks[i][N - 1]--;
	}

	for (int i = 0; i < students_num; i++) {
		cin >> students[i];
		int max_likes = -1, max_blanks = -1, min_r = -1, min_c = -1;

		setLikes(i);

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (board[r][c]) continue;
				if (likes[r][c] > max_likes) {
					max_likes = likes[r][c];
					max_blanks = blanks[r][c];
					min_r = r;
					min_c = c;
				}
				else if (likes[r][c] == max_likes) {
					if (blanks[r][c] > max_blanks) {
						max_blanks = blanks[r][c];
						min_r = r;
						min_c = c;
					}
				}
			}
		}
		setStudent(students[i], min_r, min_c);
	}
	cout << getSumSatisfaction();
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}

void setLikes(int student_index) {
	fill(&likes[0][0], &likes[N - 1][N], 0);
	for (int j = 0; j < 4; j++) {
		cin >> liked_students[student_index][j];
		int curr_r = student_row[liked_students[student_index][j]];
		int curr_c = student_col[liked_students[student_index][j]];

		if (curr_r == -1 && curr_c == -1) continue;

		for (int d = 0; d < 4; d++) {
			int next_r = curr_r + dr[d];
			int next_c = curr_c + dc[d];

			if (isPossible(next_r, next_c)) {
				likes[next_r][next_c]++;
			}
		}
	}
	return;
}

void setStudent(int student, int r, int c) {
	board[r][c] = student;
	student_row[student] = r;
	student_col[student] = c;

	for (int d = 0; d < 4; d++) {
		int next_r = r + dr[d];
		int next_c = c + dc[d];
		if (isPossible(next_r, next_c)) {
			blanks[next_r][next_c]--;
		}
	}
	return;
}

int getSumSatisfaction() {
	int sumSatisfaction = 0;
	for (int i = 0; i < students_num; i++) {
		int num_satisfaction = 0;
		int student = students[i];
		for (int j = 0; j < 4; j++) {
			for (int d = 0; d < 4; d++) {
				int next_r = student_row[student] + dr[d];
				int next_c = student_col[student] + dc[d];
				if (isPossible(next_r, next_c) && board[next_r][next_c] == liked_students[i][j]) {
					num_satisfaction++;
					break;
				}
			}
		}
		if (num_satisfaction) {
			int amount_satisfaction = 1;
			while (--num_satisfaction) {
				amount_satisfaction *= 10;
			}
			sumSatisfaction += amount_satisfaction;
		}
	}
	return sumSatisfaction;
}