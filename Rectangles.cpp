#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
static vector<pair<int, int>>points;
static set<pair<int, int>> setPoints;

bool solve(pair<int, int> i, pair<int, int> j) {

	pair<int, int> corner1 = make_pair(i.first, j.second);
	pair<int, int> corner2 = make_pair(j.first, i.second);
	
	bool a = setPoints.find(corner1) != setPoints.end();
	bool b = setPoints.find(corner2) != setPoints.end();

	if (a && b)
		return true;
	else
		return false;
}
int main() {
	int N, ans = 0;
	cin >> N;
	points.resize(N, make_pair(0, 0));
	for (int i = 0; i < N; ++i) {
		cin >> points[i].first >> points[i].second;
		setPoints.insert(points[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (solve(points[i], points[j])) {
				int length = abs(points[i].first - points[j].first);
				int width = abs(points[i].second - points[j].second);
				int area = abs(length * width);
				ans = max(ans, area);
			}
		}
	}
	cout << ans;
}