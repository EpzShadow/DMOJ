#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	long long ans = 0;
	cin >> n;
	vector<int> arr(n,0);
	vector<vector<int>>containers;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//containers[0][0] = arr[0];
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		bool in = 0;
		for (int j = 0; j < containers.size(); j++) {
			if (x < containers[j].back()) {
				in = 1;
				containers[j].push_back(x);
				break;
			}
		}
		if (!in) {
			containers.push_back(vector<int>(1,x));
		}
	}
	for (auto i : containers)
		ans += i[0];
	cout << ans << endl;
}