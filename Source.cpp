#include <bits/stdc++.h>
using namespace std;
int main() {
	string s, line;
	int sum = 0, i = 0, j = 0; 
	getline(cin, line);
	while (j < line.length()){
		j = line.find(' ', i); //find index of ' ' starting from pos i
		s = line.substr(i, j-i);//line.substr(start pos, length)
		if (j == -1) {
			j = line.length();
		}
		if (s != "(+") {
				s.erase(remove(s.begin(), s.end(), ')'), s.end());//removes all occurences of ')' from s
				sum += stoi(s);//converts string to int
		}
		i = j + 1;
	}
	cout << sum;
}