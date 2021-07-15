#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	deque<int>stack;
	vector<int>answers(n + 2);
	vector<int>bales(n + 2);
	vector<int>jumps(n + 2);
	for (int i = 0; i < n; i++)
		cin >> bales[i];
	for (int i = 0; i < n; i++)
		cin >> jumps[i];
	for (int i = n - 1; i >= 0; i--) {
		while (!stack.empty() && stack.front() <= bales[i]) 
			stack.pop_front();
		
		if (stack.size() < jumps[i])
			answers[i] = -1;
		else
			answers[i] = stack[jumps[i] - 1];
		stack.push_front(bales[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << answers[i] << ' ';
	}
	cout << endl;
}