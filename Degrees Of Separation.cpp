#include<bits/stdc++.h>
using namespace std;
void initialize();
int friendsOfFriends(int x);
void dfs(int x, vector<int>dist, vector<bool>visited);
vector<vector<int>>adj;
int main() {
	initialize();
	adj.resize(51);
	char c = ' ';
	while (c != 'q') {
		cin >> c;
		int x, y;

		if (c == 'i') {
			cin >> x >> y;
			if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end()) {
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		}

		else if (c == 'd') {
			cin >> x >> y;
			adj[x].erase(find(adj[x].begin(), adj[x].end(), y));
			adj[y].erase(find(adj[y].begin(), adj[y].end(), x));
		}
		else if (c == 'n') {
			cin >> x;
			cout << adj[x].size() << endl;
		}
		else if (c == 'f') {
			cin >> x;
			cout << friendsOfFriends(x) << endl;
		}
		else if (c == 's') {
			cin >> x >> y;
			vector<int>dist(51, 1e9);
			dist[x] = 0;
			vector<bool>visited(51, false);
			dfs(x, dist, visited);
			cout << dist[y] << endl;
		}

	}
	

}
void initialize() {
	adj = { {}, { 6 }, { 6 }, { 4,5,6,15 }, { 3,5,6 }, 
		{ 3,4,6 }, { 1,2,3,4,5,7 }, { 6,8 }, { 7,9 }, 
		{ 8,10,12 }, { 9,11 }, { 10,12 }, { 9,11,13 }, 
		{ 12,14,15 }, { 13 }, { 3,13 }, { 17,18 }, { 16,18 },
		{ 16,17 }};
}	
void dfs(int x, vector<int>dist, vector<bool>visited) {
	visited[x] = true;
	for (auto i : adj[x]) {
		if(!visited[i])
			dfs(i, dist, visited);
		dist[i] = min(dist[i], dist[x] + 1);
	}
	return;
}
int friendsOfFriends(int x) {
	vector<int>ans;
	vector<bool>visited(51, false);
	queue<int>q;
	visited[x] = true;
	for (auto i : adj[x]) {
		q.push(i);
		visited[i] = true;
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		visited[v] = true;
		for (auto i : adj[v]) {
			if (!visited[i]) {
				visited[i] = true;
				ans.push_back(i);
			}
		}
	}
	return ans.size();
}
