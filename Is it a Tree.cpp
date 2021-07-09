#include<bits/stdc++.h>
using namespace std;
bool visited[4];
int arr[4][4];
bool dfs(int v, int parent) {
	visited[v] = true;
	for (int i = 0; i < 4; i++) {
		if (!visited[i] && arr[v][i]) {
			if(!dfs(i, v))
				return false;
		}
		else if (arr[v][i])
			if (i != parent)
				return false;
	}
	return true;
}
int main() {
	int startNode = -1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				startNode = j;
		}
	bool x = dfs(startNode, -1);
	bool y = true;
	for(int i = 0; i < 4; i ++)
		if (!visited[i]) {
			y = false;
			break;
		}
	if (x && y)
		cout << "Yes";
	else
		cout << "No";
}