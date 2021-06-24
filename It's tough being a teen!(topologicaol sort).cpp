#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> ans;
	vector<int> visited(8);
	vector<int>incoming(8, 0);
	vector<vector<int>>adj(8);
	adj[1].push_back(7);
	incoming[7] ++;
	adj[1].push_back(4);
	incoming[4] ++;
	adj[2].push_back(1);
	incoming[1] ++;
	adj[3].push_back(4);
	incoming[4] ++;
	adj[3].push_back(5);
	incoming[5] ++;
	priority_queue<int, vector<int>, greater<int>> q;
	int a = -1, b = -1;
	while (a != 0 && b != 0) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		adj[a].push_back(b);
		incoming[b]++;
	}
	for (int i = 1; i <= 7; i++) {
		if (incoming[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int v = q.top();
		ans.push_back(v);
		q.pop();
		visited[v] = true;
		for (int i : adj[v]){
			if (!visited[i]) {
				incoming[i]--;
				if (incoming[i] == 0) {
					q.push(i);
				}
			}
		}
	}
	bool pass = true;
	for (int i = 1; i < 8; i++) {
		if (!visited[i])
			pass = false;
	}
	if (pass) {
		for (int i : ans)
			cout << i << ' ';
	}
	else
		cout << "Cannot complete these tasks. Going to bed." << endl;

}
