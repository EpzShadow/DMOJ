#include<bits/stdc++.h>
using namespace std;
static vector<vector<int>>adj;
void dfs(int node, vector<bool>& visited, int &counterOfEdges, int &counterOfVerticies) {
	visited[node] = true;
	counterOfVerticies++;
	counterOfEdges += adj[node].size();
	vector<int>::iterator i;
	for (i = adj[node].begin(); i != adj[node].end(); i++) {
		if (!visited[*i]) {
			dfs(*i, visited, counterOfEdges, counterOfVerticies);
		}
	}
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, m, k, components = 0, extraPipes = 0;
	cin >> n >> m >> k;
	adj.resize(n+1);
	vector<bool>visited(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int x = 0, y = 0;
			dfs(i, visited, x, y);
			components++;
			x = x / 2;
			extraPipes += x - (y - 1);
		}
	}
		cout << max(0, components - 1 - min(k, extraPipes)) << endl;
}