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

void chooseChicken(int chickenIndex, int chosenChicken,	vector<int> min_CDs) {	//어디까지 읽었는지, 몇 개 선택했는지
	//선택한 치킨 집의 수가 M개면 최소 거리 비교
	if (chosenChicken == M) {
		int sum = 0;
		for (int i = 0; i < num_house; i++) sum += min_CDs[i];
		min_CD = min(min_CD, sum);
		return;
	}
	//치킨집 수가 최대 치킨 집 수를 넘으면 return
	if (chickenIndex == num_chicken)
		return;
	
	//선택하지 않는 경우
	chooseChicken(chickenIndex + 1, chosenChicken, min_CDs);
	//선택하는 경우
	for (int i = 0; i < num_house; i++) {
		min_CDs[i] = min(min_CDs[i], chickenDistance[chickenIndex][i]);
	}
	chooseChicken(chickenIndex + 1, chosenChicken + 1, min_CDs);
	return;
}