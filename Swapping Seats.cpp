#include<bits/stdc++.h>
using namespace std;
string s;
void countSection(int start, int end, vector<int>&section) {
	for (int i = start; i < end; i++) {
		switch (s[i]) {
		case 'A':
			section[0]++;
			break;
		case 'B':
			section[1]++;
			break;
		case 'C':
			section[2]++;
			break;
		}
	}
}
int main() {
	cin >> s;
	int size = s.size();
	int a_count = 0, b_count = 0, c_count = 0, ans = INT_MAX;
	vector<int>a_section(3, 0);//[0] = number of A's; [1] = number of B's; [2] = number of C's in each section
	vector<int>b_section(3, 0);
	vector<int>c_section(3, 0);
	
	for (auto i : s) {//this is to get the amount of each letters in the entire string
		switch (i) {
		case 'A':
			a_count++;
			break;
		case 'B':
			b_count++;
			break;
		case 'C':
			c_count++;
			break;
		}
	}

	countSection(0, a_count, a_section);//all of this is to count the amount in each section curr
	countSection(a_count, a_count + b_count, b_section);
	countSection(a_count + b_count, size, c_section);
	//this is for permuation ABC
	for (int i = 0; i < size; i++) {
		ans = min(ans, a_section[1] + a_section[2] + b_section[0] + b_section[2] - min(a_section[1], b_section[0]));
		char removeFromA = s[i % size];
		char removeFromB = s[(i + a_count) % size];
		char removeFromC = s[(i + a_count + b_count) % size];

		a_section[removeFromA - 'A']--;
		a_section[removeFromB - 'A']++;

		b_section[removeFromB - 'A']--;
		b_section[removeFromC - 'A']++;

		c_section[removeFromC - 'A']--;
		c_section[removeFromA - 'A']++;
	}

	//this is for permuation ACB
	fill(a_section.begin(), a_section.end(), 0);
	fill(b_section.begin(), b_section.end(), 0);
	fill(c_section.begin(), c_section.end(), 0);

	countSection(0, a_count, a_section);
	countSection(a_count, a_count + c_count, c_section);
	countSection(a_count + b_count, size, b_section);


	for (int i = 0; i < size; i++) {
		ans = min(ans, a_section[1] + a_section[2] + c_section[0] + c_section[1] - min(a_section[2], c_section[0]));
		char removeFromA = s[i % size];
		char removeFromC = s[(i + a_count) % size];
		char removeFromB = s[(i + a_count + c_count) % size];

		a_section[removeFromA - 'A']--;
		a_section[removeFromC - 'A']++;

		c_section[removeFromC - 'A']--;
		c_section[removeFromB - 'A']++;

		b_section[removeFromB - 'A']--;
		b_section[removeFromA - 'A']++;
	}

	cout << ans;



}
