#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(int);
void merge(int, int);

int V, E;
int vertex1, vertex2, edge;
vector< pair< int, pair< int, int> > > edges;
long long mst = 0;
int root[10001];
int length[10001];

int main(){
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		cin >> vertex1 >> vertex2 >> edge;
		edges.push_back(make_pair(edge, make_pair(vertex1, vertex2)));
	}
	for (int i = 1; i <= V; i++) {
		root[i] = i;
		length[i] = 1;
	}

	sort(edges.begin(), edges.end());
	
	vector<pair<int, pair<int, int> > >::iterator it;
	int num_edges = 0;
	for(it = edges.begin(); num_edges < V && it != edges.end(); it++){
		edge = (*it).first;
		vertex1 = (*it).second.first;
		vertex2 = (*it).second.second;
		
		if(find(vertex1) == find(vertex2)) continue;
		
		num_edges++;
		mst += edge;
		merge(vertex1, vertex2);
	}
	
	cout << mst;
	return 0;
}

int find(int node){
	if(node == root[node]) return node;
	return root[node] = find(root[node]);
};

void merge(int node1, int node2){
	int root1 = find(node1);
	int root2 = find(node2);
	
	if(root1 == root2) return;
	
	if(length[root1] == length[root2]){
		root[root2] = root1;
		length[root1]++;
	}else {
		if(length[root1] > length[root2]) swap(root1, root2);
		root[root2] = root1;
	}
};