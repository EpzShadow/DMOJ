#include<bits/stdc++.h>
using namespace std;
string solve(int s, int d, vector<pair<string, int>>a) {
	bool matchFound = false;
	pair<string, int> ans = make_pair("", -1);
	for (auto i : a) {
		if (i.second >= s && i.second <= s + d) {
			if (!matchFound) {
				ans = i;
				matchFound = true;
			}
			else{
				if (i.second - s < ans.second - s)
					ans = i;
			}
		}
	}
	if (ans.second != -1)
		return ans.first;
	else
		return "No suitable teacher!";
}
int main() {
	int n;
	cin >> n;
	vector<pair<string, int>>a;
	while (n--) {
		string s;
		int b;
		cin >> s >> b;
		a.push_back(make_pair(s, b));
	}

	int q;
	cin >> q;
	while (q--) {
		int s, d;
		cin >> s >> d;
		cout << solve(s, d, a) << endl;
	
	}

}