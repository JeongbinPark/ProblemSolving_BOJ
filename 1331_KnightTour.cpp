#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool knight(int pre_x, int pre_y, int x, int y);

int main() {
	int visited[6][6] = { 0 };
	bool isValid = true;
	string str;
	int x, y, pre_x, pre_y, s_x, s_y;
	cin >> str;
	s_x = pre_x = str[0] - 'A';
	s_y = pre_y = str[1] - '1';
	visited[s_x][s_y] = 1;
	for (int i = 1; i < 36; i++)
	{
		cin >> str;
		x = str[0] - 'A';
		y = str[1] - '1';
		if (!visited[x][y] && knight(pre_x, pre_y, x, y))
			visited[x][y] = 1;
		else {
			isValid = false;
			break;
		}
		pre_x = x;
		pre_y = y;
	}
	if (!knight(pre_x, pre_y, s_x, s_y)) isValid = false;
	cout << (isValid? "Valid": "Invalid");
	return 0;
}
bool knight(int pre_x, int pre_y, int x, int y) {
	return (abs(pre_x - x) == 2 && abs(pre_y - y) == 1) || (abs(pre_x - x) == 1 && abs(pre_y - y) == 2);
}