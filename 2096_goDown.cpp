/* 메모리 초과 => 슬라이딩윈도우 이용해야함
#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, c;
int numbers[100000][3][2];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		numbers[i][0][0] = numbers[i][0][1] = a;
		numbers[i][1][0] = numbers[i][1][1] = b;
		numbers[i][2][0] = numbers[i][2][1] = c;
	}
	for (int i = n - 2; i >= 0; i--) {
		numbers[i][0][0] += max(numbers[i + 1][0][0], numbers[i + 1][1][0]);
		numbers[i][1][0] += max(numbers[i + 1][0][0], max(numbers[i + 1][1][0], numbers[i + 1][2][0]));
		numbers[i][2][0] += max(numbers[i + 1][1][0], numbers[i + 1][2][0]);
		numbers[i][0][1] += min(numbers[i + 1][0][1], numbers[i + 1][1][1]);
		numbers[i][1][1] += min(numbers[i + 1][0][1], min(numbers[i + 1][1][1], numbers[i + 1][2][1]));
		numbers[i][2][1] += min(numbers[i + 1][1][1], numbers[i + 1][2][1]);
	}
	cout << max(numbers[0][0][0], max(numbers[0][1][0], numbers[0][2][0])) << " " << min(numbers[0][0][1], min(numbers[0][1][1], numbers[0][2][1]));
	return 0;
}
*/
/*
틀림 => 1 -> 2 -> 3 선택불가능
#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, c;
int numbers[3][2];

int main() {
	cin >> n;
	cin >> a >> b >> c;
	numbers[0][0] = numbers[0][1] = a;
	numbers[1][0] = numbers[1][1] = b;
	numbers[2][0] = numbers[2][1] = c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		numbers[0][0] += max(a, b);
		numbers[1][0] += max(a, max(b, c));
		numbers[2][0] += max(b, c);
		numbers[0][1] += min(a, b);
		numbers[1][1] += min(a, min(b, c));
		numbers[2][1] += min(b, c);
	}
	cout << max(numbers[0][0], max(numbers[1][0], numbers[2][0])) << " " << min(numbers[0][1], min(numbers[1][1], numbers[2][1]));
	return 0;
}
*/

/* 이전 선택저장 => 틀림
#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, c, tmp2;
int numbers[3][2], pre_num[3], pre_choice[3][2] = {0, 0, 1, 1, 2, 2}, tmp[3][2];

int main() {
	cin >> n;
	cin >> a >> b >> c;
	numbers[0][0] = numbers[0][1] = a;
	numbers[1][0] = numbers[1][1] = b;
	numbers[2][0] = numbers[2][1] = c;
	for (int i = 1; i < n; i++) {
		if (i == 1) {
			cin >> pre_num[0] >> pre_num[1] >> pre_num[2];
		}
		if (i == n - 1) a = b = c = 0;
		else cin >> a >> b >> c;

		tmp[0][0] = pre_num[0] + max(a, b);
		tmp[1][0] = pre_num[1] + max(a, max(b, c));
		tmp[2][0] = pre_num[2] + max(b, c);

		tmp[0][1] = pre_num[0] + min(a, b);
		tmp[1][1] = pre_num[1] + min(a, min(b, c));
		tmp[2][1] = pre_num[2] + min(b, c);

		for (int i = 0; i < 3; i++) {
			if (pre_choice[i][0] == 0) {
				 tmp2 = tmp[0][0] > tmp[1][0] ? 0 : 1;
			}
			else if (pre_choice[i][0] == 1) {
				tmp2 = tmp[0][0] > tmp[1][0] ? 0 : 1;
				tmp2 = tmp[tmp2][0] > tmp[2][0] ? tmp2 : 2;
			}
			else if (pre_choice[i][0] == 2) {
				tmp2 = tmp[1][0] > tmp[2][0] ? 1 : 2;
			}
			numbers[i][0] += pre_num[tmp2];
			pre_choice[i][0] = tmp2;

			if (pre_choice[i][1] == 0) {
				tmp2 = tmp[0][1] < tmp[1][1] ? 0 : 1;
			}
			else if (pre_choice[i][1] == 1) {
				tmp2 = tmp[0][1] < tmp[1][1] ? 0 : 1;
				tmp2 = tmp[tmp2][1] < tmp[2][1] ? tmp2 : 2;
			}
			else if (pre_choice[i][1] == 2) {
				tmp2 = tmp[1][1] < tmp[2][1] ? 1 : 2;
			}
			numbers[i][1] += pre_num[tmp2];
			pre_choice[i][1] = tmp2;
		}
		
		pre_num[0] = a, pre_num[1] = b, pre_num[2] = c;
	}
	cout << max(numbers[0][0], max(numbers[1][0], numbers[2][0])) << " " << min(numbers[0][1], min(numbers[1][1], numbers[2][1]));
	return 0;
}
*/

//반대로 생각하기
//즉, numbers[i][0]가 numbers[i+1][0]과 numbers[i+1][1] 중에 선택이 아닌
//numbers[i][0]가 numbers[i-1][0]과 numbers[i-1][1] 중에 선택되는 것
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, curr_num[3], pre_max[3], pre_min[3], tmp_max[3], tmp_min[3];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> curr_num[0] >> curr_num[1] >> curr_num[2];
	for(int i = 0; i < 3; i++)	pre_max[i] = pre_min[i] = curr_num[i];
	while (--n) {
		memcpy(tmp_max, pre_max, sizeof(pre_max));
		memcpy(tmp_min, pre_min, sizeof(pre_min));
		cin >> curr_num[0] >> curr_num[1] >> curr_num[2];
		pre_max[0] = curr_num[0] + *max_element(tmp_max, tmp_max + 2);
		pre_max[1] = curr_num[1] + *max_element(tmp_max, tmp_max + 3);
		pre_max[2] = curr_num[2] + *max_element(tmp_max + 1, tmp_max + 3);
		pre_min[0] = curr_num[0] + *min_element(tmp_min, tmp_min + 2);
		pre_min[1] = curr_num[1] + *min_element(tmp_min, tmp_min + 3);
		pre_min[2] = curr_num[2] + *min_element(tmp_min + 1, tmp_min + 3);
	}
	cout << *max_element(pre_max, pre_max + 3)<< " " << *min_element(pre_min, pre_min + 3);
	return 0;
}