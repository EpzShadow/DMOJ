#include<bits/stdc++.h>
using namespace std;
vector<int> suffixMin(0, 1e9);
vector<int> suffixMax(0, -1e9);
static int n;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int q, l, e;
	cin >> n >> q;
	vector<int> arr(n,0);
	suffixMin.resize(n);
	suffixMax.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	suffixMax[n - 1] = arr[n - 1];
	suffixMin[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suffixMin[i] = min(arr[i], suffixMin[i+1]);
		suffixMax[i] = max(arr[i], suffixMax[i + 1]);
	}
	
	for (int i = 0; i < q; i++) {
		cin >> l >> e;
		int upperBound = l + e;
		int lowerBound = l - e;
		vector<int>::iterator low, high;
		low = lower_bound(suffixMin.begin(), suffixMin.end(), lowerBound);
		high = lower_bound(suffixMax.begin(), suffixMax.end(), upperBound, greater<int>());
		int d1 = distance(low, suffixMin.end());
		int d2 = distance(high, suffixMax.end());
		cout << min(d1, d2) <<  endl;

//-2 -2 -2 -2 0 0 0

	}
}