#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int sum = 0;
	int K, temp;

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> temp;
		if(temp) s.push(temp);
		else s.pop();
	}
	while (!s.empty()) {
		temp = s.top();
		s.pop();
		sum += temp;
	}
	cout << sum;
	return 0;
}