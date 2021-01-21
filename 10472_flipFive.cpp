/*
#include <iostream>
using namespace std;

int r, c;
int board[5][5];
int cnt;

int main() {
	while (true) {
		cin >> r >> c;

		if (r == 0 && c == 0) {
			for (int i = 0; i <= 4; i++)
				for (int j = 0; j <= 4; j++)
					board[i][j] = 0;
			cnt = 0;

			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (board[i][j] % 2) cout << "бс";
					else cout << "бр";
				}
				cout << "\n";
			}
			cout << "count : " << 0;
			cout << "\n\n";
			continue;
		}
		else if(r == 0 && c == 1) {
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					cout << board[i][j];
				}
				cout << "\n";
			}
			cout << "\n\n";
			continue;
		}

		board[r][c]++, board[r - 1][c]++, board[r + 1][c]++, board[r][c - 1]++, board[r][c + 1]++;

		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (board[i][j] % 2) cout << "бс";
				else cout << "бр";
			}
			cout << "\n";
		}
		cout << "count : " << ++cnt;
		cout << "\n\n";
	}
	return 0;
}
//брбс
*/

/*
#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

bool isResult();

int T;
char ch, result_board[5][5];
int board[5][5];

int main(){
	cin >> T;
	for(T--){
		for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++){
				cin >> ch;
				result_board[i][j];
			}
		
		priority_queue<int, string> pq;
		pq.push(0, "000000000");
		while(!pq.empty()){
			int clicked = -pq.first;
			string clicked_state = pq.second;
			pq.pop();
			
			fill(board[0], board[4], 0);
			for(int i = 0; i <= 9; i++){
				clicked_state[i] = '1';
				int r = i / 3 + 1;
				int c = i % 3 + 1;
				board[r][c]++, board[r - 1][c]++, board[r + 1][c]++, board[r][c - 1]++, board[r][c + 1]++;
			}
			if(isResult()) return clicked;
			
		}
		
		
	}
	return 0;
}
bool isResult(){
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			if((result_board[i][j] == '.' && board[i][j] % 2) || (result_board[i][j] == '*' && !(board[i][j] % 2))) return false;
	return true;
}
*/

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void makeBoard(string);
bool isResult();
bool visited(string);

int T;
char ch, result_board[5][5];
int board[5][5];

set<string> s;
set<string>::iterator it;

int main() {
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++) {
				cin >> ch;
				result_board[i][j] = ch;
			}

		s.clear();
		s.insert("000000000");

		priority_queue< pair<int, string> > pq;
		pq.push(make_pair(0, "000000000"));
		while (!pq.empty()) {
			int clicked = -pq.top().first;
			string curr_state = pq.top().second;
			pq.pop();

			makeBoard(curr_state);

			if (isResult()) {
				cout << clicked << "\n";
				break;
			}

			for (int i = 0; i < 9; i++) {
				string next_state = curr_state;
				next_state[i] = '1';
				it = s.find(next_state);
				if (curr_state[i] == '0' && it == s.end()) {
					s.insert(next_state);
					pq.push(make_pair(-clicked - 1, next_state));
				}
			}
		}
	}
	return 0;
}
void makeBoard(string curr_state) {
	fill(board[0], board[4], 0);
	for (int i = 0; i <= 9; i++) {
		if (curr_state[i] == '1') {
			int r = i / 3 + 1;
			int c = i % 3 + 1;
			board[r][c]++, board[r - 1][c]++, board[r + 1][c]++, board[r][c - 1]++, board[r][c + 1]++;
		}
	}
}
bool isResult() {
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			if ((result_board[i][j] == '.' && board[i][j] % 2) || (result_board[i][j] == '*' && !(board[i][j] % 2))) return false;
	return true;
}
bool visited(string next_state) {
	set<string>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
		if (*it == next_state) return true;
	return false;
}