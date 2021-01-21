/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void op(int value, int count);

vector<int> vec;

int main() {
	int X;
	cin >> X;
	op(X, 0);
	
	int m = vec[0];
	for (int i = 1; i < (int) vec.size(); i++)
		m =  min(m, vec[i]);
	cout << m;
	return 0;
}
void op(int value, int count) {
	if (value == 1) {
		vec.push_back(count);
		return;
	}
	if (value % 6 == 0) op(value / 6, count + 2);
	else {
		if (value % 3 == 0) op(value / 3, count + 1);
		if (value % 2 == 0) op(value / 2, count + 1);
	}
	op(value - 1, count + 1);
	return;
}
//메모리 초과
//이미 계산한 것은 객체에 넣어서 객체에 있는지 찾아 더하는 방법?
*/

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	int X;
	cin >> X;
	dp[0] = dp[1] = 0;
 	for (int i = 2; i <= X; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[X];
	return 0;
}
