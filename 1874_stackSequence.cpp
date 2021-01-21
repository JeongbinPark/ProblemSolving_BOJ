#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool sqeuence(int n);

vector<char> op;

int main() {
	int n;
	cin >> n;

	if (!sqeuence(n)) cout << "NO";
	else 
		for (int i = 0; i < op.size(); i++)
			cout << op[i] << "\n";

	return 0;
}

bool sqeuence(int n) {
	int val = 0;
	int last = 0;
	stack<int> s;

	
	while(n-->0){
		cin >> val;
		if (!s.empty() && s.top() > val) return false;
		else {
			for (int j = last + 1; j <= val; j++)
			{
				s.push(j);
				op.push_back('+');
				last = j;
			}
			s.pop();
			op.push_back('-');
		}
	}
	return true;
}