#include <bits/stdc++.h>
using namespace std;
int main() {
	int r, c, k, x, y;
	cin >> r;
	cin >> c;
	vector<vector<int>> matrix;
	matrix.resize(r+1, vector<int>(c+1, 0));
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		cin >> y;
		matrix[x][y] = -1;
	}
	for (int i = 1; i <= r; ++i) {
		if (matrix[i][1] == -1)
			break;
		else
			matrix[i][1] = 1;
	}
	for (int i = 1; i <= c; ++i) {
		if (matrix[1][i] == -1) {
			break;
		}
		else 
			matrix[1][i] = 1;	
	}
	for (int i = 2; i <= r; ++i) {
		for (int j = 2; j <= c; ++j) {
			if (matrix[i][j] == -1) {
				continue;			
			}
			if (matrix[i - 1][j] == -1)
				matrix[i - 1][j] = 0;
			if (matrix[i][j - 1] == -1)
				matrix[i][j - 1] = 0;
			matrix[i][j] = matrix[i - 1][j] + matrix [i][j-1];
		}
	}
	cout << matrix[r][c];

	return 0;
}