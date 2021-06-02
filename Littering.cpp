#include<bits/stdc++.h>
#include<set>
using namespace std;
void print(vector<int> arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

}
bool compare(int a, int b) {
	return (b < a);
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	vector<int>bruh(n, 0);
	for (int i = 0; i < n; i++)
		cin >> bruh[i];
	sort(bruh.begin(), bruh.end(), compare);

	for (int i = 0; i < k; i++) {
		ans += bruh[i];
	}

	cout << ans;

}