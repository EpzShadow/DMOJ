#include<bits/stdc++.h>
using namespace std;
int main() {
	string t, s;
	cin >> t >> s;
	int size = s.size();
	for (int i = 0; i < s.size(); i++) {
		string temp = "";
		for (int j = i, x = 0; x < s.size(); x++, j++) {
			temp.push_back(s[j % (size)]);
		}
		if (t.find(temp) != string::npos) {
			cout << "yes";
			return 0;
		}
	}
	cout << "no";
	return 0;
}