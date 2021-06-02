#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
void print(vector<vector<int>>& arr) {
	for (auto& i : arr) {
		for (auto& j : i)
			cout << j << ' ';
		cout << endl;
	}

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n;
	vector<vector<int>>arr(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)//getting array
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	cin >> q;
	int r1, c1, r2, c2, x;
	for (int t = 0; t < q; t++) { //doing the operations
		cin >> r1 >> c1 >> r2 >> c2 >> x;
		if (x % 360 == 0)
			continue;
		x = (x + 360) % 360;
		for (int v = 0; v < x; v += 90) {
			int d = r2 - r1;
			for (int i = 0; i <= d; i++) {
				for (int j = i; j <= d; j++) {
					swap(arr[i + r1 - 1][j + c1 - 1], arr[j + r1 - 1][i + c1 - 1]);
				}
			}
			int j = c2 - 1;
			for (int i = c1 - 1; i < c2; i++) {
				if (j > i) {
					for (int k = r1 - 1; k < r2; k++) {
						swap(arr[k][i], arr[k][j]);
					}
				}
				j--;
			}
		}
	}
	print(arr);
}

