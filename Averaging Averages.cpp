#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& arr) {
	for (auto& i : arr) 
		cout << i << ' ';
	cout << endl;

}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int>averages(n + 1, 0);
	vector<long long>sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> averages[i];
		sum[i] = sum[i - 1] + averages[i];
	}
	//print(averages);
	long long l, r, sumLR;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		sumLR = sum[r] - sum[l-1];
		sumLR = sumLR / (r - l + 1);
		cout << sumLR << endl;
	}
}