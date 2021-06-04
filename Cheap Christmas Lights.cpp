#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	bool bruh = false;
	int m, n, sum = 0, numLightsOn = 0;
	cin >> n >> m;
	vector<int>lights(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> lights[i];
		if (lights[i] == 1) {
			numLightsOn++;
			sum += lights[i];
		}
	}
	int t = max(m, n);
	if (sum > 0) {
		for (int i = 1; i <= t; i++) {
			if (i <= m) {
				int b;
				cin >> b;
				if (lights[b] == 1)
					numLightsOn--;
				else//lights[b] == 0
					numLightsOn++;
				lights[b] = (lights[b] + 1) % 2;
			}
			if (numLightsOn <= i) {
				cout << i << endl;
				break;
				bruh = true;
				
			}
		}
	}
	else
		cout << 0 << endl;
}