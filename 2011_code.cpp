#include <iostream>
#define MOD 1000000
using namespace std;

int pre1_cnt, pre2_cnt, curr = 1;
char c;
int curr_c_num, pre_c_num, sum_c_num;

int main() {
	while (cin >> c) {
		pre2_cnt = pre1_cnt;
		pre1_cnt = curr;
		pre_c_num = curr_c_num;

		curr_c_num = c - '0';

		if (!pre_c_num) {
			if (!curr_c_num) {
				curr = 0;
				break;
			}
			curr = pre1_cnt;
		}
		else {
			sum_c_num = pre_c_num * 10 + curr_c_num;
			if (!curr_c_num) {
				if (!(pre_c_num == 1 || pre_c_num == 2)) {
					curr = 0;
					break;
				}
				curr = pre2_cnt;
			} else if (sum_c_num > 26) curr = pre1_cnt;
			else curr = (pre1_cnt + pre2_cnt) % MOD;
		}
	}
	cout << curr;
	return 0;
}