#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, nClubs, x;
	cin >> n;
	cin >> nClubs;
	vector<int> minStrokes(n+1, INT_MAX);
	vector<int>dist(nClubs);
	//base case for dp? lmao idfk
	minStrokes[0] = 0;
	//getting the golf club distances
	for (int i = 0; i < nClubs; i++) {
		cin >> x;
		dist[i] = x;
		minStrokes[x] = 1;
	}


	for (int i = 1; i <= n; i++) {
		if (minStrokes[i] != INT_MAX) {
			for (int j = 0; j < nClubs; j++) {
				if(i + dist[j] <= n)
				minStrokes[i + dist[j]] = min(minStrokes[i] + 1, minStrokes[i + dist[j]]);
			}
		}
	}
	if (minStrokes[n] == INT_MAX) {
		cout << "Roberta acknowledges defeat.";
	}
	else
		cout << "Roberta wins in " << minStrokes[n] << " strokes.";
}
