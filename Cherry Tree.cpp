#include <bits/stdc++.h>
using namespace std;
vector<int>cherryWeights;
vector<vector<pair<int, int>>>adjList;//go from index to i.first with weight i.second
vector<pair<int, int>>subTrees;
void dfs(int node, int parent, int edge) {
	subTrees[node].second += edge;
	subTrees[node].first += cherryWeights[node];
	for (auto to : adjList[node]) {
		if (to.first == parent)
			continue;
		dfs(to.first, node, to.second);
		subTrees[node].first += subTrees[to.first].first;
		subTrees[node].second += subTrees[to.first].second;
	}
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, c, k, ans = 0;
	cin >> n >> c >> k;
	cherryWeights.resize(n + 1);
	adjList.resize(n + 1);
	subTrees.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cherryWeights[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjList[a].push_back(make_pair(b, c));
		adjList[b].push_back(make_pair(a, c));
	}
	
	dfs(1, 1, 0);
	for (int i = 2; i <= n; i++) {
		if (subTrees[i].first >= c && subTrees[i].second <= k ) {
			ans++;
		}
	}
	cout << ans;
}