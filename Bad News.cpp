#include<bits/stdc++.h>
using namespace std;
char arr[27][27];
int n, q;
string s;
bool dfs(int i, int j, int idx, vector<vector<bool>> vis) {
	bool pass = false;
	vis[i][j] = true;
	if (idx == s.size() - 1 && arr[i][j] == s[idx])
		return true;
	idx++;
	int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };//diff in x values
	int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0 };//diff in y values
	for (int k = 0; k < 8; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == s[idx] && !vis[x][y])
			pass = max(pass, dfs(x, y, idx, vis));
	}
	return pass;

}
void solve() {
	vector<vector<bool>>vis(27, vector<bool>(27, 0));
	bool pass = false;

	cin >> s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == s[0])
				pass = max(pass, dfs(i, j, 0, vis));
	if (pass)
		cout << "good puzzle!" << endl;
	else
		cout << "bad puzzle!" << endl;
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	while (q--)
		solve();
}