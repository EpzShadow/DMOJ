#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <future>
#include <thread>
using namespace std;
vector<int> todo[1000005];
int main() {

	int fact = 5;
	int factorial = fact;
	for (int i = fact-1; i > 1; i--) {
		factorial *= i;
	}
	cout << "facotrial of " << fact << " is " << factorial;
}