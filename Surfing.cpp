#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool bfs(string, string);

static unordered_map<string, vector<string>> adj;
int main() {
	int n;
	string line, from, to;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> from;
		vector<string> toArray;
		while (true) {
			cin >> line;
			if (line.find("HREF=\"") != string::npos) {
				int j = line.find("HREF=\"") + 6;
				int j1 = line.find("\">");
				to = line.substr(j, j1 - j);
				cout << "Link from " << from << " to " << to << endl;
				toArray.push_back(to);

			}
			if (line == "</HTML>") {
				adj.insert(make_pair(from, toArray));
				break;
			}
		}
	}
	string line1, line2;
	while (line1 != "The") {
		cin >> line1;
		if (line1 == "The")
			break;
		cin >> line2;
		if (bfs(line1, line2)) {
			cout << "Can surf from " << line1 << " to " << line2 << "." << endl;
		}
		else
			cout << "Can't surf from " << line1 << " to " << line2 << "." << endl;
	}
	return 0;
}

bool bfs(string from, string to) {
	unordered_map<string, bool> marked;
	queue<string> queue;
	queue.push(from);
	while (queue.size() > 0) {
		string s = queue.front();
		queue.pop();
		if (s == to)
			return true;
		for (int i = 0; i < adj[s].size(); i++) {
			if (marked[adj[s][i]] == false) {
				queue.push(adj[s][i]);
				marked[adj[s][i]] = true;
			}
		}
	}
	return false;
}