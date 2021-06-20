#include<bits/stdc++.h>
using namespace std;
int n;

vector<vector<int>> rotate(vector<vector<int>>&arr) {
	vector<vector<int>>rotatedArr(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			rotatedArr[i][j] = arr[j][n - i + 1];
		}
	}
	return rotatedArr;
}
bool check(vector<vector<int>>arr) {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j < n; j++) 
			if (arr[i][j] > arr[i][j + 1]) 
				return false;
			
	for (int j = 1; j <= n; j++) 
		for (int i = 1; i < n; i++) 
			if (arr[i][j] > arr[i + 1][j])
				return false;
		
	return true;

}
void print(vector<vector<int>>arr) {
	for (int i = 1; i <= n; i++) {
		cout << endl;
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << ' ';
	}
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	vector<vector<int>>arr(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	while(!check(arr))
		arr = rotate(arr);

	print(arr);
}