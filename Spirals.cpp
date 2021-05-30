#include<bits/stdc++.h>
using namespace std;
//direction 0 1 2 3 down right up left

int main() {
	int x, y, dir = 1;
	int r = 50; int c = 50;
	vector<vector<int>>graph(100, vector<int>(100, 0));
	cin >> x >> y;
	graph[50][50] = x;
	
	int maxRC[4] = { 50,50,50,50 };//highest row, column, lowest row, column

	for (int i = 0; i <= y - x; i++) {
		graph[r][c] = i + x;
		switch (dir) {
		case(1):
			r = r + 1;
			if (r > maxRC[0]) {
				maxRC[0] = r;
				dir = 2;
			}
			break;
		case(2):
			c = c + 1;
			if (c > maxRC[1]) {
				maxRC[1] = c;
				dir = 3;
			}
			break;
		case(3):
			r = r - 1;
			if (r < maxRC[2]) {
				maxRC[2] = r;
				dir = 4;
			}
			break;

		case(4):
			c = c - 1;
			if (c < maxRC[3]) {
				maxRC[3] = c;
				dir = 1;
			}
			break;

		}
	}
	
	for (int i = maxRC[2]; i <= maxRC[0]; i++) {
		for (int j = maxRC[3]; j <= maxRC[1]; j++) {
			if (graph[i][j] == 0) 
				cout << " ";
			else
				cout << graph[i][j] << " ";
			}
		cout << endl;
		}
}
