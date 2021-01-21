//사이클 찾기로 해결
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findCycle(int, int);

int N, inCycle;
int numbers[101], recur[101];
bool visited[101];
vector<int> picked;

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> numbers[i];
	
	for(int i = 1; i <= N; i++){
		if(!visited[i])	findCycle(i, 1);
	}
	cout << inCycle << "\n";
	sort(picked.begin(), picked.end());
	for(int i = 0; i < (int) picked.size(); i++)
		cout << picked[i] << "\n";
	return 0;
}

bool findCycle(int node, int level){
	visited[node] = true;
	recur[node] = level;
	int nextNode = numbers[node];
	if(!visited[nextNode] && findCycle(nextNode, level + 1)) return true;
	else if(recur[nextNode]){
		inCycle += level - recur[nextNode] + 1;
		int s = nextNode;
		picked.push_back(s);
		s = numbers[s];
		while (s != nextNode) {
			picked.push_back(s);
			s = numbers[s];
		}
	}
	recur[node] = 0;
	return false;
}

/* 단순히 사이클인지만 찾는 방법도 있음
#include<cstdio>
int N, D[101], arr[101], cnt;
bool cycle(int v) {
	int n = D[v];
	for (int i = 1; i <= N; i++) {
		if (v == n) return true;
		n = D[n];
	}
	return false;
}

int main() {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &D[i]);
	for (i = 1; i <= N; i++) if (cycle(i)) arr[i]++, cnt++;
	printf("%d\n", cnt);
	for (i = 1; i <= N; i++) if (arr[i]) printf("%d\n", i);
	return 0;
}
*/