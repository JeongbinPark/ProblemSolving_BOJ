#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define INF 10000000
using namespace std;

void chooseChicken(int, int, vector<int>);

int N, M, num;
vector<pair <int, int> > chicken;
vector<pair <int, int> > house;
vector<int> chickenDistance[13];

int num_chicken;
int num_house;
int min_CD;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num == 1) house.push_back(make_pair(i, j));
			else if (num == 2) chicken.push_back(make_pair(i, j));
		}
	}

	num_chicken = (int)chicken.size();
	num_house = (int)house.size();

	for (int i = 0; i < num_chicken; i++) {
		int r_chicken = chicken[i].first;
		int c_chicken = chicken[i].second;

		for (int j = 0; j < num_house; j++) {
			int r_house = house[j].first;
			int c_house = house[j].second;
			int chickenDist = abs(r_chicken - r_house) + abs(c_chicken - c_house);
			chickenDistance[i].push_back(chickenDist);
		}
	}
	min_CD = INF;
	vector<int> min_CDs;
	for (int i = 0; i < num_house; i++) {
		min_CDs.push_back(INF);
	}
	chooseChicken(0,0, min_CDs);
	cout << min_CD;

	return 0;
}

void chooseChicken(int chickenIndex, int chosenChicken,	vector<int> min_CDs) {	//������ �о�����, �� �� �����ߴ���
	//������ ġŲ ���� ���� M���� �ּ� �Ÿ� ��
	if (chosenChicken == M) {
		int sum = 0;
		for (int i = 0; i < num_house; i++) sum += min_CDs[i];
		min_CD = min(min_CD, sum);
		return;
	}
	//ġŲ�� ���� �ִ� ġŲ �� ���� ������ return
	if (chickenIndex == num_chicken)
		return;
	
	//�������� �ʴ� ���
	chooseChicken(chickenIndex + 1, chosenChicken, min_CDs);
	//�����ϴ� ���
	for (int i = 0; i < num_house; i++) {
		min_CDs[i] = min(min_CDs[i], chickenDistance[chickenIndex][i]);
	}
	chooseChicken(chickenIndex + 1, chosenChicken + 1, min_CDs);
	return;
}