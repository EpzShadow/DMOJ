#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int N, L;
	cin >> N >> L;
	cin.ignore();
	getline(cin, s);
	for (int i = 0; i < N; i++) {
		if (s[i] == ' ')
			continue;
		else {
			int x = ((s[i] + L - 97)%26 + 97);
			char a = x;
			s[i] = a;
		}
	}
	cout << s;
}