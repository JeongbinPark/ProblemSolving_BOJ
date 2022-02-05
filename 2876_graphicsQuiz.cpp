#include <iostream>
using namespace std;

int main() {
	int N;
	int A, B;
	bool tables[100001][5] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		tables[i][A-1] = true; 
		tables[i][B-1] = true;
	}

	int max_count = 0;
	int max_grade = 6;
	for (int grade = 4; grade >= 0; grade--) {
		int current_count = 0;
		for (int row = 0; row <= N; row++) {
			if (tables[row][grade]) current_count++;
			if ((row == 0 || tables[row - 1][grade]) && !tables[row][grade]) {
				if (max_count <= current_count) {
					max_count = current_count;
					max_grade = grade;
				}
				current_count = 0;
			}
		}
	}

	cout << max_count << " " << max_grade + 1;
	
	return 0;
}



/*
#include <iostream>
using namespace std;

int N;
int A, B;
int max_consecutiveGrade[6] = { 0 };
int current_consecutiveGrade[6] = { 0 };


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		for (int grade = 1; grade <= 5; grade++) {
			if (grade == A || grade == B) continue;
			if (current_consecutiveGrade[grade] > max_consecutiveGrade[grade]) {
				max_consecutiveGrade[grade] = current_consecutiveGrade[grade];
				current_consecutiveGrade[grade] = 0;
			}
		}
		current_consecutiveGrade[A]++;
		if (A != B) { current_consecutiveGrade[B]++; }
	}

	for (int grade = 1; grade <= 5; grade++) {
		if (current_consecutiveGrade[grade] > max_consecutiveGrade[grade]) {
			max_consecutiveGrade[grade] = current_consecutiveGrade[grade];
			current_consecutiveGrade[grade] = 0;
		}
	}

	int max_student = 0, max_grade = 6;
	for (int grade = 1; grade <= 5; grade++) {
		if (max_student < max_consecutiveGrade[grade]) {
			max_student = max_consecutiveGrade[grade];
			max_grade = grade;
		}
	}
	cout << max_student << " " << max_grade;
	return 0;
}
*/