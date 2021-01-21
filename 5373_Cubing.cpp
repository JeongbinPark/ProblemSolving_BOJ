//À¸¾Æ°¡¾Æ¾Æ¤¿¾Æ¾Æ¾Ç ³ë°¡´Ù ±ØÇø

#include <iostream>
#include <algorithm>
using namespace std;

void move(char, char);

int t, n;
int cube[7][3][3];
char color[6] = { 'w','g','r','b','y','o' };
char side, direction;
int face, times, tmp1, tmp2, tmp3;

int main() {
	cin >> t;
	while (t--) {
		for (int i = 0; i < 6; i++)
			fill(cube[i][0], cube[i+1][0], i);
		cin >> n;
		while (n--) {
			cin >> side >> direction;
			move(side, direction);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << color[cube[0][i][j]];
			cout << "\n";
		}
	}
	return 0;
}

char faces[7] = { 'U', 'L', 'F', 'R', 'D', 'B' };
int ro[8][2] = { 0,0,0,1,0,2,1,2,2,2,2,1,2,0,1,0 };
int u[12][3] = { 1,0,0,1,0,1,1,0,2,2,0,0,2,0,1,2,0,2,3,0,0,3,0,1,3,0,2,5,2,2,5,2,1,5,2,0 },
d[12][3] = { 3,2,2,3,2,1,3,2,0,2,2,2,2,2,1,2,2,0,1,2,2,1,2,1,1,2,0,5,0,0,5,0,1,5,0,2 },
f[12][3] = { 1,0,2,1,1,2,1,2,2,4,0,0,4,0,1,4,0,2,3,2,0,3,1,0,3,0,0,0,2,2,0,2,1,0,2,0 },
b[12][3] = { 4,2,2,4,2,1,4,2,0,1,2,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,2,3,0,2,3,1,2,3,2,2 },
l[12][3] = { 5,2,0,5,1,0,5,0,0,4,2,0,4,1,0,4,0,0,2,2,0,2,1,0,2,0,0,0,2,0,0,1,0,0,0,0 },
r[12][3] = { 0,0,2,0,1,2,0,2,2,2,0,2,2,1,2,2,2,2,4,0,2,4,1,2,4,2,2,5,0,2,5,1,2,5,2,2 };


void move(char s, char dir) {
	times = dir == '+' ? 1 : 3;
	for (int i = 0; i < 6; i++) {
		if (faces[i] == s) face = i;
	}

	for (int i = 0; i < times; i++) {
		tmp1 = cube[face][ro[1][0]][ro[1][1]], tmp2 = cube[face][ro[0][0]][ro[0][1]];
		for (int i = 7; i > 1; i--) {
			cube[face][ro[(i + 2) % 8][0]][ro[(i + 2) % 8][1]] = cube[face][ro[i][0]][ro[i][1]];
		}
		cube[face][ro[3][0]][ro[3][1]] = tmp1, cube[face][ro[2][0]][ro[2][1]] = tmp2;
	}

	if (face == 0) {
		for (int j = 0; j < times; j++) {
			tmp1 = cube[u[0][0]][u[0][1]][u[0][2]], tmp2 = cube[u[1][0]][u[1][1]][u[1][2]], tmp3 = cube[u[2][0]][u[2][1]][u[2][2]];
			for (int i = 0; i < 9; i++) {
				cube[u[i][0]][u[i][1]][u[i][2]] = cube[u[i + 3][0]][u[i + 3][1]][u[i + 3][2]];
			}
			cube[u[9][0]][u[9][1]][u[9][2]] = tmp1, cube[u[10][0]][u[10][1]][u[10][2]] = tmp2, cube[u[11][0]][u[11][1]][u[11][2]] = tmp3;
		}
	}
	else if (face == 1) {
		for (int j = 0; j < times; j++) {
			tmp1 = cube[l[0][0]][l[0][1]][l[0][2]], tmp2 = cube[l[1][0]][l[1][1]][l[1][2]], tmp3 = cube[l[2][0]][l[2][1]][l[2][2]];
			for (int i = 0; i < 9; i++) {
				cube[l[i][0]][l[i][1]][l[i][2]] = cube[l[i + 3][0]][l[i + 3][1]][l[i + 3][2]];
			}
			cube[l[9][0]][l[9][1]][l[9][2]] = tmp1, cube[l[10][0]][l[10][1]][l[10][2]] = tmp2, cube[l[11][0]][l[11][1]][l[11][2]] = tmp3;
		}
		
	}
	else if (face == 2) {
		for (int j = 0; j < times; j++) {
			tmp1 = cube[f[0][0]][f[0][1]][f[0][2]], tmp2 = cube[f[1][0]][f[1][1]][f[1][2]], tmp3 = cube[f[2][0]][f[2][1]][f[2][2]];
			for (int i = 0; i < 9; i++) {
				cube[f[i][0]][f[i][1]][f[i][2]] = cube[f[i + 3][0]][f[i + 3][1]][f[i + 3][2]];
			}
			cube[f[9][0]][f[9][1]][f[9][2]] = tmp1, cube[f[10][0]][f[10][1]][f[10][2]] = tmp2, cube[f[11][0]][f[11][1]][f[11][2]] = tmp3;
		}
	}
	else if (face == 3) {
		for (int j = 0; j < times; j++) {
			tmp1 = cube[r[0][0]][r[0][1]][r[0][2]], tmp2 = cube[r[1][0]][r[1][1]][r[1][2]], tmp3 = cube[r[2][0]][r[2][1]][r[2][2]];
			for (int i = 0; i < 9; i++) {
				cube[r[i][0]][r[i][1]][r[i][2]] = cube[r[i + 3][0]][r[i + 3][1]][r[i + 3][2]];
			}
			cube[r[9][0]][r[9][1]][r[9][2]] = tmp1, cube[r[10][0]][r[10][1]][r[10][2]] = tmp2, cube[r[11][0]][r[11][1]][r[11][2]] = tmp3;
		}
	}
	else if (face == 4) {
		for (int j = 0; j < times; j++) {
			tmp1 = cube[d[0][0]][d[0][1]][d[0][2]], tmp2 = cube[d[1][0]][d[1][1]][d[1][2]], tmp3 = cube[d[2][0]][d[2][1]][d[2][2]];
			for (int i = 0; i < 9; i++) {
				cube[d[i][0]][d[i][1]][d[i][2]] = cube[d[i + 3][0]][d[i + 3][1]][d[i + 3][2]];
			}
			cube[d[9][0]][d[9][1]][d[9][2]] = tmp1, cube[d[10][0]][d[10][1]][d[10][2]] = tmp2, cube[d[11][0]][d[11][1]][d[11][2]] = tmp3;
		}
	}
	else if (face == 5) {
		for (int j = 0; j < times; j++) {
			tmp1 = cube[b[0][0]][b[0][1]][b[0][2]], tmp2 = cube[b[1][0]][b[1][1]][b[1][2]], tmp3 = cube[b[2][0]][b[2][1]][b[2][2]];
			for (int i = 0; i < 9; i++) {
				cube[b[i][0]][b[i][1]][b[i][2]] = cube[b[i + 3][0]][b[i + 3][1]][b[i + 3][2]];
			}
			cube[b[9][0]][b[9][1]][b[9][2]] = tmp1, cube[b[10][0]][b[10][1]][b[10][2]] = tmp2, cube[b[11][0]][b[11][1]][b[11][2]] = tmp3;
		}
	}
	return;
}